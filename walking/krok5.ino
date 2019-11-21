#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <NewPing.h>

#define TRIGGER_PIN  12    // piny do czujnika
#define ECHO_PIN     11
#define MAX_DISTANCE 300

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN1_1  350 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX1_1  450 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN1_2  280 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX1_2  380 // this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN2_1  500 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX2_1  600 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN2_2  420 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX2_2  520 // this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN3_1  350 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX3_1  450 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN3_2  250 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX3_2  350 // this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN4_1  175 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX4_1  275 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN4_2  280 //!! this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX4_2  380 //!! this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN5_1  250 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX5_1  349 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN5_2  330 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX5_2  430 // this is the 'maximum' pulse length count (out of 4096)

#define SERVOMIN6_1  225 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX6_1  325 // this is the 'maximum' pulse length count (out of 4096)
#define SERVOMIN6_2  320 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX6_2  420 // this is the 'maximum' pulse length count (out of 4096)

uint8_t servonum1_1 = 0;
uint8_t servonum1_2 = 1;
uint8_t servonum2_1 = 2;
uint8_t servonum2_2 = 3;
uint8_t servonum3_1 = 4;
uint8_t servonum3_2 = 5;
uint8_t servonum4_1 = 14;
uint8_t servonum4_2 = 7;
uint8_t servonum5_1 = 8;
uint8_t servonum5_2 = 9;
uint8_t servonum6_1 = 10;
uint8_t servonum6_2 = 11;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

uint16_t dist() {
  uint16_t uS = sonar.ping();
  if (uS == 0) {
    Serial.print("MAX: resetting sensor \n");
    pinMode(ECHO_PIN, OUTPUT);
    delay(150);
    digitalWrite(ECHO_PIN, LOW);
    delay(150);
    pinMode(ECHO_PIN, INPUT);
    delay(150);
    return MAX_DISTANCE;
  }
  else {
    return uS / US_ROUNDTRIP_CM;
  }
}

void move_up() {
  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + 5;

    pwm.setPWM(servonum1_2, 0, SERVOMAX1_2 - pulselen);
    pwm.setPWM(servonum2_2, 0, SERVOMAX2_2 - pulselen);
    pwm.setPWM(servonum3_2, 0, SERVOMAX3_2 - pulselen);
    pwm.setPWM(servonum4_2, 0, SERVOMAX4_2 - pulselen);
    pwm.setPWM(servonum5_2, 0, SERVOMAX5_2 - pulselen);
    pwm.setPWM(servonum6_2, 0, SERVOMAX6_2 - pulselen);

    delay(20);
  }
}
void move_down() {
  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + 5;

    pwm.setPWM(servonum1_2, 0, SERVOMIN1_2 + pulselen);
    pwm.setPWM(servonum2_2, 0, SERVOMIN2_2 + pulselen);
    pwm.setPWM(servonum3_2, 0, SERVOMIN3_2 + pulselen);
    pwm.setPWM(servonum4_2, 0, SERVOMIN4_2 + pulselen);
    pwm.setPWM(servonum5_2, 0, SERVOMIN5_2 + pulselen);
    pwm.setPWM(servonum6_2, 0, SERVOMIN6_2 + pulselen);

    delay(20);
  }
}

void step_a(uint16_t v) {
  
  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum2_2, 0, SERVOMIN2_2 + pulselen);
    pwm.setPWM(servonum4_2, 0, SERVOMIN4_2 + pulselen);
    pwm.setPWM(servonum6_2, 0, SERVOMIN6_2 + pulselen);

    delay(20);
  }
  
  for (uint16_t pulselen = 0; pulselen < 50; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum2_1, 0, (SERVOMIN2_1+SERVOMAX2_1)/2 - pulselen);
    pwm.setPWM(servonum4_1, 0, (SERVOMIN4_1+SERVOMAX4_1)/2 + pulselen);
    pwm.setPWM(servonum6_1, 0, (SERVOMIN6_1+SERVOMAX6_1)/2 + pulselen);
    delay(20);
  }
  delay(100);


  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum2_1, 0, SERVOMIN2_1 + pulselen);
    pwm.setPWM(servonum2_2, 0, SERVOMAX2_2 - pulselen);
    pwm.setPWM(servonum4_1, 0, SERVOMAX4_1 - pulselen);
    pwm.setPWM(servonum4_2, 0, SERVOMAX4_2 - pulselen);
    pwm.setPWM(servonum6_1, 0, SERVOMAX6_1 - pulselen);
    pwm.setPWM(servonum6_2, 0, SERVOMAX6_2 - pulselen);

    delay(20);
  }
}

