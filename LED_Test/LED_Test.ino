// Definice konstanty pro pin, který ovládá LED
#define PIN_LED 10

void setup()
{
  // Nastavení pinMode(# pinu, I/O)
  pinMode(PIN_LED, OUTPUT);
}

void loop()
{
  // Zápis digitalWrite(# pinu, HIGH = 1 / LOW = 0)
  // Zapíše 1 (rozsvítit) diodu na pinu č. 10
  digitalWrite(PIN_LED, HIGH);
  // Výpis do konzole
  Serial.print("LED ON");
  // Zpoždění delay(čas v ms)
  delay(1000);
  // Zápis 0 (zhasnout) diodu na pinu č. 10
  digitalWrite(PIN_LED, LOW);
  // Výpis do konzole
  Serial.print("LED OFF");
  // Zpoždění delay(čas v ms)
  delay(1000);
}
