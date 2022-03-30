// Použité knihovny: I2C komunikace, ovládání EEPROM
#include <Wire.h>
#include <I2C_eeprom.h>

// Deklarace EEPROM (adresa, velikost (štítek IC))
I2C_eeprom eeprom(0x50, I2C_DEVICESIZE_24LC256);

// Metoda pro zápis do paměti
void eepromZapis(String in_text)
{
  int delka;

  delka = in_text.length();
  Serial.print("Zapisuji text o délce ");
  Serial.print(delka);
  Serial.println(" znaků do paměti.");

  if (delka != 0)
  {
    for (int i = 0; i < delka; i++)
    {
      // writeByte(místo v paměti, znak)
      eeprom.writeByte(i, in_text[i]);
    }
  }
}

// Metoda pro čtení z paměti
void eepromCteni(int in_delka)
{
  String cteni;

  Serial.println("Čtu paměť.");

  for (int i = 0; i < in_delka; i++)
  {
    // writeByte(místo v paměti)
    // Bloky musíme převést zpátky do znaků
    cteni += char(eeprom.readByte(i));
  }

  Serial.print("Přečtený text: ");
  Serial.println(cteni);
}

void setup()
{
  String text;
  int delka = 0;

  Serial.begin(115200);
  // Čekáme na start Serialu
  while (!Serial);

  // Inicializace EEPROM
  eeprom.begin();

  // Kontrola připojení
  if (!eeprom.isConnected())
  {
    Serial.println("CHYBA: EEPROM neběží/odpojena.");
    while (true);
  }

  Serial.println("EEPROM běží.");

  Serial.println("Zadej text pro zápis do paměti:");
  while (!Serial.available());
  text = Serial.readString();
  Serial.print("Zadaný text: ");
  Serial.print(text);
  delka = text.length();

  eepromZapis(text);
  eepromCteni(delka);
}

void loop() {}
