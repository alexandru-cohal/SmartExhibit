
#include "thingProperties.h"

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

void onAlarmChange()
{  
}

void onMessageChange()
{
  if (message == "status")
  {
    message = "I Am Alive!";
  }
  else
  {
    message = "Unknown command :(";
  }
}

void initProperties()
{
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(temperature, READ, ON_CHANGE, NULL, 1);
  ArduinoCloud.addProperty(humidity, READ, ON_CHANGE, NULL, 1);
  ArduinoCloud.addProperty(illuminance, READ, ON_CHANGE, NULL, 1);
  ArduinoCloud.addProperty(sound, READ, ON_CHANGE, NULL, 1);
  ArduinoCloud.addProperty(motionAround, READ, ON_CHANGE, NULL, 1);
  ArduinoCloud.addProperty(motionItselfLinear, READ, ON_CHANGE, NULL, 1);
  ArduinoCloud.addProperty(motionItselfAngular, READ, ON_CHANGE, NULL, 1);
  ArduinoCloud.addProperty(buttonPress, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(alarm, READWRITE, ON_CHANGE, onAlarmChange);
  ArduinoCloud.addProperty(message, READWRITE, ON_CHANGE, onMessageChange);
}
