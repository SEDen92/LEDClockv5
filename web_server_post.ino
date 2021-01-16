String WEBPage() {
  WEBCheck();
  String Page;
  Page += "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"\"http://www.w3.org/TR/html4/loose.dtd\">";
  Page += "<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>";
  Page += "<title>Управление умными часами</title>";
  Page += "<link rel=\"stylesheet\" href=\"style.css\"/>";
  Page += "<link rel=\"shortcut icon\" href=\"https://i.yapx.ru/GEF4w.png\" type=\"image/png\">";
  Page += "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css\">";
  Page += "</head>";
  Page += "<body background=\"http://i.yapx.ru/GFnf5.jpg\">";
  Page += "<h1 style=\"color:#000000\" align=\"center\">Данные с часов</h1>";
  Page += "<h2 align=\"center\">Данные датчиков в доме</h2>";
  Page += "<h2 style=\"color:#ff0000\" align=\"center\">Температура = " + TemperatureHome + "</h2>";
  Page += "<h2 style=\"color:#0000ff\" align=\"center\">Относительная влажность = " + HumidityHome + "</h2>";
  Page += "<h2 align=\"center\">Данные датчиков на улице</h2>";
  Page += "<h2 style=\"color:#0000ff\" align=\"center\">Температура = " + TemperatureOutdoors + "</h2>";
  Page += "<h2 style=\"color:#ff00ff\" align=\"center\">Атмосферное давление = " + Pressure + " мм. рт. столба" + "</h2>";
  Page += "<h2 align=\"center\">Время</h2>";
  Page += "<big><big><big><big><big><big><big><big><big><big><p align=\"center\">" + String(hour) + ":" + String(minute) + ":" + String(second) + "</p></big></big></big></big></big></big></big></big></big></big>";
  Page += "<h2 style=\"color:#0000ff\" align=\"center\"></h2>";
  Page += "<h1 style=\"color:#000000\" align=\"center\">Управление умными часами</h1>";
  Page += "<div class=\"container\"><h2>Данные датчиков</h2>";
  Page += "<div class=\"row\"><div class=\"col-md-2\"><a href=\"/show_sensor\" class=\"btn btn-block btn-lg btn-info\" role=\"button\">Показать</a></div></div>";
  Page += "<h2>Синхронизация времени</h2>";
  Page += "<div class=\"row\"><div class=\"col-md-2\"><a href=\"/synch\" class=\"btn btn-block btn-lg btn-info\" role=\"button\">Начать</a></div></div>";
  Page += "<h2>Настроить таймер</h2>";
  if (TimerStatus == true)  {
    Page += "<h2>Осталось времени " + String(t_hour) + ":" + String(t_minute) + "</h2>";
    Page += "<div class=\"row\"><div class=\"col-md-2\"><a href=\"/timer_off\" class=\"btn btn-block btn-lg btn-danger\" role=\"button\">Выкл. таймер</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_balance\" class=\"btn btn-block btn-lg btn-info\" role=\"button\">Остаток</a></div></div>";
  }
  else  {
    Page += "<div class=\"row\">";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_5\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">5 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_10\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">10 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_15\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">15 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_20\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">20 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_25\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">25 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_30\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">30 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_35\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">35 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_40\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">40 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_45\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">45 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_50\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">50 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_55\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">55 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_60\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">1 час</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_70\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">1 час 10 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_80\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">1 час 20 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_90\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">1 час 30 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_100\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">1 час 40 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_110\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">1 час 50 мин</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/timer_120\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">2 часа</a></div></div>";
  }
  Page += "<h2>Управление радио</h2><div class=\"row\">";
  if (RadioStatus == false)  {
    Page += "<div class=\"col-md-2\"><a href=\"/radio\" class=\"btn btn-block btn-lg btn-success\" role=\"button\">Включить</a></div>";
  }
  else  {
    Page += "<div class=\"col-md-2\"><a href=\"/radio\" class=\"btn btn-block btn-lg btn-danger\" role=\"button\">Выключить</a></div>";
    Page += "</div><h2>Громкость</h2><div class=\"row\">";
    if (radio.getMute() == true)  {
      Page += "<div class=\"col-md-2\"><a href=\"/mute\" class=\"btn btn-block btn-lg btn-success\" role=\"button\">Включить</a></div>";
    }
    else {
      Page += "<div class=\"col-md-2\"><a href=\"/mute\" class=\"btn btn-block btn-lg btn-danger\" role=\"button\">Выключить</a></div>";
    }
    Page += "</div><h2>Установить громкость</h2>";
    if (radio.getMute() == false)  {
      Page += "<h2>Текущая громкость " + String(volume) + "%" + "</h2>";
    }
    else  {
      Page += "<h2>Текущая громкость MUTE</h2>";
    }
    Page += "<div class=\"row\">";
    Page += "<div class=\"col-md-2\"><a href=\"/vol_1\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">1%</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/vol_20\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">20%</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/vol_40\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">40%</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/vol_60\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">60%</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/vol_80\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">80%</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/vol_100\" class=\"btn btn-block btn-lg btn-primary\" role=\"button\">100%</a></div>";
    Page += "</div><h2>Выбрать радиостанцию</h2>";
    Page += "<h2>Текущая радиостанция " + String(RadioStationName[RadioStation]) + "</h2>";
    Page += "<div class=\"row\">";
    Page += "<div class=\"col-md-2\"><a href=\"/radio_0\" class=\"btn btn-block btn-lg btn-warning\" role=\"button\">Авантаж</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/radio_1\" class=\"btn btn-block btn-lg btn-warning\" role=\"button\">Ретро FM</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/radio_2\" class=\"btn btn-block btn-lg btn-warning\" role=\"button\">Русское Радио</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/radio_3\" class=\"btn btn-block btn-lg btn-warning\" role=\"button\">Европа +</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/radio_4\" class=\"btn btn-block btn-lg btn-warning\" role=\"button\">Радио России</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/radio_5\" class=\"btn btn-block btn-lg btn-warning\" role=\"button\">Белый лебедь</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/radio_6\" class=\"btn btn-block btn-lg btn-warning\" role=\"button\">Радио День</a></div>";
    Page += "<div class=\"col-md-2\"><a href=\"/radio_7\" class=\"btn btn-block btn-lg btn-warning\" role=\"button\">Урюпинск FM</a></div></div>";
  }
  Page += "<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>";
  Page += "</div></div></body></html>";
  return Page;
}

