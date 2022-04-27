#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <RTClib.h>

#define SENZOR A3
#define SDCTECKA 4

RTC_DS1307 rtc;
File soubor;
String const SOUBOR_NAZEV = "Teploty.txt";
long const PERIODA = 60000;

void hodinyNastaveni()
{
  if (!rtc.isrunning())
  {
    Serial.println("Hodiny neběží. Probíhá nastavení.");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

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

String teplotaVypis()
{
  char teplotaC[6];
  int teplota = map(analogRead(SENZOR), 0, 1023, 0, 500);

  sprintf(teplotaC, "%3d C\0", teplota);

  return (String)teplotaC;
}

String hodinyVypis()
{
  DateTime ted = rtc.now();
  char cas[9];

  sprintf(cas, "%02d:%02d:%02d\0", ted.hour(), ted.minute(), ted.second());

  return (String)cas;
}

void zapisTeploty()
{
  String info = hodinyVypis() + ": " + teplotaVypis();
  soubor = SD.open(SOUBOR_NAZEV, FILE_WRITE);
  if (soubor)
  {
    Serial.print("Zapisuji do souboru: ");
    Serial.println(info);
    soubor.println(info);
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

  rtc.begin();
  hodinyNastaveni();
  sdNastaveni();
}

void loop()
{
  zapisTeploty();
  delay(PERIODA);
}
