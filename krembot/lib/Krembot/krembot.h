#ifndef KREMBO_H
#define KREMBO_H

#include "application.h"
#include "battery.h"
#include "mobile_base.h"
#include "rgb_led.h"
#include "rgba_sensor.h"
#include "com_layer.h"
#include "wkc_krembot2pc.h"
#include "wkc_pc2krembot.h"
#include "bluesky_timer.h"
#include "dac_bumpers.h"
//#include "imu_sensor.h"

/*TODO:
1. add connection between photons
2. add errors checking in code
4. implement connection between master and photon (protocol)
5. add documentation
6. add documentation of Kiril wirings
7. add documentation of how to solve problems like breathing green, and how to flash version 0.6.1
8. add photon light functions from photon api
9. add photon timer functions from photon api
10. add photon logging functions from photon api
11. add documentation of wkp protocol
12. add getting photon details functions from photon api (linke name)
13. change rgba_sensor to color_sensor
14. initiate Serial.begin inside photon and encapsulte Serial methods
*/

#define SEND_DATA_INTERVAL 100 //ms

enum class RGBAAddr //TODO: extract this to krembot, and make constructor here take int8
{
  Front = 0,
  FrontRight = 1,
  Right = 2,
  RearRight = 3,
  Rear = 4,
  RearLeft = 5,
  Left = 6,
  FrontLeft = 7
};

class Krembot
{
private:

  bool id_was_sent_,
       master_asks_for_data_,
       skip_led_gui_cmds_,
       skip_base_gui_cmds_,
       bump_calib_mode_;
  COMLayer com_;
  BlueSkyTimer send_data_timer_;
  String my_name_;
  String master_ip_;
  uint16_t port_;


  WKCKrembot2PC createWKC();
  void rcveWKC();
  void sendWKC(WKCKrembot2PC& wkc_msg);
  void handleWKCFromPC(WKCPC2Krembot wkc_msg);
  void saveMyName(const char *topic, const char *data);

public:

  RGBASensor RgbaFront;
  RGBASensor RgbaRear;
  RGBASensor RgbaRight;
  RGBASensor RgbaLeft;
  RGBASensor RgbaFrontRight;
  RGBASensor RgbaFrontLeft;
  RGBASensor RgbaRearRight;
  RGBASensor RgbaRearLeft;

  MobileBase Base;
  DacBumpers Bumpers;
  Battery Bat;
  RGBLed Led;

void setup(String master_ip="192.168.2.112", uint16_t port=8000);

  //void setup() {
  //  setup("192.168.2.112",8000);
  //}

void loop();
  String getID() { return System.deviceID(); }
  String getName() { return  my_name_; }

};

#endif //KREMBO_H
