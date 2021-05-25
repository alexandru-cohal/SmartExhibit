#include <ArduinoBLE.h>

#include "BLEData.h"

BLEService smartExhibitService("4A98ABCD-1CC4-E7C1-C757-F1267DD021E8"); // BLE String Service
BLEStringCharacteristic factCharacteristic("992d8ad2-b29b-11eb-8529-0242ac130003", BLERead | BLENotify, 512);
BLEStringCharacteristic discussionCharacteristic("b04396c6-b29b-11eb-8529-0242ac130003", BLERead | BLEWrite | BLENotify, 512);

int iteration = 0;
int indexFact = 0;

void setup() 
{
  Serial.begin(9600);
  
  if (!BLE.begin()) 
  {
    Serial.println("Starting BLE failed!");
  }

  // Set advertised local name and service UUID
  BLE.setLocalName("SmartExhibit");
  BLE.setAdvertisedService(smartExhibitService);

  // Add the characteristic to the service
  smartExhibitService.addCharacteristic(factCharacteristic);
  smartExhibitService.addCharacteristic(discussionCharacteristic);
  
  // Add the service
  BLE.addService(smartExhibitService);

  // Set the initial value for the characeristic:
  factCharacteristic.writeValue("Facts");
  discussionCharacteristic.writeValue("Discussion");

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
      iteration %= TIME_FOR_FACT_SEC;
      
      if (iteration == 0)
      {
        // Write the new fact
        factCharacteristic.writeValue(facts[indexFact]);
        
        indexFact++;
        indexFact %= 5;
      }

      // Verify if something new was written
      if (discussionCharacteristic.written()) 
      {
        String question = discussionCharacteristic.value();

        // Answer to the question
        if (question == "status")
        {
          discussionCharacteristic.writeValue("I Am Alive!");
        }
        else
        {
          // Check if it is one of the predetermined questions
          bool flagAnswered = false;
          
          for (int indexQuestion = 0; indexQuestion < sizeof(discussionQuestions)/sizeof(String); indexQuestion++)
          {
            if (discussionQuestions[indexQuestion] == question)
            {
              discussionCharacteristic.writeValue(discussionAnswers[indexQuestion]);
              flagAnswered = true;
              break;
            }
          }

          // If not, answer with a generic answer
          if (!flagAnswered)
          {
            discussionCharacteristic.writeValue("I don't know :(");
          }
        }
      }

      delay(1000);
    }

    // When the central disconnects, print it out
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}
