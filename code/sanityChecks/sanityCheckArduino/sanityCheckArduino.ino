unsigned int counter = 0;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500);   

  Serial.print("Hello! This is Arduino Nano 33 IoT! Counter of seconds: ");
  Serial.println(counter);
  counter++;                 
}