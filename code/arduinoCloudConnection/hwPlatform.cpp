/*
 * The definition of the HWPlatform class used for interfacing with the hardware components (i.e. sensors and actuators)
 */

#include "hwPlatform.h"

// Constructor with no arguments (initializes the needed sensor objects and sets the needed pins)
HWPlatform::HWPlatform():tempHumidSensor(TEMP_HUMID_SENSOR_PIN, TEMP_HUMID_SENSOR_TYPE), pushButton(PUSH_BUTTON_PIN)
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MOTION_SENSOR_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
}

// Start the modules which need to be started (e.g. serial communication, sensors)
int HWPlatform::begin()
{
  Serial.begin(9600);
  
  tempHumidSensor.begin();
  
  bool flagValidLightSensor = lightSensor.begin(BH1750_TO_GROUND);
  if (!flagValidLightSensor)
  {
    Serial.println("Light sensor failed to initialize");
  }  
  lightSensor.calibrateTiming(); 

  Serial.println("Calibrating the motion sensor... ");
  for (int numSec = 0; numSec < MOTION_SENSOR_CALIBR_TIME_SEC; numSec++)
  {
    delay(1000);
    Serial.println(String(numSec + 1) + " sec. out of " + String(MOTION_SENSOR_CALIBR_TIME_SEC) + " sec. passed");
    this->toggleBuiltInLED();
  }
  Serial.println("Calibration of the motion sensor done!");

  bool flagValidIMU = IMU.begin();
  if (!flagValidIMU)
  {
    Serial.println("IMU sensor failed to initialize!");
  }

  return 0;
}

void HWPlatform::toggleBuiltInLED()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

// Get the temperature in Celsius degrees
float HWPlatform::getTemperature()
{
  return tempHumidSensor.readTemperature();
}

// Get the humidity in %
float HWPlatform::getHumidity()
{
  return tempHumidSensor.readHumidity();
}

// Get the heat index in Celsius degrees
float HWPlatform::getHeatIndex()
{
  float temp = tempHumidSensor.readTemperature();
  float humid = tempHumidSensor.readHumidity();
  return tempHumidSensor.computeHeatIndex(temp, humid, false);
}

// Get the state of the push button (0 = state change from released to pressed, 1 = state change from pressed to release, 2 = otherwise)
unsigned char HWPlatform::getPushButtonStatus()
{
  if (pushButton.getSingleDebouncedPress())
  {
    return 0;
  }

  if (pushButton.getSingleDebouncedRelease())
  {
    return 1;
  }

  return 2;
}

// Get the illuminance in lux
float HWPlatform::getIlluminance()
{
  lightSensor.start();
  return lightSensor.getLux();
}

// Get the motion status (TRUE = motion detected, FALSE = no motion detected)
bool HWPlatform::getMotionStatus()
{
  return digitalRead(MOTION_SENSOR_PIN);
}

// Get the sound level (as returned by the ADC, containing the DC bias from the amplifier)
int HWPlatform::getSoundLevel()
{
  return analogRead(MICROPHONE_PIN);
}

// Play a tone on a specific frequency in Hertz and for a specific duration in milliseconds
void HWPlatform::playTone(unsigned int frequencyHz, unsigned long durationMs)
{
  tone(SPEAKER_PIN, frequencyHz, durationMs);
}

// Get the acceleration for each axis in G
void HWPlatform::getAcceleration(float& x, float& y, float& z)
{
  IMU.readAcceleration(x, y, z);
}

// Get the angular velocity for each axis in degrees/second
void HWPlatform::getAngularVelocity(float& x, float& y, float& z)
{
  IMU.readGyroscope(x, y, z);
}
