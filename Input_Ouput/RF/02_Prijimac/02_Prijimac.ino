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
  rf.openReadingPipe(1, rfVysilac);
  // Nastavení RF modulu do přijímače
  rf.startListening();
}

void loop()
{
  // Parametr přenosu musí být uint
  uint8_t prenos;
  // Kontrola přenosu
  if (rf.available(&prenos))
  {
    // Velikost dat přenosu
    uint8_t velikost = rf.getPayloadSize();
    // Přečtení a dosazení do dat, proto reference
    rf.read(&data, velikost);
    Serial.print("Přijata data: ");
    Serial.print(data);
    Serial.print(" o velikosti ");
    Serial.print(velikost);
    Serial.println(" bajtů.");
  }
}
