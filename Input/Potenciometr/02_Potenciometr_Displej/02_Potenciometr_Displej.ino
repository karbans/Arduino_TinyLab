// Použité knihovny: LedControl
#include "LedControl.h"

// Deklarace displeje
// LedControl(Din, CLK, Load, # čipů)
LedControl lc = LedControl(10, 12, 11, 1);

// Definice konstanty pinu potenciometru
#define POTENCIOMETR A0


void setup()
{
  // Probuzení displeje
  // shutdown(adresa, T/F)
  lc.shutdown(0, false);

  // Nastavení podsvícení
  // setIntensity(adresa, <0-15>)
  lc.setIntensity(0, 8);

  // Smazání displeje
  // clearDisplay(adresa)
  lc.clearDisplay(0);

  // Počátek sériového čtení
  Serial.begin(9600);
}

void zobrazCislo(int in_cislo)
{
  int cislo;

  // Zobrazí číslice na správném místě (zobrazuje od začátku)
  for (int i = 3; i >= 0; i--)
  {
    cislo = in_cislo % 10;
    in_cislo /= 10;
    // Zobrazí číslici na pozici
    // setDigit(adresa, pozice, číslo, desetinná tečka T/F)
    lc.setDigit(0, i, cislo, false);
  }
}

void loop()
{
  int hodnota = analogRead(POTENCIOMETR);
  zobrazCislo(hodnota);
  delay(10);
}
