// Zahrnutí/import knihovny do projektu
// dokumentace na
// https://evert-arias.github.io/EasyBuzzer/
#include <EasyBuzzer.h>
// Definice konstanty pro pin, který ovládá bzučák
#define BZUCAK A1

void setup()
{
  // Přiřazení
  EasyBuzzer.setPin(BZUCAK);
}

void loop()
{
  EasyBuzzer.update();
  EasyBuzzer.singleBeep(40, 100);
  delay(100);
  EasyBuzzer.stopBeep();
  delay(1000);
}