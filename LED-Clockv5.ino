#define BRIGHTNESS 50         // стандартная яркость (0-255)
#define D_TEXT_SPEED 50      // скорость бегущего текста по умолчанию (мс)

#define CURRENT_LIMIT 2500    // лимит по току в миллиамперах, автоматически управляет яркостью (пожалей свой блок питания!) 0 - выключить лимит

#define WIDTH 32              // ширина матрицы
#define HEIGHT 8              // высота матрицы
#define SEGMENTS 1            // диодов в одном "пикселе" (для создания матрицы из кусков ленты)

#define COLOR_ORDER GRB       // порядок цветов на ленте. Если цвет отображается некорректно - меняйте. Начать можно с RGB

#define MATRIX_TYPE 0         // тип матрицы: 0 - зигзаг, 1 - параллельная
#define CONNECTION_ANGLE 3    // угол подключения: 0 - левый нижний, 1 - левый верхний, 2 - правый верхний, 3 - правый нижний
#define STRIP_DIRECTION 1     // направление ленты из угла: 0 - вправо, 1 - вверх, 2 - влево, 3 - вниз

#include <SPI.h>
#include <Wire.h>
#include <radio.h>
#include <RDA5807M.h>
#include <DHT.h>
#include <DHT_U.h>
#include <EEPROM.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ArduinoOTA.h>
#include <WiFiUdp.h>
#include <FastLED.h>
#include "fonts.h"

#define DHTPIN 4
#define DS3231_SCL 0  
#define DS3231_SDA 2  
#define LED_PIN 8
const uint16_t kRecvPin = 13;

const int pinPhoto = A0;
int raw = 0;

#define DHTTYPE    DHT11
DHT dht(DHTPIN, DHTTYPE);
IRrecv irrecv(kRecvPin);
decode_results results;
IPAddress timeServerIP;

ESP8266WebServer server(80);

const char* ntpServerName = "time.nist.gov";
//const char* ntpServerName = "time.windows.com";
const int NTP_PACKET_SIZE = 48;

//char ssid[] = "B.E.N.D.E.R.";  //  your network SSID (name)
//char pass[] = "25112003";
//char ssid[] = "SE-Den Wi-Fi NetWork";  //  your network SSID (name)
//char pass[] = "4815162342";//// your network password

char incomingPacket[255], ReplyBuffer[255];
int map_source = 50;
int volume = 1;
int clockAddress = 0x68;  // I2C адрес микросхемы

byte second, minute, hour, dayOfWeek, day, dayOfMonth, month, year;
byte RadioStation = 1;
byte packetBuffer[ NTP_PACKET_SIZE];



const int NUM_LEDS = WIDTH * HEIGHT * SEGMENTS;
CRGB leds[NUM_LEDS];
CRGB ColorRunningText;

uint32_t scrollTimer;
String Temperature, runningText, Pressure, header;
const char* web_login;
const char* web_password;
boolean loadingFlag, fullTextFlag, Show_Sensor, RadioStatus, TimerStatus, TimeShowStatus, volumetimerb;
int h1, m1, photoR, t_hour, t_minute;
boolean rt, wifi_connection;
unsigned long timeglobal, timer_time, timercd, timetmp, volumetimer, TimerUDP, TimerClock, wifi_timer;
uint64_t IRPrev;

String TemperatureHome, TemperatureOutdoors, HumidityHome;

WiFiUDP UdpSensor;
WiFiUDP UdpCommand;
WiFiUDP NtpUdp;
IPAddress apIP(192, 168, 0, 5);

RDA5807M radio;

void setup() {
  Serial.begin(115200);
  EEPROM.begin(1);
  FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  GetBrightness();
  if (CURRENT_LIMIT > 0) FastLED.setMaxPowerInVoltsAndMilliamps(5, CURRENT_LIMIT);
  FastLED.clear();
  FastLED.show();
  RadioStatus = false;
  Show_Sensor = true;
  //CheckLEDDisplay();
  Wire.begin(DS3231_SCL, DS3231_SDA);
  WIFIConnect("B.E.N.D.E.R.", "25112003", 1, "", "", 3, 0);
  NtpUdp.begin(2390);
  UdpSensor.begin(3555);
  UdpCommand.begin(3565);
  dht.begin();
  pinMode(pinPhoto, INPUT);
  irrecv.enableIRIn(); // Start the receiver
  Temperature = "0";
  Pressure = "0";
  TimerStatus = false;
  TimeShowStatus = true;
  radio.init();
  radio.setBandFrequency(RADIO_BAND_FM, 9900);
  radio.setMute(true);
  volumetimerb = false;
  server.begin();
  WEBServer();
  ArduinoOTA.setHostname("LEDClock"); // Задаем имя сетевого порта
  ArduinoOTA.setPassword((const char *)"0816"); // Задаем пароль доступа для удаленной прошивки
}

void GetBrightness()  {
  int val;
  raw = analogRead( pinPhoto );
  val = map(raw, 0, 1024, 2, 100);
  //Serial.println(String(val));
  FastLED.setBrightness(val);
}
void CheckLEDDisplay()  {
  fillAll(0xff0000);
  delay(2000);
  fillAll(0x00ff00);
  delay(2000);
  fillAll(0x0000ff);
  delay(2000);
}

void loop() {
  ArduinoOTA.handle();
  server.handleClient();
  if (wifi_timer <= millis()) {
    if (wifi_connection == false)   {
      wifi_timer = millis() + 500;
    }
    else  {
      wifi_timer = millis() + 60000;
    }
    WIFI_CHECK();
  }
  if (TimerUDP <= millis()) {
    TimerUDP = millis() + 300;
    int packetSize = UdpCommand.parsePacket();
    if (packetSize)
    {
      int len = UdpCommand.read(incomingPacket, UDP_TX_PACKET_MAX_SIZE);
      if (len > 0)
      {
        incomingPacket[len] = 0;
      }
      Serial.println(incomingPacket);
      IR_TCP(0, String(incomingPacket));
    }
    packetSize = UdpSensor.parsePacket();
    if (packetSize)
    {
      int len = UdpSensor.read(incomingPacket, UDP_TX_PACKET_MAX_SIZE);
      if (len > 0)
      {
        incomingPacket[len] = 0;
      }
      Serial.println(incomingPacket);
      Serial.println(String(incomingPacket).substring(4, 5));
      IR_TCP(0, String(incomingPacket));
    }
  }
  if (irrecv.decode(&results)) {
    serialPrintUint64(results.value);
    irrecv.resume();
    if (results.value == 18446744073709551615)  {
      IR_TCP(IRPrev, "");
    }
    else  {
      if (results.value == 534743 || results.value == 542903) {
        IRPrev = results.value;
        IR_TCP(results.value, "");
      }
      else  {
        IRPrev = 0;
        IR_TCP(results.value, "");
      }
    }
  }
  if (TimerClock <= millis()) {
    TimerClock = millis() + 1000;
    get_time();
    //if (hour == 1 && minute == 0 && second >= 40) SynchTime();
    if (h1 != hour || m1 != minute)  {
      GetBrightness();
      ShowTime();
      if (TimerStatus == true)  {
        if (timer_time <= millis()) {
          TimerStatus = false;
          timer_time = 0;
          IR_TCP(524543, "");
        }
      }
    }
  }
  if (rt == true) fillString(runningText, ColorRunningText);
  if (volumetimerb == true)  {
    if (volumetimer <= millis()) {
      Show_Sensor = false;
      ShowTime();
      volumetimerb = false;
    }
  }
}
