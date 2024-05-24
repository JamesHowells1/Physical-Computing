#include <Servo.h>

Servo servo1;
Servo servo2;

int stickX = A0;
int stickY = A1;

int laser = 11;
int laserSwitch = A2;
int laserNum;

int valX;
int valY;

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  
  pinMode(laser, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  valX = analogRead(stickX);
  valY = analogRead(stickY);

  int angleX = map(valX, 0, 1023, 0, 180);
  int angleY = map(valY, 0, 1023, 0, 180);

  servo1.write(angleX);
  servo2.write(angleY);

  laserNum = analogRead(laserSwitch);
  Serial.println(laserNum);

  if(laserNum == 0){
    analogWrite(laser, HIGH);
  } else {
    analogWrite(laser, LOW);
  }

  delay(50);
}