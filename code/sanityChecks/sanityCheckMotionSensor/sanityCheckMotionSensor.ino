#define PIRPIN 7
#define CALIBRTIMESEC 30

bool pirState = false; // true = motion detected, false otherwise

void setup() 
{
  Serial.begin(9600);

  pinMode(PIRPIN, INPUT);
  
  Serial.println("Calibrating the sensor: ");
  for (int indexSec = 0; indexSec < CALIBRTIMESEC; indexSec++)
  {
    delay(1000);

    Serial.print(indexSec + 1);
    Serial.print(" sec. out of ");
    Serial.print(CALIBRTIMESEC);
    Serial.print(" sec. passed");
    Serial.println();
  }
  Serial.println("Calibration done!");
}

void loop() 
{
  int pirValue = digitalRead(PIRPIN);

  Serial.print("Value read: ");
  Serial.print(pirValue);
  Serial.println();

  if (pirValue == HIGH && pirState == false)
  {
    pirState = true;
    Serial.println("Motion detected!");
  }
  else if (pirValue == LOW && pirState == true)
  {
    pirState = false;
    Serial.println("Motion ended!");
  }

  delay(100);
}