#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int mq2Pin = A0;
int buzzerPin = 8;
int relayPin = 7;

int gasValue;
int threshold = 500;

void setup() {
  pinMode(mq2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Gas Guard");
  lcd.setCursor(0, 1);
  lcd.print("System Started");

  delay(2000);
  lcd.clear();
}

void loop() {

  gasValue = analogRead(mq2Pin);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  lcd.setCursor(0, 0);
  lcd.print("Gas: ");
  lcd.print(gasValue);
  lcd.print("    ");

  if (gasValue > threshold) {

    // LPG leakage detected
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(relayPin, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("LPG LEAK DETECTED");

  } else {

    // Normal condition
    digitalWrite(buzzerPin, LOW);
    digitalWrite(relayPin, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Gas Level Normal ");
  }

  delay(500);
}
