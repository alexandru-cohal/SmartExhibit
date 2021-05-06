#include <TaskScheduler.h>

#include "tasks.h"
#include "thingProperties.h"

#define PERIOD_TEMP_HUMID_SENSOR_MS   1000
#define PERIOD_ILLUMINANCE_SENSOR_MS  500
#define PERIOD_MOTION_SENSOR_MS       5000
#define PERIOD_MICROPHONE_MS          100
#define PERIOD_IMU_SENSOR_MS          100
#define PERIOD_PUSH_BUTTON_MS         500
#define PERIOD_LED_MS                 5000
#define PERIOD_SPEAKER_MS             5000

HWPlatform hwPlatform;
Scheduler scheduler;

Task taskTempHumidSensor(PERIOD_TEMP_HUMID_SENSOR_MS, TASK_FOREVER, &taskTempHumidSensorCallback, &scheduler, true);
Task taskIlluminanceSensor(PERIOD_ILLUMINANCE_SENSOR_MS, TASK_FOREVER, &taskIlluminanceSensorCallback, &scheduler, true);
Task taskMotionSensor(PERIOD_MOTION_SENSOR_MS, TASK_FOREVER, &taskMotionSensorCallback, &scheduler, true);
Task taskMicrophone(PERIOD_MICROPHONE_MS, TASK_FOREVER, &taskMicrophoneCallback, &scheduler, true);
Task taskIMUSensor(PERIOD_IMU_SENSOR_MS, TASK_FOREVER, &taskIMUSensorCallback, &scheduler, true);
Task taskPushButton(PERIOD_PUSH_BUTTON_MS, TASK_FOREVER, &taskPushButtonCallback, &scheduler, true);

void setup() 
{
  // Initialize the Hardware Platform
  hwPlatform.begin();

  // Initialize the Arduino Cloud connection
  initProperties();
  
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(4);
  ArduinoCloud.printDebugInfo();
  
  while (!ArduinoCloud.connected())
  {
    ArduinoCloud.update();
    delay(500);
  }
}

void loop() 
{
  // Update Arduino Cloud
  ArduinoCloud.update();

  // Execute the ready tasks
  scheduler.execute();

  // React to the changes of the IoT Cloud variables
  if (alarm)
  {
    hwPlatform.playTone(200, 50);
  }
  delay(1000);
}
