
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
}

void loop()
{
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("10");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("9");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("8");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("7");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("6");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("5");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("4");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("3");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("2");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("1");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("0");
  delay(1000);
}
