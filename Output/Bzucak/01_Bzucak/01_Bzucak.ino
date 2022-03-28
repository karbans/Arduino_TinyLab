// Definice konstanty pro pin, který ovládá bzučák
#define BZUCAK A1

void setup()
{
  // Nastavení pinMode(# pinu, I/O)
  pinMode(BZUCAK, OUTPUT);
}

void loop()
{
  // Vyvolání tónu tone(# pinu, čas v ms)
  tone(BZUCAK, 1000);
  Serial.print("Vydávám zvuk.");
  delay(1000);
  // Zrušení tónu noTone(# pinu, čas v ms)
  noTone(BZUCAK);
  Serial.print("Jsem zticha.");
  delay(1000);
}
