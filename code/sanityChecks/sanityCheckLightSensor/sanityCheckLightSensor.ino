#include <hp_BH1750.h>  

hp_BH1750 lightSensor;      

void setup() 
{
  Serial.begin(9600);

  int flagLightSensor = lightSensor.begin(BH1750_TO_GROUND);
  if (flagLightSensor)
  {
    Serial.println("Light sensor initialized OK");
  }
  else
  {
    Serial.println("Light sensor failed to initialize");
  }  

  lightSensor.calibrateTiming(); 
}

void loop() 
{
  lightSensor.start();   //start a measurement

  // getLux() method is blocking
  // For non-blocking behaviour, use the hasValue() method before the getLux() method
  while (lightSensor.hasValue() == false)
  {
    Serial.print("Light measurement not ready");
    Serial.println();
    delay(100);
  }

  float lux = lightSensor.getLux();

  Serial.print("Light level: ");
  Serial.print(lux);
  Serial.print(" lux");
  Serial.println();

  delay(100);
}
