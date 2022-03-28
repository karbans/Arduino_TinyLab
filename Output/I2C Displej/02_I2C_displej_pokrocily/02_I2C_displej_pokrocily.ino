// Použité knihovny: I2C komunikace, ovládání displeje
#include <Wire.h>
#include <LiquidTWI2.h>

// Deklarace displeje
// LiquidCrystal_I2C <název>(adresa sběrnice)
LiquidTWI2 lcd(0x20);

// Vlastní funkce na vykreslení displeje
// Vstupní proměnné jsou řetězce znaků, druhý vstup není nutný
// (když se nezadá, implicitní hodnota bude prázdný řetězec)
// Musí být před metodami, které funkci volají
void vykresliDisplej(String text1, String text2 = "")
{
  // Smazání dipleje
  lcd.clear();
  // Nastavení kurzoru
  // V tomto případě není nutný, metoda clear jej vyresetuje na pozici 0, 0
  //lcd.setCursor(0, 0);
  lcd.print(text1);
  lcd.setCursor(0, 1);
  lcd.print(text2);
}

void setup()
{
  Serial.begin(9600);
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
