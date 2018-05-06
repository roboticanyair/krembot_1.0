/*******************************************************************************
* Copyright (c) 2018 RoboTICan
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted (subject to the limitations in the disclaimer
* below) provided that the following conditions are met:
*
*     * Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*     * Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the distribution.
*
*     * Neither the name of the copyright holder nor the names of its
*     contributors may be used to endorse or promote products derived from this
*     software without specific prior written permission.
*
* NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY
* THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
* IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/
/* Author: Elhay Rauper */

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


  void reset(const char *topic, const char *data) {
    if (strcmp(topic,"reset")==0 && (strcmp(data,"all")==0 || strcmp(data,getName().c_str())==0) ) {
      System.reset();
    }
  }

  void setup(String master_ip="10.0.0.31", uint16_t port=8000);

  //void setup() {
  //  setup("192.168.2.112",8000);
  //}

  void loop();
  String getID() { return System.deviceID(); }
  String getName() { return  my_name_; }

  bool have_name() {return my_name_.length()>0 ;}

  void pub_battery() {
    char str[50];
    int level= Bat.getBatLvl();
    sprintf(str,"%d",level);
    Particle.publish("Battery level",str);
  }

};

#endif //KREMBO_H
