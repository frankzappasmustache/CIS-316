#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DHT11_PIN 7
#define DHTTYPE DHT11
DHT dht(DHT11_PIN, DHTTYPE, 1);

void setup(){
  dht.begin();
  lcd.begin(16, 2);
}

void loop(){
  int chk = dht.read(DHT11_PIN);
  int tmp = dht.readTemperature(true, true);
  int hum = dht.readHumidity(true);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(tmp);
  lcd.print((char)223);
  lcd.print("F");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print("%");
  delay(1000);
}