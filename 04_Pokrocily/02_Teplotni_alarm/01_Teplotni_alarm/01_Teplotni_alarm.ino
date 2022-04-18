#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10
#define BZUCAK A1
#define TEPLOMER A3

int teplotaMax;

void alarm()
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED4, LOW);
  tone(BZUCAK, 1000, 100);
  delay(100);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(LED3, LOW);
  delay(100);
}

void alarmReset()
{
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  noTone(BZUCAK);
}

int teplota()
{
  return map(analogRead(TEPLOMER), 0, 1023, 0, 500);
}

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(BZUCAK, OUTPUT);
  pinMode(TEPLOMER, INPUT);

  Serial.begin(9600);
  while (!Serial);

  Serial.println("Zadej teplotu, při které se spustí alarm:");
  while (!Serial.available())
  {
    teplotaMax = Serial.parseInt();
  }
  Serial.print("Maximální teplota nastavena na ");
  Serial.print(teplotaMax);
  Serial.println(" °C.");
}

void loop()
{
  Serial.print("Aktuální tepolota: ");
  Serial.print(teplota());
  Serial.println(" °C.");
  
  while (teplota() >= teplotaMax)
  {
    alarm();
  }
  
  delay(200);
  alarmReset();
}
