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


#include "wkc_krembot2pc.h"

WKCKrembot2PC::WKCKrembot2PC()
{
  id_ = System.deviceID(); //get 24 long id string
}

void WKCKrembot2PC::toBytes(byte bytes_arr[])
{
  byte flags_byte = 0;

  //battery flags
  BitConverter::setBitInByte(flags_byte,
                             is_bat_full,
                             BAT_FULL_BIT);

  BitConverter::setBitInByte(flags_byte,
                            is_bat_chrgng,
                            BAT_CHARGING_BIT);

  //bumpers flags
  BitConverter::setBitInByte(flags_byte,
                             bumps.front,
                             BUMP_FRONT_BIT);

  BitConverter::setBitInByte(flags_byte,
                            bumps.rear,
                            BUMP_REAR_BIT);

  BitConverter::setBitInByte(flags_byte,
                             bumps.right,
                             BUMP_RIGHT_BIT);

  BitConverter::setBitInByte(flags_byte,
                            bumps.left,
                            BUMP_LEFT_BIT);

  bytes_arr[FLAGS_INDX] = flags_byte;
  bytes_arr[BAT_LVL_INDX] = bat_lvl;
  bytes_arr[BAT_CHRG_LVL_INDX] = bat_chrg_lvl;

  //rgba sensors
  bytes_arr[RGBA_FRONT_START_INDX + RGBA_PROX_OFFSET] = rgba_front.Distance;
  bytes_arr[RGBA_FRONT_START_INDX + RGBA_RED_OFFSET] = RGBA16TO8(rgba_front.Red);
  bytes_arr[RGBA_FRONT_START_INDX + RGBA_GREEN_OFFSET] = RGBA16TO8(rgba_front.Green);
  bytes_arr[RGBA_FRONT_START_INDX + RGBA_BLUE_OFFSET] = RGBA16TO8(rgba_front.Blue);

  bytes_arr[RGBA_REAR_START_INDX + RGBA_PROX_OFFSET] = rgba_rear.Distance;
  bytes_arr[RGBA_REAR_START_INDX + RGBA_RED_OFFSET] = RGBA16TO8(rgba_rear.Red);
  //Serial.println(rgba_rear.Red);///////////////////////////////////////////////////////////////////
  //Serial.print("--->"); Serial.println(RGBA16TO8(rgba_rear.Red));//////////////////////////////
  bytes_arr[RGBA_REAR_START_INDX + RGBA_GREEN_OFFSET] = RGBA16TO8(rgba_rear.Green);
  bytes_arr[RGBA_REAR_START_INDX + RGBA_BLUE_OFFSET] = RGBA16TO8(rgba_rear.Blue);

  bytes_arr[RGBA_RIGHT_START_INDX + RGBA_PROX_OFFSET] = rgba_right.Distance;
  bytes_arr[RGBA_RIGHT_START_INDX + RGBA_RED_OFFSET] = RGBA16TO8(rgba_right.Red);
  bytes_arr[RGBA_RIGHT_START_INDX + RGBA_GREEN_OFFSET] = RGBA16TO8(rgba_right.Green);
  bytes_arr[RGBA_RIGHT_START_INDX + RGBA_BLUE_OFFSET] = RGBA16TO8(rgba_right.Blue);

  bytes_arr[RGBA_LEFT_START_INDX + RGBA_PROX_OFFSET] = rgba_left.Distance;
  bytes_arr[RGBA_LEFT_START_INDX + RGBA_RED_OFFSET] = RGBA16TO8(rgba_left.Red);
  bytes_arr[RGBA_LEFT_START_INDX + RGBA_GREEN_OFFSET] = RGBA16TO8(rgba_left.Green);
  bytes_arr[RGBA_LEFT_START_INDX + RGBA_BLUE_OFFSET] = RGBA16TO8(rgba_left.Blue);

  bytes_arr[RGBA_FRONT_RIGHT_START_INDX + RGBA_PROX_OFFSET] = rgba_front_right.Distance;
  bytes_arr[RGBA_FRONT_RIGHT_START_INDX + RGBA_RED_OFFSET] = RGBA16TO8(rgba_front_right.Red);
  bytes_arr[RGBA_FRONT_RIGHT_START_INDX + RGBA_GREEN_OFFSET] = RGBA16TO8(rgba_front_right.Green);
  bytes_arr[RGBA_FRONT_RIGHT_START_INDX + RGBA_BLUE_OFFSET] = RGBA16TO8(rgba_front_right.Blue);

  bytes_arr[RGBA_FRONT_LEFT_START_INDX + RGBA_PROX_OFFSET] = rgba_front_left.Distance;
  bytes_arr[RGBA_FRONT_LEFT_START_INDX + RGBA_RED_OFFSET] = RGBA16TO8(rgba_front_left.Red);
  bytes_arr[RGBA_FRONT_LEFT_START_INDX + RGBA_GREEN_OFFSET] = RGBA16TO8(rgba_front_left.Green);
  bytes_arr[RGBA_FRONT_LEFT_START_INDX + RGBA_BLUE_OFFSET] = RGBA16TO8(rgba_front_left.Blue);

  bytes_arr[RGBA_REAR_RIGHT_START_INDX + RGBA_PROX_OFFSET] = rgba_rear_right.Distance;
  bytes_arr[RGBA_REAR_RIGHT_START_INDX + RGBA_RED_OFFSET] = RGBA16TO8(rgba_rear_right.Red);
  bytes_arr[RGBA_REAR_RIGHT_START_INDX + RGBA_GREEN_OFFSET] = RGBA16TO8(rgba_rear_right.Green);
  bytes_arr[RGBA_REAR_RIGHT_START_INDX + RGBA_BLUE_OFFSET] = RGBA16TO8(rgba_rear_right.Blue);

  bytes_arr[RGBA_REAR_LEFT_START_INDX + RGBA_PROX_OFFSET] = rgba_rear_left.Distance;
  bytes_arr[RGBA_REAR_LEFT_START_INDX + RGBA_RED_OFFSET] = RGBA16TO8(rgba_rear_left.Red);
  bytes_arr[RGBA_REAR_LEFT_START_INDX + RGBA_GREEN_OFFSET] = RGBA16TO8(rgba_rear_left.Green);
  bytes_arr[RGBA_REAR_LEFT_START_INDX + RGBA_BLUE_OFFSET] = RGBA16TO8(rgba_rear_left.Blue);


  byte id_bytes[ID_SIZE];
  //particle apigetbyte() function is buggy,
  //therefore adding one is needed to insure
  //last byte is returned to array
  id_.getBytes(id_bytes, ID_SIZE+1);
  for(int i=0; i < ID_SIZE; i++)
  {
    bytes_arr[i + ID_START_INDX] = id_bytes[i];
  }
}

uint16_t WKCKrembot2PC::size()
{
  return MSG_SIZE;
}
