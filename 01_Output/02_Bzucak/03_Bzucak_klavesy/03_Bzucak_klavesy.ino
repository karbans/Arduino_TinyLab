// Definice konstanty pro pin, který ovládá bzučák
#define BZUCAK A1
#define TLACITKO 9

// Deklarace proměnné pro stav talčítka
int stisknuto = 1;

void setup()
{
  // Přiřazení
  pinMode(TLACITKO, INPUT);
}

void loop()
{
  stisknuto = digitalRead(TLACITKO);
  Serial.println(stisknuto);
  if (stisknuto == 0)
  {
    tone(BZUCAK, 10);
  }
  else
  {
    noTone(BZUCAK);
  }
}
