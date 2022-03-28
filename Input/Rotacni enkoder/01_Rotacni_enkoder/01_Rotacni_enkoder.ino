// Deklarace pinů enkodéru
#define ENKODER1 A5   // Tlačítko enkodéru
#define ENKODER2 6    // Kolečko A
#define ENKODER3 7    // Kolečko B

// Deklarce proměnných
int posledniStav;
int citac = 0;

void setup()
{
  // Nastavení módů
  pinMode(ENKODER1, INPUT);
  pinMode(ENKODER2, INPUT_PULLUP);
  pinMode(ENKODER3, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop()
{
  int stav = digitalRead(ENKODER2);

  // Sledování stavů a změna čítače podle jejich změn
  if (stav != posledniStav)
  {
    if (digitalRead(ENKODER3) != stav)
    {
      citac++;
    }
    else
    {
      citac--;
    }
  }

  // Reset čítače
  if (analogRead(ENKODER1) != 0)
  {
    citac = 0;
  }

  posledniStav = stav;
  
  Serial.println(citac);
  delay(10);
}
