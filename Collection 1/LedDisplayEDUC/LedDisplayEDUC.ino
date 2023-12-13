#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte heart[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};
byte smiley[] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};
byte sound[] = {
  B00011,
  B00011,
  B00010,
  B00010,
  B01110,
  B11110,
  B11110,
  B01100
};
byte sound2[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};
void setup()
{ 


  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
  lcd.createChar(2, sound);
  lcd.createChar(3, sound2);
}

void loop()
{ 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write((byte)3); // sound2 
  lcd.setCursor(2, 0);
  lcd.write((byte)2); // sound
  lcd.setCursor(4, 0);
  lcd.write((byte)3); // sound2 
  lcd.setCursor(6, 0);
  lcd.write((byte)2); // sound
  lcd.setCursor(8, 0);
  lcd.write((byte)3); // sound2
  lcd.setCursor(10, 0);
  lcd.write((byte)2); // sound
  lcd.setCursor(12, 0);
  lcd.write((byte)3); // sound2
  lcd.setCursor(14, 0);
  lcd.write((byte)2); // sound
  
  lcd.setCursor(1, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(3, 1);
  lcd.write((byte)0); // heart
  lcd.setCursor(5, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(7, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(9, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(11, 1);
  lcd.write((byte)0); // heart
  lcd.setCursor(13, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(15, 1);
  lcd.write((byte)0); // heart
  delay(16000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Kakainis na    ");
  lcd.setCursor(0, 1);
  lcd.print("    ayaw mong   ");
  delay(5000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" maniwalang     ");
  lcd.setCursor(0, 1);
  lcd.print("    mahal kita  ");
  delay(4000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Ano pa bang    ");
  lcd.setCursor(0, 1);
  lcd.print("  kailangan kong");
  delay(5000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" patunayan sa'yo");
  lcd.setCursor(0, 1);
  lcd.print("    sinta?      ");
  delay(3000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Pero           ");
  lcd.setCursor(0, 1);
  lcd.print("  naiintindihan ");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    ko naman,   ");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" iniiwasan mo   ");
  lcd.setCursor(0, 1);
  lcd.print("   lang masaktan");
  delay(4000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" 'di ka         ");
  lcd.setCursor(0, 1);
  lcd.print("   madedehado,  ");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" kung sasagutin ");
  lcd.setCursor(0, 1);
  lcd.print("   mo lang ako  ");
  delay(4000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Paninindigan   ");
  lcd.setCursor(0, 1);
  lcd.print("   kita, oo     ");
  delay(4000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mamahalin kitang");
  lcd.setCursor(0, 1);
  lcd.print("   buong buo    ");
  delay(6000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Kahit sa       ");
  lcd.setCursor(0, 1);
  lcd.print("   pagtanda,    ");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  ako'y sa'yo   ");
  delay(4000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Paninindigan   ");
  lcd.setCursor(0, 1);
  lcd.print("   kita, oo     ");
  delay(3500);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Anumang        ");
  lcd.setCursor(0, 1);
  lcd.print("   sabihin ng   ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" magulong mundo ");
  delay(3000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Kahit ayaw     ");
  lcd.setCursor(0, 1);
  lcd.print("   nilang       ");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   ako'y sayo   ");
  delay(3000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Ika'y ");
  lcd.setCursor(0, 1);
  lcd.print("   iingatan ko  ");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write((byte)3); // sound2 
  lcd.setCursor(2, 0);
  lcd.write((byte)2); // sound
  lcd.setCursor(4, 0);
  lcd.write((byte)3); // sound2 
  lcd.setCursor(6, 0);
  lcd.write((byte)2); // sound
  lcd.setCursor(8, 0);
  lcd.write((byte)3); // sound2
  lcd.setCursor(10, 0);
  lcd.write((byte)2); // sound
  lcd.setCursor(12, 0);
  lcd.write((byte)3); // sound2
  lcd.setCursor(14, 0);
  lcd.write((byte)2); // sound
  
  lcd.setCursor(1, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(3, 1);
  lcd.write((byte)0); // heart
  lcd.setCursor(5, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(7, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(9, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(11, 1);
  lcd.write((byte)0); // heart
  lcd.setCursor(13, 1);
  lcd.write((byte)0); // heart 
  lcd.setCursor(15, 1);
  lcd.write((byte)0); // heart
  delay(20000);
}
