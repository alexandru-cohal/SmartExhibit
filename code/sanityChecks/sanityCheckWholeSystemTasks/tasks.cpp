/*
 * The definition of the tasks callback functions for all the sensors
 */

#include "tasks.h"

void taskTempHumidSensorCallback()
{
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
}

void taskIlluminanceSensorCallback()
{
  float illuminance = hwPlatform.getIlluminance();
  Serial.print("Illuminance: " + String(illuminance) + " lux");
  Serial.println();
}

void taskMotionSensorCallback()
{
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
}

void taskMicrophoneCallback()
{
  int soundLevel = hwPlatform.getSoundLevel();
  Serial.print("Sound level: " + String(soundLevel));
  Serial.println();
}

void taskIMUSensorCallback()
{
  float x, y, z;
  hwPlatform.getAcceleration(x, y, z);
  Serial.print("AccX: " + String(x) + " G; " + "AccY: " + String(y) + " G; " + "AccZ: " + String(z) + " G; ");
  Serial.println();
  hwPlatform.getAngularVelocity(x, y, z);
  Serial.print("AngVelX: " + String(x) + " deg/sec; " + "AngVelY: " + String(y) + " deg/sec; " + "AngVelZ: " + String(z) + " deg/sec; ");
  Serial.println();
}

void taskPushButtonCallback()
{
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
}

void taskLEDCallback()
{
  hwPlatform.toggleBuiltInLED();
}

void taskSpeakerCallback()
{
  hwPlatform.playTone(200, 50);
}
