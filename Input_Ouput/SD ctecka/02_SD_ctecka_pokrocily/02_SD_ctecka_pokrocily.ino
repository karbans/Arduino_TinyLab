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
  String out_text;
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
    // Po přečtení zavřeme soubor!
    soubor.close();
    Serial.println("Hotovo.");
  }
  else
  {
    Serial.println("Nepovedlo se otevřít soubor!");
  }
}

void sdSeznamSouboru()
{
  File root = SD.open("/");

  Serial.println("Výpis souborů:");
  while (true)
  {
    File sbr = root.openNextFile();

    if (!sbr)
    {
      break;
    }

    Serial.println(sbr.name());
    sbr.close();
  }
}

void sdFormat()
{
  File root = SD.open("/");

  Serial.println("Mažu souboru na kartě.");
  while (true)
  {
    File sbr = root.openNextFile();

    if (!sbr)
    {
      break;
    }

    sbr.close();
    SD.remove(sbr.name());
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
  sdSeznamSouboru();
  sdFormat();
  sdSeznamSouboru();
}

void loop() {}
