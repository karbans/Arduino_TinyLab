// Pro lepší čitelnost dáme Serial1 alias BT
// Serial1 operuje pouze na pinech 0, 1, kde je připojený modul BT
#define BT Serial1

String ssid = "joudoid-Guest"
String pw = "karelsepokakal"

void wifiKonektivita();
void prikaz(String parametr);
void prTest();
void prMod();
void prVypis();
void prPripoj();
void prOdpoj();
void prInfo();

void setup()
{
  // Otevření komunikace Arduino - USB
  Serial.begin(9600);
  // Otevření komunikace Arduino - BT
  // WiFi modul funguje implicitně na 115200 baudech
  BT.begin(115200);
  while (!Serial);

  Serial.println("Nezapomeň přepnout sériový monitor na 'Obojí NL & CR!'");
  Serial.println("--------+---------------------");
  Serial.println("Příkaz  | Akce");
  Serial.println("--------+---------------------");
  Serial.println("1       | Test, vrátí OK");
  Serial.println("2       | Mód (Client/AP/C+AP");
  Serial.println("3       | Výpis sítí");
  Serial.println("4       | Připojení k síti");
  Serial.println("5       | Info o připojení");
  Serial.println("6       | Odpojení od sítě");
  Serial.println("--------+---------------------");
}

void loop()
{
  wifiKonektivita();
}

void wifiKonektivita()
{
  while (Serial.available())
  {
    BT.write(Serial.read());
  }

  while (BT.available())
  {
    Serial.write(BT.read());
  }
}

void prikaz(String parametr)
{
  Serial.println(parametr);
}

void prTest()
{
  prikaz("AT");
}

void prMod()
{
  prikaz("AT+CWMODE=1");
}

void prVypis()
{
  prikaz("AT+CWLAP ");
}

void prPripoj()
{
  prikaz("AT+CWJAP=\"SSID\",\"PW\"
}
void prOdpoj();
void prInfo();
