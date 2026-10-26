#include "Adafruit_HX711.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define HX711_DATA  3
#define HX711_CLK   2

LiquidCrystal_I2C lcd(0x27, 16, 2);

Adafruit_HX711 hx711(HX711_DATA, HX711_CLK);

float calibrationFactor = 200.0;

long zeroOffset = 430000;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  hx711.begin();

  lcd.setCursor(0, 0);
  lcd.print("Weight Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);

  lcd.clear();
  lcd.print("Weight System");
  Serial.println("Weight Monitoring System Started");
}

void loop() {
  long rawReading = hx711.read();
s
  float weightGrams =
      (rawReading - zeroOffset) / calibrationFactor;

  if (weightGrams < 0) {
    weightGrams = 0;
  }

  float weightKg = weightGrams / 1000.0;

  lcd.setCursor(0, 0);
  lcd.print("Weight:         ");

  lcd.setCursor(0, 1);
  lcd.print(weightKg, 3);
  lcd.print(" kg            ");

  Serial.print("Raw Reading: ");
  Serial.print(rawReading);

  Serial.print(" | Weight: ");
  Serial.print(weightKg, 3);
  Serial.println(" kg");

  delay(500);
}
