// Definice konstanty pro pin relé
#define RELE A4

void setup()
{
  pinMode(RELE, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(RELE, HIGH);
  delay(3000);
  digitalWrite(RELE, LOW);
  delay(3000);
}
