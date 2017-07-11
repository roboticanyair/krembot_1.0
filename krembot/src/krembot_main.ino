
#include "Krembot/krembot.h"
#include "Krembot/demos.h"


Krembot krembot;


void setup()
{
//  krembot.setup("192.168.2.104"); //GUI communication
    krembot.setup();

}


void loop()
{
//  krembot.loop(); //GUI communication

 demo_loop(&krembot);

}
