// Použité knihovny: Wire, RTClib
#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

void setup()
{
  Serial.begin(57600);
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop()
{
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  delay(1000);
}
