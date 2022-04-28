// Použité knihovny: I2C komunikace, ovládání displeje
#include <Wire.h>
#include <LiquidTWI2.h>

// Deklarace displeje
// LiquidTWI2 <název>(adresa sběrnice)
LiquidTWI2 lcd(0x20);

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  // Inicializace displeje: Nastavení typu
  lcd.setMCPType(LTI_TYPE_MCP23008);
  // Spuštění a nastavení begin(# znaků, # řádků)
  lcd.begin(16, 2);
  // Spuštění podsvícení
  lcd.setBacklight(HIGH);
  // Smazání displeje
  lcd.clear();
  // Nastavení kurzoru
  lcd.setCursor(0, 0);
}

void loop()
{
  // Vyčistíme Serial tak, že jej načteme do proměnné
  String text = Serial.readString();

  Serial.println("Zadej text k zobrazeni na displeji:");

  while (Serial.available() == 0)
  {
    // Prázdná smyčka čekající na vstup
  }

  text = Serial.readString();
  Serial.println(text);
  lcd.clear();
  lcd.print(text);
  delay(1000);
}
