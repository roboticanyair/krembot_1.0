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


#ifndef BATTERY_H
#define BATTERY_H

#include "application.h"

#define BATTERY_LVL_LEG A4
#define CHARGING_LVL_LEG A5
#define IS_FULL_CHARGE_LEG D6
#define IS_CHARGINE_LEG DAC

//TODO: update those vals with Kiril
#define MAX_BAT_LVL 4.2
#define MIN_BAT_LVL 3.7
#define MAX_CHRG_LVL 5.0
#define MIN_CHRG_LVL 0.0

class Battery
{
private:

public:

  Battery();
  float readBatLvl(); //lvl in Volt
  uint8_t getBatLvl(); //lvl in %
  float readChargelvl(); //lvl in Volt
  uint8_t getChargeLvl(); //lvl in %
  bool isCharging();
  bool isFull();
  void print();

};

#endif //BATTERY_H
