// Based on: https://github.com/arduino-libraries/ArduinoBLE/pull/5

#include <ArduinoBLE.h>

BLEService baseService("4A98ABCD-1CC4-E7C1-C757-F1267DD021E8"); // BLE String Service
BLEStringCharacteristic baseCharacteristic("992d8ad2-b29b-11eb-8529-0242ac130003", BLERead | BLENotify, 512);

int iteration = 0;
int indexStatement = 0;
String statement[2] = {"Hi", "This is SmartExhibit"};

void setup() 
{
  Serial.begin(9600);
  
  if (!BLE.begin()) 
  {
    Serial.println("Starting BLE failed!");
  }

  // Set advertised local name and service UUID
  BLE.setLocalName("SmartExhibit");
  BLE.setAdvertisedService(baseService);

  // Add the characteristic to the service
  baseService.addCharacteristic(baseCharacteristic);
  
  // Add the service
  BLE.addService(baseService);

  // Set the initial value for the characeristic:
  baseCharacteristic.writeValue("Starting...");

  // Start advertising
  BLE.advertise();

  Serial.println("BLE SmartExhibit");
}

void loop() 
{
  // listen for BLE peripherals to connect:
  BLEDevice central = BLE.central();

  // If a central is connected to peripheral
  if (central) 
  {
    // Print the central's MAC address
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    // While the central is still connected to peripheral
    while (central.connected()) 
    {
      iteration++;
      iteration %= 10;
      
      if (iteration == 0)
      {
        baseCharacteristic.writeValue(statement[indexStatement]);
        Serial.println(statement[indexStatement]);
        
        indexStatement++;
        indexStatement %= 2;
      }

      delay(1000);
    }

    // When the central disconnects, print it out
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}
