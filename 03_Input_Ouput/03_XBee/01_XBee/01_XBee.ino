// Pro lepší čitelnost dáme Serial1 alias XB
// Serial1 operuje pouze na pinech 0, 1, kde je aktuálně připojený modul XBee
#define XB Serial1

void setup()
{
  // Otevření komunikace Arduino - USB
  Serial.begin(9600);
  // Otevření komunikace Arduino - XB
  // XBee modul funguje implicitně na 9600 baudech
  XB.begin(9600);
}

void loop()
{
  if(Serial.available())
  {
    XB.write(Serial.read());
  }
  if(XB.available())
  {
    Serial.write(XB.read());
  }
}
