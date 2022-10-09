//此为HCSR04.h的示例代码
/*
  接线：
    VCC----5V
    Trig---3
    Echo---4
    GND----GND
    注意：trig和echo仅为例程中的引脚，此引脚可自行设定，在实例化时注册即可。
*/
#include <Arduino.h>
#include"HCSR04.h"
int pinTrig=3;
int pinEcho=4;



HCSR04 sensor1(pinTrig,pinEcho);//首先实例化该类，名为sensor1

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Sensor1:");
  Serial.print(sensor1.getDistance());//直接调用getDistance()方法即可，单位为厘米。
  Serial.println();
  sleep(100);//手册建议测量周期在100以上，此处也可防止模块过热。
}