// Použité knihovny: RF24
#include <RF24.h>

// Definice konstant pinů RF
#define CE 8
#define CSN 9
// Deklarace vysílače <název>(CE, CSN/CS)
RF24 rf(CE, CSN);
// Deklarace přijímače a vysílače
byte rfPrijimac[] = "prijimac";
byte rfVysilac[] = "vysilac";
// Deklarace přenášených dat
uint8_t data = 0;

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  // Spuštění RF modulu
  rf.begin();
  // Kontrola funkčnosti
  if (!rf.begin())
  {
    Serial.println("RF modul nefunkční/odpojen.");
    while (true);
  }

  // Nastavení síly signálu
  rf.setPALevel(RF24_PA_LOW);
  // Nastavení velikosti přenášených dat
  rf.setPayloadSize(sizeof(data));
  // Nastavení vysílače
  rf.openWritingPipe(rfVysilac);
  // Nastavení přijímače
  rf.openReadingPipe(1, rfPrijimac);
  // Nastavení RF modulu do vysílače
  rf.stopListening();
}

void loop()
{
  // Odešleme data a zároveň zjistíme, jestli by přenos úspěšný
  // .write(ref data, velikost data)
  bool prenos = rf.write(&data, sizeof(data));

  if (prenos)
  {
    Serial.print("Odeslaná data: ");
    Serial.println(data);
    data += 1;
  }
  else
  {
    Serial.println("Přenos nevyšel");
  }
  delay(1000);
}
