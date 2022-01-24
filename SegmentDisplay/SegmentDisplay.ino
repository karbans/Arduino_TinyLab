// Použité knihovny: LedControl
#include "LedControl.h"

// Deklarace displeje
// LedControl(Din, CLK, Load, # čipů)
LedControl lc = LedControl(10, 12, 11, 1);

// Deklarace potenciometru
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
  Serial.begin(9600);
}

void zobrazCislo(int in_cislo)
{
  int cislo;
  for(int i = 3; i >= 0; i--)
  {
    cislo = in_cislo % 10;
    in_cislo /= 10;
    lc.setDigit(0, i, cislo, false);
  }
}

void loop()
{
//  for(int i = 0; i < 9999; i++)
//  {
//    zobrazCislo(i);
//    delay(100);
//  }
  int hodnota = analogRead(POTENCIOMETR);
  zobrazCislo(hodnota);
  delay(10);
}
