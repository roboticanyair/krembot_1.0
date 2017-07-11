
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

if (!check_low_bat(&krembot,10)) { //10%

  if (set_color_after_name(&krembot)) {

    escape_obstacles(&krembot);

    catch_red_disease(&krembot);

    heal_by_green(&krembot);

    check_reset_by_bumpers(&krembot); //reset if all 4 bumbers are pressed
  }
}

}
