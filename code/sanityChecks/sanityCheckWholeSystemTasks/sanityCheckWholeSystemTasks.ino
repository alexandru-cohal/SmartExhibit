#include <TaskScheduler.h>

#include "hwPlatform.h"
#include "tasks.h"

HWPlatform hwPlatform;
Scheduler scheduler;

#define PERIOD_TEMP_HUMID_SENSOR_MS   1000
#define PERIOD_ILLUMINANCE_SENSOR_MS  500
#define PERIOD_MOTION_SENSOR_MS       5000
#define PERIOD_MICROPHONE_MS          100
#define PERIOD_IMU_SENSOR_MS          100
#define PERIOD_PUSH_BUTTON_MS         500
#define PERIOD_LED_MS                 5000
#define PERIOD_SPEAKER_MS             5000

Task taskTempHumidSensor(PERIOD_TEMP_HUMID_SENSOR_MS, TASK_FOREVER, &taskTempHumidSensorCallback, &scheduler, true);
Task taskIlluminanceSensor(PERIOD_ILLUMINANCE_SENSOR_MS, TASK_FOREVER, &taskIlluminanceSensorCallback, &scheduler, true);
Task taskMotionSensor(PERIOD_MOTION_SENSOR_MS, TASK_FOREVER, &taskMotionSensorCallback, &scheduler, true);
Task taskMicrophone(PERIOD_MICROPHONE_MS, TASK_FOREVER, &taskMicrophoneCallback, &scheduler, true);
Task taskIMUSensor(PERIOD_IMU_SENSOR_MS, TASK_FOREVER, &taskIMUSensorCallback, &scheduler, true);
Task taskPushButton(PERIOD_PUSH_BUTTON_MS, TASK_FOREVER, &taskPushButtonCallback, &scheduler, true);
Task taskLED(PERIOD_LED_MS, TASK_FOREVER, &taskLEDCallback, &scheduler, true);
Task taskSpeaker(PERIOD_SPEAKER_MS, TASK_FOREVER, &taskSpeakerCallback, &scheduler, true);

void setup() 
{
  hwPlatform.begin();
}

void loop() 
{
  scheduler.execute();
}
