// Definice konstanty pro pin fotorezistoru
#define FOTOREZISTOR A2
#define LED 10

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(FOTOREZISTOR));
  // Přempujeme naměřené hodnoty na jas LED
  // Max hodnota jasu je 255, změna na vyšší není tak znatelná
  int hodnota = map(analogRead(FOTOREZISTOR), 100, 600, 0, 255);
  analogWrite(LED, hodnota);
  delay(100);
}