void step_a2(uint16_t v) {
  
  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum1_2, 0, SERVOMIN1_2 + pulselen);
    pwm.setPWM(servonum3_2, 0, SERVOMIN3_2 + pulselen);
    pwm.setPWM(servonum5_2, 0, SERVOMIN5_2 + pulselen);

    delay(20);
  }
  
  for (uint16_t pulselen = 0; pulselen < 50; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum1_1, 0, (SERVOMIN1_1+SERVOMAX1_1)/2 - pulselen);
    pwm.setPWM(servonum3_1, 0, (SERVOMIN3_1+SERVOMAX3_1)/2 - pulselen);
    pwm.setPWM(servonum5_1, 0, (SERVOMIN5_1+SERVOMAX5_1)/2 + pulselen);
    delay(20);
  }
  delay(100);

  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum1_1, 0, SERVOMIN1_1 + pulselen);
    pwm.setPWM(servonum1_2, 0, SERVOMAX1_2 - pulselen);
    pwm.setPWM(servonum3_1, 0, SERVOMIN3_1 + pulselen);
    pwm.setPWM(servonum3_2, 0, SERVOMAX3_2 - pulselen);
    
    pwm.setPWM(servonum5_1, 0, SERVOMAX5_1 - pulselen);
    pwm.setPWM(servonum5_2, 0, SERVOMAX5_2 - pulselen);

    delay(20);
  }
}

void step_b(uint16_t v) {
  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum1_1, 0, SERVOMIN1_1 + pulselen);
    pwm.setPWM(servonum1_2, 0, SERVOMIN1_2 + pulselen);
    pwm.setPWM(servonum3_1, 0, SERVOMIN3_1 + pulselen);
    pwm.setPWM(servonum3_2, 0, SERVOMIN3_2 + pulselen);
    pwm.setPWM(servonum5_1, 0, SERVOMIN5_1 + pulselen);
    pwm.setPWM(servonum5_2, 0, SERVOMIN5_2 + pulselen);

    delay(0);
  }
  delay(100);

  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum1_1, 0, SERVOMAX1_1 - pulselen);
    pwm.setPWM(servonum1_2, 0, SERVOMAX1_2 - pulselen);
    pwm.setPWM(servonum3_1, 0, SERVOMAX3_1 - pulselen);
    pwm.setPWM(servonum3_2, 0, SERVOMAX3_2 - pulselen);
    pwm.setPWM(servonum5_1, 0, SERVOMAX5_1 - pulselen);
    pwm.setPWM(servonum5_2, 0, SERVOMAX5_2 - pulselen);

    delay(20);
  }
}

