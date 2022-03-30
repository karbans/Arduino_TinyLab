// Pro lepší čitelnost dáme Serial1 alias BT
// Serial1 operuje pouze na pinech 0, 1, kde je aktuálně připojený modul WiFi
#define WF Serial1

// Dopředná deklarace, metodu popíšeme na konci
void wifiKonektivita();

void setup()
{
  // Otevření komunikace Arduino - USB
  Serial.begin(9600);
  // Otevření komunikace Arduino - BT
  // WiFi modul funguje implicitně na 115200 baudech
  BT.begin(115200);
  while (!Serial);

  Serial.println("Nezapomeň přepnout sériový monitor na 'Obojí NL & CR!'");
  Serial.println("--------------------------+---------------------");
  Serial.println("Příkaz                    | Akce");
  Serial.println("--------------------------+---------------------");
  Serial.println("AT                        | Test, vrátí OK");
  Serial.println("AT+CWMODE=(1-3)           | Mód (Client/AP/C+AP");
  Serial.println("AT+CWLAP                  | Výpis sítí");
  Serial.println("AT+CWJAP=\"SSID\",\"PW\"      | Připojení k síti");
  Serial.println("AT+CIFSR                  | Info o připojení");
  Serial.println("AT+CWQAP                  | Odpojení od sítě");
  Serial.println("--------------------------+---------------------");
}

void loop()
{
  wifiKonektivita();
}

void wifiKonektivita()
{
  while (Serial.available())
  {
    WF.write(Serial.read());
  }

  while (WF.available())
  {
    Serial.write(WF.read());
  }
}
