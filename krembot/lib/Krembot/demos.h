
unsigned long pub_t=0;

void pub_RGBAD(String event,RGBAResult sensor,int interval) {
  if (millis()-pub_t>interval) {
    char str[100];
  sprintf(str,"R:%d   G:%d   B:%d   A:%d   D:%.1f",sensor.Red,sensor.Green,sensor.Blue,sensor.Ambient,sensor.Distance);
    Particle.publish(event,str);
    pub_t=millis();
  }
}


void init_dance(Krembot *k) {

  k->Led.write(255,0,0);
  delay(200);
  k->Led.write(0,255,0);
  delay(200);
  k->Led.write(0,0,255);
  delay(200);
  k->Led.write(255,255,255);
  delay(200);
  k->Base.drive(0,50);
  delay(200);
  k->Base.drive(0,-50);
  delay(200);
  k->Led.write(0,0,0);
  k->Base.stop();
}


void escape(Krembot *k) {
  float dist=k->RgbaFront.read().Distance;
  int linear=30;
  int angular=0;
  if (dist<12)  angular=90;

  dist=k->RgbaFrontLeft.read().Distance;
  if (dist<10)  angular=-70;

  dist=k->RgbaFrontRight.read().Distance;
  if (dist<10)  angular=70;

if (angular!=0) k->Led.write(255,0,0);
else k->Led.write(0,255,0);

  k->Base.drive(linear,angular);
}
