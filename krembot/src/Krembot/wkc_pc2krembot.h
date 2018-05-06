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


#ifndef WKC_PC2KREMBO_H
#define WKC_PC2KREMBO_H

#include "bit_converter.h"

/***************************************************************************************************************
* |----------------------------------------------N BYTES ARRAY-------------------------------------------------|
* Index |        0 (8 BITS FLAGS)      |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |
* Data  |  |AVP|LVP|BC |BO |JC |TL |DR | JX  | JY  |  MS |  LR |  LG |  LB | BRO | BLO |
* Values|  |0-1|0-1|0-1|0-1|0-1|0-1|0-1|0-255|0-255|0-255|0-255|0-255|0-255|0-255|0-255|
* -------------------------------------------------------------------------------------------------------------|
* Flags:
* JC = JOY CONTROL = indicates whether master request to control base with joystick
* DR = DATA REQUEST = master asks for sensors/Krembo state data
* TL = TOGGLE LED = master asks to turn on/off led
* BO = BASE OFFSET = indicates whether to set wheels speed offset (calibration)
* BC = BUMPERS CALIBRATION MODE
* LVP = LINEAR VELOCITY POSITIVE = sets the sign of the linear velocity
* AVP = ANGULAR VELOCITY POSITIVE = sets the sign of the angular velocity
*
* JX = JOY X = joystick x value
* JY = JOY Y = joystick y value
* MS = MESSAGE SIZE = user message size
* LR = LED RED
* LG = LEG GREEN
* LB = LED BLUE
* BRO = BASE RIGHT OFFSET
* BLO = BASE LEFT OFFSET
**************************************************************************************************************/

#define PC2KREMBO_MSG_SIZE 9 //size bytes arr

#define FLAGS_INDX 0
        #define DATA_REQ_BIT 0 //master askes photon to send sensors data
        #define TOGGLE_LED_BIT 1
        #define JOY_CTRL_BIT 2
        #define BASE_OFFSET_BIT 3
        #define BUMPS_CALIB_BIT 4
        #define LINEAR_VEL_POSITIVE 5
        #define ANGULAR_VEL_POSITIVE 6

#define JOY_X_INDX 1
#define JOY_Y_INDX 2
#define USER_MSG_SIZE_INDX 3
#define LED_RED_INDX 4
#define LED_GREEN_INDX 5
#define LED_BLUE_INDX 6
#define BASE_RIGHT_OFFSET 7
#define BASE_LEFT_OFFSET 8

class WKCPC2Krembot
{
private:

public:

  uint8_t joy_x,
          joy_y,
          user_msg_size,
          led_red,
          led_green,
          led_blue,
          base_right_offset,
          base_left_offset;

  bool data_req,
       toggle_led,
       joy_control,
       base_offset,
       bumps_calib,
       linear_vel_positive,
       angular_vel_positive;


  void fromBytes(byte bytes_arr[]);
  uint16_t size() { return PC2KREMBO_MSG_SIZE; }
  void print();
};

#endif
