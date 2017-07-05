
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
