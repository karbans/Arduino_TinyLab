// Definice pinu pro zapojení motoru
#define MOTOR 5

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(MOTOR, HIGH);
  delay(5000);
  digitalWrite(MOTOR, LOW);
  delay(5000);
}
