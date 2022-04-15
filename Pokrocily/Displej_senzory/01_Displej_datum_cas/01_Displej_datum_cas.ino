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

String hodinyVypis()
{
  DateTime ted = rtc.now();
  char cas[9];

  sprintf(cas, "%02d:%02d:%02d\0", ted.hour(), ted.minute(), ted.second());

  return (String)cas;
}

String datumVypis()
{
  DateTime ted = rtc.now();
  char datum[11];

  sprintf(datum, "%02d.%02d.%4d\0", ted.day(), ted.month(), ted.year());

  return (String)datum;
}

String teplotaVypis()
{
  char teplotaC[6];
  int teplota = map(analogRead(SENZOR), 0, 1023, 0, 500);

  sprintf(teplotaC, "%3d C\0", teplota);

  return (String)teplotaC;
}

void displejVypis()
{
  lcd.setCursor(0, 0);
  lcd.print(datumVypis());
  lcd.setCursor(0, 1);
  lcd.print(hodinyVypis());
  lcd.setCursor(11, 1);
  lcd.print(teplotaVypis());
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
