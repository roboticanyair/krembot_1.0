#ifndef WKC_PC2KREMBO_H
#define WKC_PC2KREMBO_H

#include "bit_converter.h"

/***************************************************************************************************************
* |----------------------------------------------N BYTES ARRAY-------------------------------------------------|
* Index |    0 (8 BITS FLAGS)   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |
* Data  | | |BC |BO |JC |DR |TL | JX  | JY  |  MS |  LR |  LG |  LB | BRO | BLO |
* Values|   |0-1|0-1|0-1|0-1|0-1|0-255|0-255|0-255|0-255|0-255|0-255|0-255|0-255|
* -------------------------------------------------------------------------------------------------------------|
* Flags:
* JC = JOY CONTROL = indicates whether master request to control base with joystick
* DR = DATA REQUEST = master asks for sensors/Krembot state data
* TL = TOGGLE LED = master asks to turn on/off led
* BO = BASE OFFSET = indicates whether to set wheels speed offset (calibration)
* BC = BUMPERS CALIBRATION MODE
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
       bumps_calib;

  void fromBytes(byte bytes_arr[]);
  uint16_t size() { return PC2KREMBO_MSG_SIZE; }
  void print();
};

#endif
