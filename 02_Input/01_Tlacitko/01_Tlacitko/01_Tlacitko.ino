// Definice pinů pro tlačítka
#define TLACITKO1 9
#define TLACITKO2 8
#define TLACITKO3 A5

void setup()
{
  // Nastavení módu pinů
  pinMode(TLACITKO1, INPUT);
  pinMode(TLACITKO2, INPUT);
  pinMode(TLACITKO3, INPUT);

  // Spuštění čtení pinů v hodnotě 9600 baudů
  Serial.begin(9600);
}

void loop()
{
  // Digitální tlačítka jsou zapojeny pull-up, tudíž spínají do O
  if (digitalRead(TLACITKO1) == 0)
  {
    Serial.println("Tlačítko 1 stisknuto.");
  }

  if (digitalRead(TLACITKO2) == 0)
  {
    Serial.println("Tlačítko 2 stisknuto.");
  }

  // Po pozorování zjistíme hodnoty při stisku tlačítka/tlačítek
  // Podle hodnot se rozhodneme
  int tlacitko3 = analogRead(TLACITKO3);
  switch (tlacitko3)
  {
    case 200 ... 220:
      Serial.println("Tlačítko 3 stisknuto");
      break;
    case 500 ... 520:
      Serial.println("Tlačítko 4 stisknuto");
      break;
    case 560 ... 580:
      Serial.println("Tlačítko 3 a 4 stisknuto");
      break;
  }

  delay(100);
}
