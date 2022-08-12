#include<AFMotor.h>
#include<Servo.h>

Servo myservo;

#define frontLeft 4
#define frontRight 3
#define backLeft 1
#define backRight 2

#define IR 6

AF_DCMotor F1_Motor(frontLeft);
AF_DCMotor F2_Motor(frontRight);
AF_DCMotor B1_Motor(backLeft);
AF_DCMotor B2_Motor(backRight);

void setup() {
  // put your setup code here, to run once:
  pinMode(6,INPUT);
  myservo.attach (10);
  myservo.write(110); 
  Serial.begin(9600);
  F1_Motor.setSpeed(250);
  F2_Motor.setSpeed(250);
  B1_Motor.setSpeed(250);
  B2_Motor.setSpeed(250);
}

void go(){
  F1_Motor.run(FORWARD);
  F2_Motor.run(FORWARD);
  B1_Motor.run(FORWARD);
  B2_Motor.run(FORWARD);
  delay(10);
}

void carStop(){
  F1_Motor.run(RELEASE);
  F2_Motor.run(RELEASE);
  B1_Motor.run(RELEASE);
  B2_Motor.run(RELEASE);
  delay(10);
}

void reverse(){
  F1_Motor.run(BACKWARD);
  F2_Motor.run(BACKWARD);
  B1_Motor.run(BACKWARD);
  B2_Motor.run(BACKWARD);
  delay(200);
}

void right(){
  F1_Motor.run(FORWARD);
  B1_Motor.run(FORWARD);
  //F2_Motor.run(BACKWARD);
  //B2_Motor.run(BACKWARD);
  delay(1000);
}

void left(){
  F2_Motor.run(FORWARD);
  B2_Motor.run(FORWARD);
  //F1_Motor.run(BACKWARD);
  //B1_Motor.run(BACKWARD);
  delay(1000);
}


void servoRight(){
  myservo.write(85);
  delay(500); 
}

void servoLeft(){
  myservo.write(135);
  delay(500); 
}

void servoStraight(){
  myservo.write(110);
  delay(500); 
}

void loop() {
  myservo.write(110);
  delay(500);
  // put your main code here, to run repeatedly:
  if(digitalRead(6)){
    Serial.println(digitalRead(6));
    go();
  }
  else {
    carStop();
    reverse();
    carStop();
    servoLeft();
    if(digitalRead(6)){
      left();
    } else {
      servoRight();
      if(digitalRead(6)){
        right();
      }
    }
  }
}
