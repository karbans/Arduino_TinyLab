// Definice konstanty pro pin teplotního senzoru
#define SENZOR A3

// Funkce pro převod naměřené hodnoty na stupně Celsia
int prepocetTeploty(int in_hodnota)
{
  // 1. vstupní hodnotu vydělíme maximální měřitelnou hodnotou,
  //    je nutné použít desetinné číslo, aby nedošlo k zaokrouhlení
  // 2. Vynásobíme maximální hodnotou napětí na desce (5 V = 5000 mV)
  // 3. Vydělíme inkrement, po kterých senzor měří (10 mV odpovídá 1 °C)
  return in_hodnota / 1024.0 * 5000 / 10;
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int teplota = analogRead(SENZOR);
  
  Serial.print("Teplota pomocí funkce: ");
  Serial.println(prepocetTeploty(analogRead(SENZOR)));

  // map(vstup, min_původní, max_původní, min_nové, max_nové)
  teplota = map(teplota, 0, 1023, 0, 500);
  Serial.print("Teplota pomocí map: ");
  Serial.println(teplota);
  
  delay(1000);
}
