// Použité knihovny: SPI (dependence), SD
#include <SPI.h>
#include <SD.h>

// Deklarace pinu SD čtečky
#define SDCTECKA 4
// Deklarace souboru
File soubor;
String const SOUBOR_NAZEV = "test.txt";

// Metoda pro inicializaci SD karty
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

// Metoda pro zápis na kartu
void sdZapis(String in_text)
{
  // Zápis do souboru
  // open(název, zápis/čtení)
  soubor = SD.open(SOUBOR_NAZEV, FILE_WRITE);
  // Pokud se soubor podařilo otevřít, zapíšeme do něj text
  if (soubor)
  {
    Serial.print("Zapisuji do souboru: ");
    Serial.println(in_text);
    soubor.println(in_text);
    // Po přečtení zavřeme soubor!
    soubor.close();
    Serial.println("Hotovo.");
  }
  else
  {
    Serial.println("Nepovedlo se otevřít soubor!");
  }
}

// Metoda pro čtení karty
void sdCteni()
{
  // Čtení souboru
  // open(název, zápis/čtení)
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

void setup()
{
  Serial.begin(9600);
  while (!Serial);

  String text = "Testovací text pro SD kartu.";

  sdNastaveni();
  sdZapis(text);
  sdCteni();
}

void loop() {}
