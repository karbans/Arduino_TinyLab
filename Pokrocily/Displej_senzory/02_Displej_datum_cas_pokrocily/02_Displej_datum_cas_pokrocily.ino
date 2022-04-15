#include <Wire.h>
#include <LiquidTWI2.h>
#include <RTClib.h>

#define SENZOR A3

LiquidTWI2 lcd(0x20);
RTC_DS1307 rtc;

void hodinyNastaveni()
{
  if (!rtc.isrunning())
  {
    Serial.println("Hodiny neběží. Probíhá nastavení.");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void nastavCas(char *cas)
{
  DateTime ted = rtc.now();

  sprintf(cas, "%02d:%02d:%02d\0", ted.hour(), ted.minute(), ted.second());
}

// Funkce vracející aktuální datum
void nastavDatum(char *datum)
{
  DateTime ted = rtc.now();

  sprintf(datum, "%02d.%02d.%4d\0", ted.day(), ted.month(), ted.year());
}

void nastavTeplotu(char *teplota)
{
  int teplotaC = map(analogRead(SENZOR), 0, 1023, 0, 500);

  sprintf(teplota, "%3d C\0", teplotaC);
}

void displejVypis()
{
  char datum[11];
  char cas [9];
  char teplota[5];

  nastavDatum(datum);
  nastavCas(cas);
  nastavTeplotu(teplota);

  lcd.setCursor(0, 0);
  lcd.print(datum);
  lcd.setCursor(0, 1);
  lcd.print(cas);
  lcd.setCursor(11, 1);
  lcd.print(teplota);
}

void setup()
{
  Serial.begin(115200);

  lcd.setMCPType(LTI_TYPE_MCP23008);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  rtc.begin();
  hodinyNastaveni();
}

void loop()
{
  displejVypis();
  delay(1000);
}
