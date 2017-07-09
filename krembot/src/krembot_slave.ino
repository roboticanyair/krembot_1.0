#include "krembot.h"

//declare only one krembot instance in your code
Krembot krembot;

void setup()
{
  krembot.setup("192.168.2.112");
  krembot.Led.write(255,0,0);
  delay(200);
  krembot.Led.write(0,255,0);
  delay(200);
  krembot.Led.write(0,0,255);
  delay(200);
  krembot.Led.write(0,0,0);
}

void loop()
{
  krembot.loop();
}
