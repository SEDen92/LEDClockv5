const CRGB Colors[] = {
  0xff0000,
  0xff0000,
  0xff0000,
  0xff1100,
  0xff2200,
  0xff3300,
  0xff4400,
  0xff5500,
  0xff6600,
  0xff7700,
  0xff8800,
  0xff9900,
  0xffaa00,
  0xffbb00,
  0xffcc00,
  0xffdd00,
  0xffee00,
  0xffff00,
  0xeeff00,
  0xddff00,
  0xccff00,
  0xbbff00,
  0xaaff00,
  0x99ff00,
  0x88ff00,
  0x77ff00,
  0x66ff00,
  0x55ff00,
  0x44ff00,
  0x33ff00,
  0x22ff00,
  0x11ff00,
  0x00ff00,
  0x00ff11,
  0x00ff22,
  0x00ff33,
  0x00ff44,
  0x00ff55,
  0x00ff66,
  0x00ff77,
  0x00ff88,
  0x00ff99,
  0x00ffaa,
  0x00ffbb,
  0x00ffcc,
  0x00ffdd,
  0x00ffee,
  0x00ffff,
  0x00eeff,
  0x00ddff,
  0x00ccff,
  0x00bbff,
  0x00aaff,
  0x0099ff,
  0x0088ff,
  0x0077ff,
  0x0066ff,
  0x0055ff,
  0x0044ff,
  0x0033ff,
  0x0022ff,
  0x0011ff,
  0x0000ff,
  0x0000ff,
  0x0000ff,
  0x0000ff,
  0x0000ff,
  0x0000ff,
  0x0000ff,
  0x0000ff,
  0x0000ff,
  0x0000ff,
  0x0000ff,
  0x1100ff,
  0x2200ff,
  0x3300ff,
  0x4400ff,
  0x5500ff,
  0x6600ff,
  0x7700ff,
  0x8800ff,
  0x9900ff,
  0xaa00ff,
  0xbb00ff,
  0xcc00ff,
  0xdd00ff,
  0xee00ff,
  0xff00ff,
  0xff00ff,
  0xff00ff
};

void ShowSensor()  {
  /*Serial.println("Function ShowSensor()");
  String strtemp = String(dht.readTemperature());
  TemperatureHome = "+" + strtemp.substring(0, strtemp.length() - 1);
  drawText(TemperatureHome, 0, 0, 0xff0000);
  Serial.println("Show Temperature in Home =" + TemperatureHome);
  strtemp = "Th=" + TemperatureHome;
  UdpSensor.beginPacket("192.168.0.255", 3555);
  strcpy(ReplyBuffer, strtemp.c_str());
  UdpSensor.write(ReplyBuffer);
  UdpSensor.endPacket();
  delay(2000);  
  HumidityHome = String( round( dht.readHumidity()));
  HumidityHome = HumidityHome.substring(0, HumidityHome.length() - 3) + "%";
  drawText(HumidityHome, 7, 0, 0x0000ff);
  Serial.println("Show Humidity =" + HumidityHome);
  strtemp = "Hh=" + HumidityHome;
  UdpSensor.beginPacket("192.168.0.255", 3555);
  strcpy(ReplyBuffer, strtemp.c_str());
  UdpSensor.write(ReplyBuffer);
  UdpSensor.endPacket();
  delay(2000);
  if (Temperature.toInt() >= 0) {
    TemperatureOutdoors = "+" + Temperature;
    drawText(TemperatureOutdoors, 0, 0, Colors[map(Temperature.toFloat(), -40, +50, 80, 0)]);
  }
  else {
    TemperatureOutdoors = Temperature;
    drawText(TemperatureOutdoors, 0, 0, Colors[map(Temperature.toFloat(), -40, +50, 80, 0)]);
  }
  Serial.println("Show Temperature Outdoors =" + Temperature);
  delay(2000);
  drawText(Pressure, 0, 0, 0xff00ff);
  Serial.println("Show Pressure Outdoors =" + Temperature);
  delay(2000);*/
}
