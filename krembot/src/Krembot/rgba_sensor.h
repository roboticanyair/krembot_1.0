#ifndef RGBA_SENSOR_H
#define RGBA_SENSOR_H

#include "application.h"
#include "math.h"
#include "SparkFun_APDS9960.h"
#define MUX_ADDR 0x70


struct RGBAResult
{
  uint16_t Ambient;
  uint16_t Red;
  uint16_t Green;
  uint16_t Blue;
  uint8_t Proximity; //Raw proximity
  float Distance; //Calculated distance (cm)
  uint8_t ErrCode;
  bool IsReadOk;
};


class RGBASensor
{
private:

  uint8_t addr_;

  SparkFun_APDS9960 apds_;
  bool i2cMuxSelectMe();


public:

  void init(uint8_t addr);
  RGBAResult read();
  void print();
};




#endif
