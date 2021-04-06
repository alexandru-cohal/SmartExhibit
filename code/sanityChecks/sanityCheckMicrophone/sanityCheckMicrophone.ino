#define MICROPHONEPIN A7

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int sound = analogRead(MICROPHONEPIN);

  Serial.println(sound);

  delay(10);
}
