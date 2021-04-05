#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);  
  dht.begin();
}

void loop() 
{
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  float hindex = dht.computeHeatIndex(t, h, false);

  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from the DHT11 sensor!");
  }
  else
  {
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" deg C; ");
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %; ");
    Serial.print("Heat index: ");
    Serial.print(hindex);
    Serial.print(" deg C; ");
    Serial.println("");
  }

  delay(1000);
}