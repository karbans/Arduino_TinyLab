#include <SPI.h>
#include <SD.h>

#define SDCTECKA 4
File koren;

void sdNastaveni()
{
  Serial.println("Příprava SD karty.");
  if (!SD.begin(SDCTECKA))
  {
    Serial.println("Chyba karty.");
    while (true);
  }
  Serial.println("Karta připravena.");
}

void vypisSoubory(File slozka, int tab)
{
  while (true)
  {
    File soubor = slozka.openNextFile();
    if (! soubor)
    {
      break;
    }
    for (int i = 0; i < tab; i++)
    {
      Serial.print('\t');
    }
    Serial.print(soubor.name());
    if (soubor.isDirectory())
    {
      Serial.print("/");
      vypisSoubory(soubor, tab + 1);
    }
    else
    {
      Serial.print("\t\t");
      Serial.println(soubor.size());
    }
    soubor.close();
  }
}

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  sdNastaveni();
  Serial.println("Vypisuji souborovou strukturu.");
  koren = SD.open("/");
  vypisSoubory(koren, 0);
  Serial.println("Hotovo");
}

void loop() {}
