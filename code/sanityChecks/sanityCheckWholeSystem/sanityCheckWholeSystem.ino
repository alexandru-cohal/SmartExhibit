#include "hwPlatform.h"

HWPlatform hwPlatform;

void setup() 
{
  hwPlatform.begin();
}

void loop() 
{
  // Toggle the built-in LED
  hwPlatform.toggleBuiltInLED();

  // Temperature and humidity sensor
  float temp = hwPlatform.getTemperature();
  float humid = hwPlatform.getHumidity();
  float heatIndex = hwPlatform.getHeatIndex();

  if (isnan(temp) || isnan(humid)) 
  {
    Serial.println("Failed to read from the DHT11 sensor!");
  }
  else
  {
    Serial.print("Temperature: " + String(temp) + " deg C; ");
    Serial.print("Humidity: " + String(humid) + " %; ");
    Serial.print("Heat index: " + String(heatIndex) + " deg C; ");
    Serial.println();
  }

  // Push-button
  unsigned char pushButtonStatus = hwPlatform.getPushButtonStatus();
  if (pushButtonStatus == 0)
  {
    Serial.print("The push button was pressed");
  }
  else if (pushButtonStatus == 1)
  {
    Serial.print("The push button was released");
  }
  else
  {
    Serial.print("The push button is in the same state");
  }
  Serial.println();

  // Illuminance sensor
  float illuminance = hwPlatform.getIlluminance();
  Serial.print("Illuminance: " + String(illuminance) + " lux");
  Serial.println();

  // Motion sensor
  bool motion = hwPlatform.getMotionStatus();
  if (motion)
  {
    Serial.print("Motion");
  }
  else
  {
    Serial.print("No Motion");
  }
  Serial.println();

  // Microphone
  int soundLevel = hwPlatform.getSoundLevel();
  Serial.print("Sound level: " + String(soundLevel));
  Serial.println();

  // Speaker
  hwPlatform.playTone(200, 50);

  // IMU
  float x, y, z;
  hwPlatform.getAcceleration(x, y, z);
  Serial.print("AccX: " + String(x) + " G; " + "AccY: " + String(y) + " G; " + "AccZ: " + String(z) + " G; ");
  Serial.println();
  hwPlatform.getAngularVelocity(x, y, z);
  Serial.print("AngVelX: " + String(x) + " deg/sec; " + "AngVelY: " + String(y) + " deg/sec; " + "AngVelZ: " + String(z) + " deg/sec; ");
  Serial.println();

  delay(5000);
}
