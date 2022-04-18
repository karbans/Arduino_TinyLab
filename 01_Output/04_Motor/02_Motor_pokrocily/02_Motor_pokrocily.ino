// Definice pinu pro zapojení motoru
#define MOTOR 5
#define POT A0

int hodnota;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  hodnota = analogRead(POT);
  hodnota = map(hodnota, 0, 1023, 0, 255);
  analogWrite(MOTOR, hodnota);
}
