#include <EEPROM.h>

void resetEEPROM()
{
  int EEPROMSize = EEPROM.length();

  for (int i = 0; i < EEPROMSize; i++)
  {
    EEPROM.write(i, 0); // Overwrite each address with 0 (or any other default value)
  }
}

void setup()
{
  // Other setup code

  // Call the resetEEPROM function to clear the EEPROM
  resetEEPROM();

  // Rest of the setup code
}

void loop()
{
  // Your loop code
}
