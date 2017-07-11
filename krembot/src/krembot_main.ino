
#include "Krembot/krembot.h"
#include "Krembot/demos.h"


Krembot krembot;


void setup()
{
krembot.setup();
//init_dance(&krembot);
}


void loop()
{



//Publish event
//pub_RGBAD("Front RGBAD",krembot.RgbaFront.read(),1000);

if (set_color_after_name(&krembot)) {
//Escape front obstacles
escape(&krembot);
//Red disease
catch_red_disease(&krembot);

heal_by_green(&krembot);
}

}
