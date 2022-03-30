// Použité knihovny: LedControl
#include <LedControl.h>

// Definice konstanty pro pin teplotního senzoru
#define SENZOR A3

// Deklarace displeje
// LedControl(Din, CLK, Load, # čipů)
LedControl lc = LedControl(10, 12, 11, 1);

// Funkce pro převod naměřené hodnoty na stupně Celsia
int prepocetTeploty(int in_hodnota)
{
  // 1. vstupní hodnotu vydělíme maximální měřitelnou hodnotou,
  //    je nutné použít desetinné číslo, aby nedošlo k zaokrouhlení
  // 2. Vynásobíme maximální hodnotou napětí na desce (5 V = 5000 mV)
  // 3. Vydělíme inkrement, po kterých senzor měří (10 mV odpovídá 1 °C)
  return in_hodnota / 1024.0 * 5000 / 10;
}

// Metoda pro zobrazení čísel na displej
// Zobrazuje čísla na správné pozici
void zobrazCislo(int in_cislo)
{
  int cislo;

  for (int i = 3; i >= 0; i--)
  {
    cislo = in_cislo % 10;
    // in_cislo = in_cislo / 10;
    in_cislo /= 10;
    lc.setDigit(0, i, cislo, false);
  }
}

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

void loop()
{
  int teplota = analogRead(SENZOR);

  Serial.println(prepocetTeploty(teplota));

  delay(1000);
}
