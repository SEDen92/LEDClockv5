void IR_TCP(uint64_t value, String data)  {
  if (String("Ts") == data.substring(0, 2)) {
    Temperature = data.substring(3);
  }
  if (String("Pr") == data.substring(0, 2)) {
    Pressure = data.substring(3);
  }  
  if (value == 558203 || data == "show_sensor") {
    ShowSensor();
    drawClock(hour, minute, true, 1, 0, 0x00ff00, 0x00ff00);
  }
  if (value == 569933 || data == "synch_time") {
    int i;
    for (i = 1; i <= 25; i++) // задаем начальное значение 1, конечное 1000 и задаем шаг цикла - 1.
    {
      if (SynchTime() == true) {
        drawText("Синхронизация времени --- успешно", 0, 0, 0x00ff00);
        break;
      }
      else  {
        drawText("Синхронизация времени --- ошибка", 0, 0, 0xff0000);
      }
      delay(1000);
    }
  }
  if (value == 524543 || data == "radio") {
    if (RadioStatus == false) {
      RadioOn();
    }
    else  {
      RadioOff();
    }
  }
  if (value == 551063 || data == "timer_off") {
    if (TimerStatus == true) {
      TimerStatus = false;
      timercd = 0;
      timer_time = 0;
      drawText("Таймер отключен", 0, 0, 0xff0000);
      Show_Sensor = false;
    }
  }
  if (value == 563303 || data == "timer_add") {
    if (TimerStatus == false)  {
      TimerAdd();
    }
    else  {
      timercd = timer_time - millis();
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      timercd = 0;
      Show_Sensor = false;
      ShowTime();
    }
    //Show_Sensor = false;
    //delay(1000);
    //ShowTime();
  }
  if (value == 575543 || data == "timer_on") {
    if (timercd > 0) {
      if (TimerStatus == false)  {
        Timer();
        RadioOff();
        Show_Sensor = false;
        ShowTime();
      }
    }
  }
  if (value == 534743 || data == "volume_up") {
    if (RadioStatus == true)  {
      if (radio.getMute() == true)  {
        radio.setMute(false);
        volume = 0;
      }
      if (volume++ <= 100)  {
        if (volume > 100) volume = 100;
        radio.setVolume(map(volume, 0, 100, 0.1, 15));
      }
      ShowVolume(volume);
      volumetimer = millis() + 1000;
      volumetimerb = true;
      //delay(500);
      //Show_Sensor = false;
      //ShowTime();
    }
  }
  if (value == 542903 || data == "volume_down") {
    if (RadioStatus == true)  {
      if (volume-- >= 0)  {
        if (volume <= 0) volume = 1;
        radio.setVolume(map(volume, 0, 100, 0.1, 15));
      }
      ShowVolume(volume);
      volumetimer = millis() + 1000;
      volumetimerb = true;
      //delay(500);
      //Show_Sensor = false;
      //ShowTime();
    }
  }
  if (value == 530663) {
    if (RadioStatus == true)  {
      if (radio.getMute() == false) {
        drawText(" MUTE", 0, 0, 0xffff00);
        Show_Sensor = false;
        radio.setMute(true);
        delay(2000);
        ShowTime();
      }
      else  {
        Show_Sensor = false;
        radio.setMute(false);
        ShowVolume(volume);
        delay(2000);
        ShowTime();
      }
    }
  }
  if (value == 559223 || data == "radio_station_up") {
    if (RadioStatus == true)  {
      if (RadioStation++ >= 7) {
        RadioStation = 7;
      }
      else  {
        WriteEEPROM(RadioStation);
        ChangeRadioStation();
        ShowTime();
      }
    }
  }
  if (value == 567383 || data == "radio_station_down") {
    if (RadioStatus == true)  {
      if (RadioStation == 0)  {
        RadioStation = 0;
      }
      else  {
        RadioStation--;
        WriteEEPROM(RadioStation);
        ChangeRadioStation();
      }
    }
  }
}

void WriteEEPROM(int value) {
  EEPROM.write(1, value);
  EEPROM.commit();
}
