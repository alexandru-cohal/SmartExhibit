#include <Pushbutton.h>

#define BUTTONPIN 5

Pushbutton button(BUTTONPIN);

void setup()
{
}

void loop()
{
    if (button.getSingleDebouncedPress())
    {
      Serial.println("Button pressed!");
    }

    if (button.getSingleDebouncedRelease())
    {
      Serial.println("Button released!");
    }
}