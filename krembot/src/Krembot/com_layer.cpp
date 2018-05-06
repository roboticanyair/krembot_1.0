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


#include "com_layer.h"


COMLayer::COMLayer()
{
  connected_ = false;
}

bool COMLayer::connect(const char* ip, uint16_t port)
{
  //TODO: check valid port (return false if not)
  byte ip_arr[4] = {0};
  stringToIp(ip, ip_arr);

  return client_.connect(ip_arr, port);
}

bool COMLayer::isConnected() { return client_.connected(); }

void COMLayer::disconnect() { client_.stop(); }

bool COMLayer::bytesWaiting() { return client_.available(); }

void COMLayer::write(byte val) { client_.write(val); }

void COMLayer::write(byte buff[], size_t len)
{
  client_.write(buff, len);
}

byte COMLayer::read() { return client_.read(); }

uint32_t COMLayer::read(byte buff[], size_t len)
{
  return client_.read(buff, len);
}

void COMLayer::stringToIp(const char *ip_str, byte ip_arr[])
{
  size_t index = 0;

  while (*ip_str) {
      if (isdigit((unsigned char)*ip_str)) {
          ip_arr[index] *= 10;
          ip_arr[index] += *ip_str - '0';
      } else {
          index++;
      }
      ip_str++;
  }
}
