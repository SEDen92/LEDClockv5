int SynchTime()
{
  Serial.println("Function SynchTime");
  boolean connect_ntp;
  WiFi.hostByName(ntpServerName, timeServerIP);
  sendNTPpacket(timeServerIP); // send an NTP packet to a time server
  int cb = NtpUdp.parsePacket();
  if (!cb) {
    Serial.println("SynchTime failed");
    return connect_ntp = false;
  }
  else {
    NtpUdp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer
    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    const unsigned long seventyYears = 2208988800UL;
    unsigned long epoch = secsSince1900 - seventyYears;
    hour = (epoch  % 86400L) / 3600;
    switch (hour) {
      case 20:
        hour = 0;
        break;
      case 21:
        hour = 1;
        break;
      case 22:
        hour = 2;
        break;
      case 23:
        hour = 3;
        break;
      default:
        hour = hour + 4;
    }
    minute = (epoch  % 3600) / 60;
    second = epoch % 60;
  }
  set_time();
  Serial.println("SynchTime done");
  return connect_ntp = true;
}

unsigned long sendNTPpacket(IPAddress & address)
{
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;
  NtpUdp.beginPacket(address, 123); //NTP requests are to port 123
  NtpUdp.write(packetBuffer, NTP_PACKET_SIZE);
  NtpUdp.endPacket();
}

void get_time() {
  Wire.beginTransmission(clockAddress);
  Wire.write(byte(0x00));
  Wire.endTransmission();
  Wire.requestFrom(clockAddress, 7);
  second     = bcdToDec(Wire.read() & 0x7f);
  minute     = bcdToDec(Wire.read());
  hour       = bcdToDec(Wire.read() & 0x3f);
}

void set_time()
{
  Serial.println("Function /set_time/");
  Wire.beginTransmission(clockAddress);
  Wire.write(byte(0x00));
  Wire.write(decToBcd(second + 2));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  //Wire.write(decToBcd(dayOfWeek));
  //Wire.write(decToBcd(22));
  //Wire.write(decToBcd(9));
  //Wire.write(decToBcd(19));
  Wire.endTransmission();
}

void ShowTime()  {
  if (timercd == 0) {
    Serial.println("Function ShowTime");
    get_time();
    timeglobal = millis() / 1000 / 60;
    if (timeglobal != timetmp)  {
      timetmp = timeglobal;
    }
    if (Show_Sensor == true)  {
      if (String("5") == String(minute).substring(1, 1) || String("0") == String(minute).substring(1, 1) || String("5") == String(minute).substring(2, 1) || String("0") == String(minute).substring(2, 1)) ShowSensor();
      Show_Sensor = true;
    }
    drawClock(hour, minute, true, 1, 0, 0x00ff00, 0x00ff00);
    if (hour == 0 & minute == 0 & millis()>= 70000) ESP.restart();
    Serial.println("Show time = " + String(hour) + ":" + String(minute) + ":" + String(second));
    m1 = minute;  h1 = hour;
  }
  Show_Sensor = true;
}

byte decToBcd(byte val) {
  return ( (val / 10 * 16) + (val % 10) );
}

byte bcdToDec(byte val) {
  return ( (val / 16 * 10) + (val % 16) );
}

String getTimeStr() {
  String str = String(day) + "." + formatDigit(month, 2) + "." +
               formatDigit(year, 2) + " " + formatDigit(hour, 2) + ":" +
               formatDigit(minute, 2) + ":" + formatDigit(second, 2);
  return str;
}

String formatDigit(int i, int len) {
  String s = String(i);
  while (s.length() < len) {
    s = "0" + s;
  }
  return (s);
}

void TimerShow()  {
  int t_tmp;
  if (timercd >= 3600000) {
    t_hour = timercd / 1000 / 60 / 60;
    t_minute = timercd / 1000 / 60;
    if (t_hour * 60 == t_minute)  {
      t_minute = 0;
    }
    else  {
      t_minute = t_minute - (t_hour * 60);
    }
  }
  else  {
    t_hour = 0;
    t_minute = timercd / 1000 / 60;
  }
  //delay(3000);
}

void TimerAdd() {
  timercd = timercd + 300000;
  TimerShow();
}

void Timer()  {
  timer_time = timercd + millis();
  timercd = 0;
  TimerStatus = true;
}
