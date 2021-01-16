// служебные функции

// функция отрисовки точки по координатам X Y
void drawPixelXY(int8_t x, int8_t y, CRGB color) {
  if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1) return;
  int thisPixel = getPixelNumber(x, y) * SEGMENTS;
  for (byte i = 0; i < SEGMENTS; i++) {
    leds[thisPixel + i] = color;
  }
}

void fillAll(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
  FastLED.show();
}

void drawSymbol_5x8(byte digit, byte X, byte Y, CRGB color) {
  for (byte x = 0; x < 5; x++) {
    byte thisByte = pgm_read_byte(&(fontHEX[digit][x]));
    //if (thisByte == 0x00) break;
    for (byte y = 0; y < 8; y++) {
      if (x + X > WIDTH || y + Y > HEIGHT) continue;
      if (thisByte & (1 << 7 - y)) drawPixelXY(x + X, y + Y, color);
    }
  }
}

void drawClock(byte hrs, byte mins, boolean dots, byte X, byte Y, uint32_t color1, uint32_t color2) {
  FastLED.clear();
  char arrayHour[String(hrs).length()];
  strcpy(arrayHour, String(hrs).c_str());
  if (String(hrs).length() == 2) {
    drawSymbol_5x8(byte(arrayHour[0]) - 32, X, Y, color1);
    drawSymbol_5x8(byte(arrayHour[1]) - 32, X + 7, Y, color1);
  }
  else  {
    drawSymbol_5x8(16, X, Y, color1);
    drawSymbol_5x8(byte(arrayHour[0]) - 32, X + 7, Y, color1);
  }
  if (dots) drawSymbol_5x8(26, X + 13, Y, color1);
  char arrayMinute[String(mins).length()];
  strcpy(arrayMinute, String(mins).c_str());
  if (String(mins).length() == 2) {
    drawSymbol_5x8(byte(arrayMinute[0]) - 32, X + 18, Y, color1);
    drawSymbol_5x8(byte(arrayMinute[1]) - 32, X + 25, Y, color1);
  }
  else  {
    drawSymbol_5x8(16, X + 18, Y, color1);
    drawSymbol_5x8(byte(arrayMinute[0]) - 32, X + 25, Y, color1);
  }
  FastLED.show();
}

void drawText(String Text, byte Xp, byte Yp, CRGB color)  {
  FastLED.clear();
  Serial.println("Function DrawText = " + Text);
  char arrayText[Text.length()];
  strcpy(arrayText, Text.c_str());
  int i, x;
  x = Xp;
  if (Text.length() <= 10)
  {
    for (i = 0; i <= Text.length() - 1; i++)
    {
      //drawSymbol_5x8(byte(arrayText[i]) - 32, x, Yp, color);
      if (byte(arrayText[i]) != 208)  {
        drawLetter(1, byte(arrayText[i]), x, color);
        x = x + 6;
      }
      FastLED.show();
    }
  }
  else
  {
    runningText = Text;
    ColorRunningText = color;
    rt = true;
  }
}

// **************** НАСТРОЙКА МАТРИЦЫ ****************
#if (CONNECTION_ANGLE == 0 && STRIP_DIRECTION == 0)
#define _WIDTH WIDTH
#define THIS_X x
#define THIS_Y y

#elif (CONNECTION_ANGLE == 0 && STRIP_DIRECTION == 1)
#define _WIDTH HEIGHT
#define THIS_X y
#define THIS_Y x

#elif (CONNECTION_ANGLE == 1 && STRIP_DIRECTION == 0)
#define _WIDTH WIDTH
#define THIS_X x
#define THIS_Y (HEIGHT - y - 1)

#elif (CONNECTION_ANGLE == 1 && STRIP_DIRECTION == 3)
#define _WIDTH HEIGHT
#define THIS_X (HEIGHT - y - 1)
#define THIS_Y x

#elif (CONNECTION_ANGLE == 2 && STRIP_DIRECTION == 2)
#define _WIDTH WIDTH
#define THIS_X (WIDTH - x - 1)
#define THIS_Y (HEIGHT - y - 1)

#elif (CONNECTION_ANGLE == 2 && STRIP_DIRECTION == 3)
#define _WIDTH HEIGHT
#define THIS_X (HEIGHT - y - 1)
#define THIS_Y (WIDTH - x - 1)

#elif (CONNECTION_ANGLE == 3 && STRIP_DIRECTION == 2)
#define _WIDTH WIDTH
#define THIS_X (WIDTH - x - 1)
#define THIS_Y y

#elif (CONNECTION_ANGLE == 3 && STRIP_DIRECTION == 1)
#define _WIDTH HEIGHT
#define THIS_X y
#define THIS_Y (WIDTH - x - 1)

#else
#define _WIDTH WIDTH
#define THIS_X x
#define THIS_Y y
#pragma message "Wrong matrix parameters! Set to default"

#endif

// получить номер пикселя в ленте по координатам
uint16_t getPixelNumber(int8_t x, int8_t y) {
  if ((THIS_Y % 2 == 0) || MATRIX_TYPE) {               // если чётная строка
    return (THIS_Y * _WIDTH + THIS_X);
  } else {                                              // если нечётная строка
    return (THIS_Y * _WIDTH + _WIDTH - THIS_X - 1);
  }
}
