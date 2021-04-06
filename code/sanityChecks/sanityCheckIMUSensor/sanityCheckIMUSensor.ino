#include <Arduino_LSM6DS3.h>

void setup() 
{
  Serial.begin(9600);

  int flagIMUAvailable = IMU.begin();
  if (!flagIMUAvailable)
  {
    Serial.println("IMU could not be initialized!");
  }
  else
  {
    delay(1000);

    Serial.print("Accelerometer sample rate = ");
    Serial.print(IMU.accelerationSampleRate());
    Serial.println(" Hz");
    Serial.print("Gyroscope sample rate = ");
    Serial.print(IMU.gyroscopeSampleRate());
    Serial.println(" Hz");
  }
}

void loop() 
{
  float x, y, z;
  
  if (IMU.accelerationAvailable()) 
  {
    IMU.readAcceleration(x, y, z);

    Serial.print(x);
    Serial.print(" G \t");
    Serial.print(y);
    Serial.print(" G \t");
    Serial.print(z);
    Serial.print(" G");
    Serial.println();
  }

  
  if (IMU.gyroscopeAvailable()) 
  {
    IMU.readGyroscope(x, y, z);

    Serial.print(x);
    Serial.print(" deg/sec \t");
    Serial.print(y);
    Serial.print(" deg/sec \t");
    Serial.print(z);
    Serial.print(" deg/sec");
    Serial.println();
  }
  
  delay(200);
}