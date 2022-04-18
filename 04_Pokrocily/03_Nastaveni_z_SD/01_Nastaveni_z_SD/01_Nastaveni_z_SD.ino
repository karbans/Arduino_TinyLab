#include <SPI.h>
#include <SD.h>

#define SDCTECKA 4

File soubor;
String const SOUBOR_NAZEV = "LED.txt";

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

void sdCteni()
{
  soubor = SD.open(SOUBOR_NAZEV, FILE_READ);
  if (soubor)
  {
    Serial.println("Čtu ze souboru: ");

    while (soubor.available())
    {
      Serial.write(soubor.read());
    }
    soubor.close();
    Serial.println("Hotovo.");
  }
  else
  {
    Serial.println("Nepovedlo se otevřít soubor!");
  }
}

void led

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  sdNastaveni();

  sdCteni();
}

void loop() {}
