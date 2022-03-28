// Definice konstanty pro pin fotorezistoru
#define FOTOREZISTOR A2

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(FOTOREZISTOR));
  delay(100);
}