void WEBCheck() {

}

void WEBPageNotFound() {
  String message = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"\"http://www.w3.org/TR/html4/loose.dtd\">";
  message += "<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/><title>404 not found!</title>";
  message += "<link rel = \"shortcut icon\" href = \"https://i.yapx.ru/GEF4w.png\" type = \"image/png\"><style>";
  message += "body { background - color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }";
  message += "</style></head><body><br><br><br><br><br><br><br><br>";
  message += "<h1 style=\"color: #000000\" align=\"center\">404 not found!</h1>";
  message += "<h2 align=\"center\">Страница не найдена</h2><br><br><br><br><br><br><br><br></body></html>";
  server.send(404, "text/html", message);
}

void WEBServer()  {
  web_login = "user";
  web_password = "esp8266";
  server.on("/", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    server.send(200, "text/html", WEBPage());
  });
  server.on(" / show_sensor", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    IR_TCP(558203, "");
    server.send(200, "text / html", WEBPage());
    //delay(1000);
  });
  server.on(" / timer_off", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    IR_TCP(551063, "");
    server.send(200, "text / html", WEBPage());
    //delay(1000);
  });
  server.on(" / synch", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    server.send(200, "text / html", WEBPage());
    IR_TCP(569933, "");
    //delay(1000);
  });
  server.on(" / mute", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    IR_TCP(530663, "");
    server.send(200, "text / html", WEBPage());
    //delay(1000);
  });
  server.on(" / timer_balance", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == true)  {
      IR_TCP(563303, "");
    }
    server.send(200, "text / html", WEBPage());
    //delay(1000);
  });
  server.on(" / show_sensor", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    IR_TCP(558203, "");
    server.send(200, "text / html", WEBPage());
    //delay(1000);
  });

  server.on(" / radio", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    IR_TCP(524543, "");
    server.send(200, "text / html", WEBPage());
    //delay(1000);
  });
  server.on(" / timer_5", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 300000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_10", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 600000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_15", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 900000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_20", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 1200000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_25", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 1500000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_30", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 1800000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_35", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 2100000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_40", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 2400000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_45", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 2700000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_50", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 3000000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_55", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 3300000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_60", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 3600000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_70", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 4200000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_80", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 4800000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_90", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 5400000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_100", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 6000000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_110", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 6600000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Serial.println("Start timer " + String(timercd) + " mills");
      Timer();
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / timer_120", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    if (TimerStatus == false)  {
      timercd = 7200000;
      TimerShow();
      drawClock(t_hour, t_minute, true, 1, 0, 0xffff00, 0xffff00);
      delay(2000);
      Timer();
      Serial.println("Start timer " + String(timercd) + " mills");
      server.send(200, "text / html", WEBPage());
    }
  });
  server.on(" / vol_1", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    volume = 0;
    IR_TCP(534743, "");
    Serial.println("Set volume " + String(volume) + " % ");
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / vol_20", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    volume = 19;
    IR_TCP(534743, "");
    Serial.println("Set volume " + String(volume) + " % ");
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / vol_40", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    volume = 39;
    IR_TCP(534743, "");
    Serial.println("Set volume " + String(volume) + " % ");
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / vol_60", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    volume = 59;
    IR_TCP(534743, "");
    Serial.println("Set volume " + String(volume) + " % ");
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / vol_80", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    volume = 79;
    IR_TCP(534743, "");
    Serial.println("Set volume " + String(volume) + " % ");
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / vol_100", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    volume = 99;
    IR_TCP(534743, "");
    Serial.println("Set volume " + String(volume) + " % ");
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / radio_0", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    RadioStation = 0;
    Serial.println("Set radiostation " + String(RadioStationName[RadioStation]));
    ChangeRadioStation();
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / radio_1", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    RadioStation = 1;
    Serial.println("Set radiostation " + String(RadioStationName[RadioStation]));
    ChangeRadioStation();
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / radio_2", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    RadioStation = 2;
    Serial.println("Set radiostation " + String(RadioStationName[RadioStation]));
    ChangeRadioStation();
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / radio_3", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    RadioStation = 3;
    Serial.println("Set radiostation " + String(RadioStationName[RadioStation]));
    ChangeRadioStation();
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / radio_4", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    RadioStation = 4;
    Serial.println("Set radiostation " + String(RadioStationName[RadioStation]));
    ChangeRadioStation();
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / radio_5", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    RadioStation = 5;
    Serial.println("Set radiostation " + String(RadioStationName[RadioStation]));
    ChangeRadioStation();
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / radio_6", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    RadioStation = 6;
    Serial.println("Set radiostation " + String(RadioStationName[RadioStation]));
    ChangeRadioStation();
    server.send(200, "text / html", WEBPage());
  });
  server.on(" / radio_7", []() {
    if (!server.authenticate(web_login, web_password))
      return server.requestAuthentication();
    RadioStation = 7;
    Serial.println("Set radiostation " + String(RadioStationName[RadioStation]));
    ChangeRadioStation();
    server.send(200, "text / html", WEBPage());
  });
  server.begin();
  server.onNotFound(WEBPageNotFound);
  Serial.println("HTTP server started");
}
