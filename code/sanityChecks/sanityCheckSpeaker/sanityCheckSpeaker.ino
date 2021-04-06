#define SPEAKERPIN 3

void setup() 
{
  pinMode(SPEAKERPIN, OUTPUT);
}

void loop() 
{
  tone(SPEAKERPIN, 1000, 500);
  delay(500);

  tone(SPEAKERPIN, 500, 500);
  delay(500);
}
