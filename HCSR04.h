/*
用法：
  1、实例化一个HCSR04类，例如:
              HCSR04 sona(pinTrig,pinEcho); //trig引脚在前，echo引脚在后
  2、需要获取距离时，调用该类下的函数，例如double dis = sona.getDistance();//sona为上方设置的实例名,输出单位为cm。

*/

#include "Arduino.h"
class HCSR04
{
    public:
        HCSR04(int trig,int echo);
       double getDistance();

    private:
        int pinTrigger;
        int pinEcho;
};
  //input trigger pin and echo pin.
HCSR04::HCSR04(int trig,int echo)
{
  pinTrigger = trig;
  pinEcho = echo;
  pinMode(pinTrig,OUTPUT);
}
//True to return in cm,false to return in inches.
double HCSR04::getDistance()
{
  long duration;
  double cm;
  // triggered by a HIGH pulse of 10  microseconds.
  //ensure a clean HIGH pulse:
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(5);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pinEcho, INPUT);
  duration = pulseIn(pinEcho, HIGH);
  // Convert the time into a distance
  cm = (duration/2) * 0.0343;     // Divide by 29.1 or multiply by 0.0343
  //inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
   return cm;
    //return _mode?cm:inches;
}