// Definice konstanty pro analogový pin, který čte potenciometr
#define PIN_POT A0

void setup()
{
  // Spuštění čtení pinů v hodnotě 9600 baudů
  Serial.begin(9600);
}

void loop()
{
  // Vytvoření proměnné pro čtení hodnoty potenciometru
  // a přiřazení hodnoty z pinu A0 analogRead(# pinu)
  int hodnota = analogRead(PIN_POT);
  // Výpis hodnoty do konzole
  Serial.println(hodnota);
  // Zpoždění 10 ms
  delay(10);
}
