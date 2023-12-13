#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD with I2C address 0x27, 16 columns, and 2 rows.

void setup() {
  lcd.begin(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
}

void loop() {
  String message = "Computer Engineering"; // The message to display
  int messageLength = message.length(); // The length of the message
  int displayLength = 16; // The length of the LCD display

  for (int i = 0; i <= messageLength + displayLength; i++) {
    lcd.clear(); // Clear the display
    int startIndex = i - displayLength; // Calculate the starting index of the message
    if (startIndex < 0) startIndex = 0; // Limit the starting index to 0
    int endIndex = i; // Calculate the ending index of the message
    if (endIndex > messageLength) endIndex = messageLength; // Limit the ending index to the length of the message
    lcd.setCursor(displayLength - i, 0); // Set the cursor position to the rightmost column of the top row
    lcd.print(message.substring(startIndex, endIndex)); // Print the substring of the message that is currently visible
    delay(500); // Delay for a short period of time to slow down the animation
  }
}
