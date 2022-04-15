// Použité knihovny: Wire, RTC
#include <Wire.h>
#include <RTClib.h>

// Deklarace RTC (RTC_model)
RTC_DS1307 rtc;

// Metoda pro nastavení hodin (po absenci napájení RTC)
void hodinyNastaveni()
{
  // Pokud hodiny neběží (kvůli absenci nastavení)
  // Nastaví se datum a čas
  if (!rtc.isrunning())
  {
    Serial.println("Hodiny neběží. Probíhá nastavení.");
    // adjust(čas + datum), v tomto případě
    // DateTime((definice data), (definice času))
    rtc.adjust(DateTime((__DATE__), (__TIME__)));
  }
}

// Metoda pro výpis času
void hodinyVypis()
{
  DateTime ted = rtc.now();

  Serial.print("Aktuální čas: ");
  Serial.print(ted.hour());
  Serial.print(':');
  Serial.print(ted.minute());
  Serial.print(':');
  Serial.print(ted.second());
  Serial.print(' ');
  Serial.print(ted.day());
  Serial.print('.');
  Serial.print(ted.month());
  Serial.print('.');
  Serial.println(ted.year());
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  rtc.begin();

  hodinyNastaveni();
  hodinyVypis();
}

void loop() {}
