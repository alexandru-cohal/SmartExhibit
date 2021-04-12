/*
 * The declaration of the tasks callback functions for all the sensors
 */

#ifndef TASKS_H
#define TASKS_H

#include "hwPlatform.h"

extern HWPlatform hwPlatform;

void taskTempHumidSensorCallback();
void taskIlluminanceSensorCallback();
void taskMotionSensorCallback();
void taskMicrophoneCallback();
void taskIMUSensorCallback();
void taskPushButtonCallback();
void taskLEDCallback();
void taskSpeakerCallback();

#endif
