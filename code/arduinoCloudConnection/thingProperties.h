#ifndef THINGPROPERTIES_H
#define THINGPROPERTIES_H

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "arduino_secrets.h"

const char THING_ID[] = "ce33e3b4-ebef-40e5-b5fa-a32633a19716";
const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onAlarmChange();
void onMessageChange();

extern CloudTemperatureSensor temperature;
extern CloudRelativeHumidity humidity;
extern CloudIlluminance illuminance;
extern int sound;
extern CloudMotionSensor motionAround;
extern CloudMotionSensor motionItselfLinear;
extern CloudMotionSensor motionItselfAngular;
extern bool buttonPress;
extern bool alarm;
extern String message;

void initProperties();

extern WiFiConnectionHandler ArduinoIoTPreferredConnection;

#endif
