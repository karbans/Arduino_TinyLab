// Definice pinů pro tlačítka
#define TLACITKO1 9
#define TLACITKO2 8
#define TLACITKO3 A5

// Definice pinů pro LED
#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10

void setup()
{
  // Nastavení módu pinů
  pinMode(TLACITKO1, INPUT);
  pinMode(TLACITKO2, INPUT);
  pinMode(TLACITKO3, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  // Spuštění čtení pinů v hodnotě 9600 baudů
  Serial.begin(9600);
}

void loop()
{
  int tlacitko1 = digitalRead(TLACITKO1);
  int tlacitko2 = digitalRead(TLACITKO2);
  int tlacitko3 = analogRead(TLACITKO3);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  if (tlacitko1 == 0)
  {
    Serial.println("Tlačítko 1 stisknuto.");
    digitalWrite(LED1, HIGH);
  }

  if (tlacitko2 == 0)
  {
    Serial.println("Tlačítko 2 stisknuto.");
    digitalWrite(LED2, HIGH);
  }

  switch (tlacitko3)
  {
    case 200 ... 220:
      Serial.println("Tlačítko 3 stisknuto");
      digitalWrite(LED3, HIGH);
      break;
    case 500 ... 520:
      Serial.println("Tlačítko 4 stisknuto");
      digitalWrite(LED4, HIGH);
      break;
    case 560 ... 580:
      Serial.println("Tlačítko 3 a 4 stisknuto");
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      break;
  }

  delay(100);
}
