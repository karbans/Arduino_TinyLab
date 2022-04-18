// Definice konstanty pro pin LED
#define LED 2

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(PIN, HIGH);
  delay(1000);
  digitalWrite(PIN, LOW);
  delay(1000);
}
