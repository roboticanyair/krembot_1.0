#ifndef IMU_H
#define IMU_H

//TODO: IMPLEMENT

#include "quaternionFilters.h"
#include "MPU9250.h"

// Using NOKIA 5110 monochrome 84 x 48 pixel display
// pin 9 - Serial clock out (SCLK)
// pin 8 - Serial data out (DIN)
// pin 7 - Data/Command select (D/C)

#define AHRS true         // Set to false for basic data read
#define SerialDebug true  // Set to true to get Serial output for debugging

class IMUSensor
{
private:
  //int intPin = 12;
  //int myLed = 13;
  MPU9250 imu_;
  void getReadyForRead();
public:
  void init();
  void print();
  float roll();
  float pitch();
  float yaw();

};

#endif
