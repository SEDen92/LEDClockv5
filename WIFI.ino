#include <ESP8266WiFi.h>

char* ssid_name_temp;
char* ssid_password_temp;

void WIFI_CREATE_AP(char ssid_ap_name[], char ssid_ap_password[], int channel_ap, int ssid_ap_hide) {
  WiFi.softAP(ssid_ap_name, ssid_ap_password, channel_ap, ssid_ap_hide);
  Serial.print('\n');
  Serial.print("---WIFI Access point name = ");
  Serial.print(ssid_ap_name);
  Serial.print('\n');
  Serial.print("---WIFI Access point password = ");
  Serial.print(ssid_ap_password);
  Serial.print('\n');
  Serial.print("---WIFI Access point channel = ");
  Serial.print(channel_ap);
  Serial.print('\n');
  Serial.print("---WIFI Hide access point = ");
  Serial.print(ssid_ap_hide);
  Serial.print('\n');
}

void WIFI_CREATE_STA(char ssid_name[], char ssid_password[]) {
  WiFi.disconnect();
  WiFi.begin(ssid_name, ssid_password);
  Serial.print('\n');
  Serial.print("---WIFI Access point name = ");
  Serial.print(ssid_name);
  Serial.print('\n');
  Serial.print("---WIFI Access point password = ");
  Serial.print(ssid_password);
  Serial.print('\n');
}

void WIFI_CHECK() {
  if (WiFi.status() != WL_CONNECTED)  {
    if (wifi_connection == true) {
      ArduinoOTA.end();
      WIFI_CREATE_STA(ssid_name_temp, ssid_password_temp);
    }
    Serial.println("---WIFI Attempt connect = fail");
    wifi_connection = false;
  }
  else  {
    if (wifi_connection == false) {
      Serial.print('\n');
      Serial.println("---WIFI Connected");
      Serial.print("---WIFI IP address: ");
      Serial.print(WiFi.localIP());
      Serial.print('\n');
      Serial.println("---WIFI MAC address: " + WiFi.macAddress());
      ArduinoOTA.begin();
    }
    wifi_connection = true;
    Serial.print('\n');
    Serial.print("---WIFI Signal power: ");
    Serial.print(WiFi.RSSI());
    Serial.print(" dBm");
  }
}

void WIFIConnect(char ssid_name[], char ssid_password[], int wifi_mode, char ssid_ap_name[], char ssid_ap_password[], int channel_ap, int ssid_ap_hide)  {
  ssid_name_temp = ssid_name;
  ssid_password_temp = ssid_password;
  Serial.print('\n');
  if (wifi_mode == 1)  {
    WiFi.mode(WIFI_STA);
    Serial.println("---WIFI Mode = STA (Client)");
    WIFI_CREATE_STA(ssid_name, ssid_password);
  }
  if (wifi_mode == 2)  {
    WiFi.mode(WIFI_AP);
    Serial.println("---WIFI Mode = AP (Access point)");
    WIFI_CREATE_AP(ssid_ap_name, ssid_ap_password, channel_ap, ssid_ap_hide);
  }
  if (wifi_mode == 3)  {
    WiFi.mode(WIFI_AP_STA);
    Serial.println("---WIFI Mode = AP+STA (Mixed)");
    WIFI_CREATE_AP(ssid_ap_name, ssid_ap_password, channel_ap, ssid_ap_hide);
    WIFI_CREATE_STA(ssid_name, ssid_password);
  }
}



/* Самодостаточный модуль для работы с Wi-Fi
    Описание применения метода WIFIConnect
    WIFIConnect(char ssid[], char password[], boolean wifi_mode, char ssidname[], char ssid_password[], int channel_ap, int ssid_hide)
    char ssid_name[] Имя точки доступа к которой нужно подключиться
    char ssid_password[] Пароль точки доступа к кеоторой необходимо подключиться
    int wifi_mode Режим работы ( 1 - STA режим клиента, 2 - AP режим точки доступа, 3 - AP+STA режим смешанный )
    char ssid_ap_name[] Имя создаваемой точки доступа
    char ssid_ap_password[] Пароль создаваемой точки доступа
    int channel_ap Канал для создаваемой точки доступа от 1 до 13
    int ssid_ap_hide Нужно ли скрыть создаваемую точку доступа ( 0 - нет, 1 - да)



    unsigned long wifi_timer;

    if (wifi_timer <= millis()) {                 Таймер опроса статуса соединения
      wifi_timer = millis() + 500;
      WIFI_CHECK();
    }
*/
