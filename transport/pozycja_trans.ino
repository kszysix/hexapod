 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN1_1  350 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX1_1  450 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN1_2  100 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX1_2  200 // this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN2_1  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX2_1  250 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN2_2  450 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX2_2  550 // this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN3_1  350 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX3_1  450 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN3_2  250 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX3_2  350 // this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN4_1  550 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX4_1  650 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN4_2  250 //!! this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX4_2  350 //!! this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN5_1  350 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX5_1  450 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN5_2  300 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX5_2  400 // this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN6_1  300 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX6_1  400 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN6_2  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX6_2  250 // this is the 'maximum' pulse length count (out of 4096)

uint8_t servonum1_1 = 0;
uint8_t servonum1_2 = 1;
uint8_t servonum2_1 = 2;
uint8_t servonum2_2 = 3;
uint8_t servonum3_1 = 4;
uint8_t servonum3_2 = 5;
uint8_t servonum4_1 = 6;
uint8_t servonum4_2 = 7;
uint8_t servonum5_1 = 8;
uint8_t servonum5_2 = 9;
uint8_t servonum6_1 = 10;
uint8_t servonum6_2 = 11;

void setup() {
  Serial.begin(9600);
  Serial.println("0 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  pwm.setPWM(servonum1_1, 0, 400);
  pwm.setPWM(servonum1_2, 0,150+100);

  pwm.setPWM(servonum2_1, 0,200);
  pwm.setPWM(servonum2_2, 0,500+100);

  pwm.setPWM(servonum3_1, 0, 400);
  pwm.setPWM(servonum3_2, 0,300+100);

  pwm.setPWM(servonum4_1, 0, 900);
  delay(300);
  pwm.setPWM(servonum4_2, 0,500+100);

   pwm.setPWM(servonum5_1, 0, 400);
  pwm.setPWM(servonum5_2, 0,350+100);

   pwm.setPWM(servonum6_1, 0, 350);
  pwm.setPWM(servonum6_2, 0,200+100);

  delay(20);

}

void loop() {
  delay(200);
    
  delay(200);

delay(200);

}
