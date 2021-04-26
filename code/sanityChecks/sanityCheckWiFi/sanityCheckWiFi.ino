#include <WiFiNINA.h>

#include "arduino_secrets.h"

void setup() 
{
  Serial.begin(9600);

  delay(2000);

  // Connect to the WiFi network
  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED) 
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    
    status = WiFi.begin(SECRET_SSID, SECRET_PASS);
    
    // Wait 1 seconds for connection
    delay(1000);
  }
  Serial.println("Connected to wifi");

  // Enable the low power mode of the WiFi module
  WiFi.lowPowerMode();
}

void loop() 
{
  Serial.print("Ping ");
  Serial.print("www.google.com");
  Serial.print(": ");

  int pingResult = WiFi.ping("www.google.com");

  if (pingResult >= 0) 
  {
    Serial.print("SUCCESS! RTT = ");
    Serial.print(pingResult);
    Serial.println(" ms");
  } else 
  {
    Serial.print("FAILED! Error code: ");
    Serial.println(pingResult);
  }

  delay(5000);
}
