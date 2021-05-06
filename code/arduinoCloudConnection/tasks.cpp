/*
 * The definition of the tasks callback functions for all the sensors
 */
 
#include "tasks.h"

CloudTemperatureSensor temperature;
CloudRelativeHumidity humidity;
CloudIlluminance illuminance;
int sound;
CloudMotionSensor motionAround;
CloudMotionSensor motionItselfLinear;
CloudMotionSensor motionItselfAngular;
bool buttonPress;
bool alarm;
String message;

void taskTempHumidSensorCallback()
{
  temperature = hwPlatform.getTemperature();
  humidity = hwPlatform.getHumidity();
}

void taskIlluminanceSensorCallback()
{
  illuminance = hwPlatform.getIlluminance();
}

void taskMotionSensorCallback()
{
  motionAround = hwPlatform.getMotionStatus();
}

void taskMicrophoneCallback()
{
  sound = hwPlatform.getSoundLevel();
}

void taskIMUSensorCallback()
{
  static float aXOld, aYOld, aZOld;
  float aXNew, aYNew, aZNew;
  hwPlatform.getAcceleration(aXNew, aYNew, aZNew);
  bool motionItselfLinearCurrent = false;
  if (abs(aXNew - aXOld) > ACC_THRESHOLD || abs(aYNew - aYOld) > ACC_THRESHOLD || abs(aZNew - aZOld) > ACC_THRESHOLD)
  {
    motionItselfLinearCurrent = true;
  }
  motionItselfLinear = motionItselfLinearCurrent;
  aXOld = aXNew;
  aYOld = aYNew;
  aZOld = aZNew;

  static float omegaXOld, omegaYOld, omegaZOld;
  float omegaXNew, omegaYNew, omegaZNew;
  hwPlatform.getAngularVelocity(omegaXNew, omegaYNew, omegaZNew);
  bool motionItselfAngularCurrent = false;
  if (abs(omegaXNew - omegaXOld) > ANG_VEL_THRESHOLD || abs(omegaYNew - omegaYOld) > ANG_VEL_THRESHOLD || abs(omegaZNew - omegaZOld) > ANG_VEL_THRESHOLD)
  {
    motionItselfAngularCurrent = true;
  }
  motionItselfAngular = motionItselfAngularCurrent;
  omegaXOld = omegaXNew;
  omegaYOld = omegaYNew;
  omegaZOld = omegaZNew;
}

void taskPushButtonCallback()
{
  unsigned char pushButtonStatus = hwPlatform.getPushButtonStatus();
  if (pushButtonStatus == 0)
  {
    buttonPress = true;
  }
  else if (pushButtonStatus == 1)
  {
    buttonPress = false;
  }
}
