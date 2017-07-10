
#include "krembot.h"

#include "demos.h"
//declare only one krembot instance in your code
Krembot krembot;




void setup()
{
krembot.setup();
init_dance(&krembot);

}


void loop()
{

//pub_RGBAD("Front RGBAD",krembot.RgbaFront.read(),1000);
escape(&krembot);
}
