#include <Servo.h>

Servo servoLeft;
Servo servoRight;

//
// Go straight straight_dur milliseconds
//
void goStraight(int straight_dur) {

  servoLeft.writeMicroseconds (1700);
  servoRight.writeMicroseconds (1300);
  delay(straight_dur);
}

//
// Turn left turn_dur milliseconds
//
// Left wheel is not fixed, but is turning slowly
// Right wheel is at full speed
//
void turnLeft(int turn_dur) {
  servoLeft.writeMicroseconds (1550);
  servoRight.writeMicroseconds (1300);
  delay(turn_dur);
}

//
// Turn left 45 degrees
//
void turnLeft45() {
  turnLeft(1300);
}

//
// Turn Left 180 degrees
//
void turnLeft180() {
  turnLeft(6000);
}

//
// Turn right turn_dur milliseconds
//
// Right wheel is not fixed, but is turning slowly
// Left wheel is at full speed
//
void turnRight(int turn_dur) {
  servoLeft.writeMicroseconds (1700);
  servoRight.writeMicroseconds (1460);
  delay(turn_dur);
}

//
// Turn right 45 degrees
//
void turnRight45() {
  turnRight(1300);
}

//
// Turn right 180 degrees
//
void turnRight180() {
  turnRight(6000);
}

void setup() {

  // Important to first attach to the servos, otherwise nothing happens
  servoLeft.attach (13);
  servoRight.attach (12);

  // Do this 5 times
  for (int i = 0; i < 5; i++) {
    turnLeft45();
    goStraight(2500);
    turnRight180();
    turnRight45();
    goStraight(2500);
    turnLeft180();
    turnLeft45();
  }
  
  servoLeft.detach();
  servoRight.detach();
}

void loop() {
  // put your main code here, to run repeatedly:

}