void prepare_to_up(uint16_t v){
      pwm.setPWM(servonum1_1, 0, (SERVOMIN1_1+SERVOMAX1_1)/2);
      pwm.setPWM(servonum1_2, 0, SERVOMAX1_2);
      delay(50);
      pwm.setPWM(servonum2_1, 0, (SERVOMIN2_1+SERVOMAX2_1)/2);
      pwm.setPWM(servonum2_2, 0, SERVOMAX2_2);
      delay(50);
      pwm.setPWM(servonum3_1, 0, (SERVOMIN3_1+SERVOMAX3_1)/2);
      pwm.setPWM(servonum3_2, 0, SERVOMAX3_2);
      delay(50);
      pwm.setPWM(servonum4_1, 0, (SERVOMIN4_1+SERVOMAX4_1)/2);
      pwm.setPWM(servonum4_2, 0, SERVOMAX4_2);
      delay(50);
      pwm.setPWM(servonum5_1, 0, (SERVOMIN5_1+SERVOMAX5_1)/2);
      pwm.setPWM(servonum5_2, 0, SERVOMAX5_2);
      delay(50);
      pwm.setPWM(servonum6_1, 0, (SERVOMIN6_1+SERVOMAX6_1)/2);
      pwm.setPWM(servonum6_2, 0, SERVOMAX6_2);
      delay(50);
}
  void turn_a(uint16_t v) {
  
  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum2_2, 0, SERVOMIN2_2 + pulselen);
    pwm.setPWM(servonum4_2, 0, SERVOMIN4_2 + pulselen);
    pwm.setPWM(servonum6_2, 0, SERVOMIN6_2 + pulselen);

    delay(20);
  }
  
  for (uint16_t pulselen = 0; pulselen < 50; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum2_1, 0, (SERVOMIN2_1+SERVOMAX2_1)/2 + pulselen);
    pwm.setPWM(servonum4_1, 0, (SERVOMIN4_1+SERVOMAX4_1)/2 + pulselen);
    pwm.setPWM(servonum6_1, 0, (SERVOMIN6_1+SERVOMAX6_1)/2 + pulselen);
    delay(20);
  }
  delay(100);

  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum2_1, 0, SERVOMAX2_1 - pulselen);
    pwm.setPWM(servonum2_2, 0, SERVOMAX2_2 - pulselen);
    pwm.setPWM(servonum4_1, 0, SERVOMAX4_1 - pulselen);
    pwm.setPWM(servonum4_2, 0, SERVOMAX4_2 - pulselen);
    pwm.setPWM(servonum6_1, 0, SERVOMAX6_1 - pulselen);
    pwm.setPWM(servonum6_2, 0, SERVOMAX6_2 - pulselen);

    delay(20);
  }
}

void turn_b(uint16_t v) {
  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum1_1, 0, SERVOMIN1_1 + pulselen);
    pwm.setPWM(servonum1_2, 0, SERVOMIN1_2 + pulselen);
    pwm.setPWM(servonum3_1, 0, SERVOMIN3_1 + pulselen);
    pwm.setPWM(servonum3_2, 0, SERVOMIN3_2 + pulselen);
    pwm.setPWM(servonum5_1, 0, SERVOMIN5_1 + pulselen);
    pwm.setPWM(servonum5_2, 0, SERVOMIN5_2 + pulselen);

    delay(20);
  }
  delay(100);

  for (uint16_t pulselen = 0; pulselen < 100; ) {
    pulselen = pulselen + v;

    pwm.setPWM(servonum1_1, 0, SERVOMAX1_1 - pulselen);
    pwm.setPWM(servonum1_2, 0, SERVOMAX1_2 - pulselen);
    pwm.setPWM(servonum3_1, 0, SERVOMAX3_1 - pulselen);
    pwm.setPWM(servonum3_2, 0, SERVOMAX3_2 - pulselen);
    pwm.setPWM(servonum5_1, 0, SERVOMAX5_1 - pulselen);
    pwm.setPWM(servonum5_2, 0, SERVOMAX5_2 - pulselen);

    delay(20);
  }
}
//minimum to w lewo/w dol
//maks to w prawo/w gore
void setup() {
  Serial.begin(9600);
  Serial.println("0 channel Servo test!");

  pwm.begin();

  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(20);
  delay(1000);
      prepare_to_up(3);
  delay(2000);
}

void loop(){
  uint16_t distance = dist();
  Serial.print(distance);
  Serial.print(" cm \n");
  if(distance>30){
    delay(300);
    prepare_to_up(3);
    delay(300);
    move_up();
    delay(100);
    step_a(4);
    delay(100);
    step_a2(4);
    delay(100);
    step_a(4);
    delay(100);
    step_a2(4);
    delay(100);
    step_a(4);
    delay(100);
    step_a2(4);
    delay(100);
    step_a(4);
    delay(100);
    step_a2(4);
    delay(300);
    move_down();
  }else{
    delay(300);
    prepare_to_up(3);
    delay(300);
    move_up();
    delay(100);
    
    for (uint16_t i = 0; i < 5; i++) {
    turn_a(4);
    delay(100);
    turn_b(4);
    delay(100);
    }
    delay(200);
    move_down();
  }
  
}
