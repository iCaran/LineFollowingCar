#include<AFMotor.h>

#define leftMotorTerminal 1
#define rightMotorTerminal 4
#define IR 6

AF_DCMotor leftMotor(leftMotorTerminal);
AF_DCMotor rightMotor(rightMotorTerminal);

void setup() {
  // put your setup code here, to run once:
  pinMode(6,INPUT);
  Serial.begin(9600);
}

void go(){
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
  delay(10);
}

void stop(){
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(6)) go();
  else stop();
}
