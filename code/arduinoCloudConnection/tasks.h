/*
 * The declaration of the tasks callback functions for all the sensors
 */

#ifndef TASKS_H
#define TASKS_H

#include "hwPlatform.h"
#include "thingProperties.h"

#define ACC_THRESHOLD 0.01 // G
#define ANG_VEL_THRESHOLD 0.2 // deg/sec

extern HWPlatform hwPlatform;

void taskTempHumidSensorCallback();
void taskIlluminanceSensorCallback();
void taskMotionSensorCallback();
void taskMicrophoneCallback();
void taskIMUSensorCallback();
void taskPushButtonCallback();

#endif
