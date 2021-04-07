/*
 * The declaration of the HWPlatform class used for interfacing with the hardware components (i.e. sensors and actuators)
 */
 
#ifndef HWPLATFORM_H
#define HWPLATFORM_H

// Libraries
#include <Arduino.h>

#include "DHT.h"
#include "Pushbutton.h"
#include "hp_BH1750.h"
#include "Arduino_LSM6DS3.h"

// Defines
#define TEMP_HUMID_SENSOR_PIN           8
#define MOTION_SENSOR_PIN               7
#define PUSH_BUTTON_PIN                 5
#define SPEAKER_PIN                     3
#define MICROPHONE_PIN                  A7

#define TEMP_HUMID_SENSOR_TYPE          DHT11
#define MOTION_SENSOR_CALIBR_TIME_SEC   30

// HWPlatform class declaration
class HWPlatform
{
  // Members
  private:
    DHT tempHumidSensor;
    Pushbutton pushButton;
    hp_BH1750 lightSensor;

  // Methods
  public:
    // Constructor with no arguments (initializes the needed sensor objects and sets the needed pins)
    HWPlatform();
    // Start the modules which need to be started (e.g. serial communication, sensors)
    int begin();
    // Toggle the built-in LED
    void toggleBuiltInLED();
    // Get the temperature in Celsius degrees
    float getTemperature();
    // Get the humidity in %
    float getHumidity();
    // Get the heat index in Celsius degrees
    float getHeatIndex();
    // Get the state of the push button (0 = state change from released to pressed, 1 = state change from pressed to release, 2 = otherwise)
    unsigned char getPushButtonStatus();
    // Get the illuminance in lux
    float getIlluminance();
    // Get the motion status (TRUE = motion detected, FALSE = no motion detected)
    bool getMotionStatus();
    // Get the sound level (as returned by the ADC, containing the DC bias from the amplifier)
    int getSoundLevel();
    // Play a tone on a specific frequency in Hertz and for a specific duration in milliseconds
    void playTone(unsigned int frequencyHz, unsigned long durationMs);
    // Get the acceleration for each axis in G
    void getAcceleration(float& x, float& y, float& z);
    // Get the angular velocity for each axis in degrees/second
    void getAngularVelocity(float& x, float& y, float& z);
};

#endif
