// Definice konstanty pinu LED
#define LED1 10
#define LED2 11
#define LED3 12
#define LED4 13

void setup()
{
  // Nastavení pinMode(# pinu, I/O)
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop()
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(100);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  delay(100);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
  delay(100);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED1, LOW);
  delay(100);
}
