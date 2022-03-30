// Definice konstanty pinu LED
#define LED 10
// Pro lepší čitelnost dáme Serial1 alias BT
// Serial1 operuje pouze na pinech 0, 1, kde je aktuálně připojený modul BT
#define BT Serial1
// Deklarace vstupu přes BT
int data;

void setup()
{
  // Otevření komunikace Arduino - USB
  Serial.begin(9600);
  // Otevření komunikace Arduino - BT
  BT.begin(9600);
  while (!Serial);

  pinMode(LED, OUTPUT);

  Serial.println("Napiš něco...");
  BT.println("Stiskni 1 pro rozsvícení a 0 pro zhasnutí LED.");
}

void loop()
{
  if (BT.available())
  {
    data = BT.read();
    if (data == '1')
    {
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
      BT.println("LED ON");
    }
    else if (data == '0')
    {
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
      BT.println("LED OFF");
    }
  }
  delay(100);
}
