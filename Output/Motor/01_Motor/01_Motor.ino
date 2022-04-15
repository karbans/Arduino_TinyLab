// Definice pinu pro zapojení motoru
#define MOTOR 5

void setup(){}

void loop()
{
  // Inkrementálně zvyšujeme otáčky motoru
  // Rozpětí pro PWM je 0-255
  for (int i = 0; i < 256; i++)
  {
    analogWrite(MOTOR, i);
    delay(100);
  }
  delay(2000);
  // Inkrementálně snižujeme otáčky motoru 
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(MOTOR, i);
    delay(100);
  }
}
