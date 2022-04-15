// Definice konstanty pro pin relé
#define RELE A4

void setup()
{
  pinMode(RELE, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  // Sepnutí relé
  digitalWrite(RELE, HIGH);
  delay(3000);
  // Rozepnutí relé
  digitalWrite(RELE, LOW);
  delay(3000);
}
