// Definice konstanty pro pin relé
#define RELE A4

void setup()
{
  pinMode(RELE, OUTPUT);

  Serial.begin(9600);
  while (!Serial);
}

void loop()
{
  digitalWrite(RELE, HIGH);
  delay(5000);
  digitalWrite(RELE, LOW);
  delay(5000);
}
