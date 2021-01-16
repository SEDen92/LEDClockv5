
const int RadioStationFreq[] = {
  10020,
  10060,
  10210,
  10260,
  10340,
  10450,
  10640,
  10780
};

const char* RadioStationName[] = {
  "Авантаж",
  "Ретро FM",
  "Русское Радио",
  "Европа +",
  "Радио России",
  "Белый лебедь",
  "Радио День",
  "Урюпинск FM"
};

void ShowVolume(int value) {
  if (value > 9) {
    drawText(" " + String(value) + "%" , 0, 0, 0xffff00);
  }
  if (value <= 9) {
    drawText("  " + String(value) + "%" , 0, 0, 0xffff00);
  }
  if (value > 99) {
    drawText(" " + String(value) + "%" , 0, 0, 0xffff00);
  }
  Show_Sensor = false;
}

void RadioOn()  {  
  Serial.println(String(String("Радио").length()));
  radio.setVolume(map(volume, 0, 100, 0.1, 15));
  radio.setBassBoost(true);
  drawText("Радио", 0, 0, 0x00ff00);
  delay(2000);
  ChangeRadioStation();
  radio.setMute(false);
  RadioStatus = true;
}

void RadioOff() {
  radio.setMute(true);
  drawText("Радио", 0, 0, 0xff0000);
  delay(2000);
  RadioStatus = false;
  Show_Sensor = false;
  ShowTime();
}

void ChangeRadioStation() {
  radio.setBandFrequency(RADIO_BAND_FM, RadioStationFreq[RadioStation]);
  drawText(RadioStationName[RadioStation], 0, 0, 0xffff00);
  Show_Sensor = false;
  ShowTime();
}
