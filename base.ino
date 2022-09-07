#include <Stepper.h>
#include <Servo.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

Servo servo2;
Servo servo3;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 6,8,7,9);

int currentrev = 0;
int currentrev2 = 0;

int pos2 = 0;
int pos3 = 0;

const int bt1 = 10;
const int bt2 = 11;
const int bt5 = 2;
const int bt6 = 3;
const int bt3 = 4;
const int bt4 = 5;


void setup() {
    pinMode(bt1,INPUT_PULLUP);
    pinMode(bt2,INPUT_PULLUP);
    pinMode(bt5,INPUT_PULLUP);
    pinMode(bt6,INPUT_PULLUP);
    pinMode(bt3,INPUT_PULLUP);
    pinMode(bt4,INPUT_PULLUP);
    servo2.attach(13);
    servo3.attach(12);
}

void loop() {
    while(digitalRead(bt1)==LOW && currentrev < 1000){
    myStepper.setSpeed(10);
    currentrev += 5;
//    stepsPerRevolution1 += 20;
    myStepper.step(currentrev);
    delay(10);
  }

  while(digitalRead(bt2)==LOW && currentrev > 0){
    myStepper.setSpeed(10);
    currentrev -= 5;
//    stepsPerRevolution1 -= 20;
    myStepper.step(-currentrev);
    delay(10);
  }  
   if((digitalRead(bt5)==LOW) && (pos2 < 180)){
    pos2 += 1;
    servo2.write(pos2);
    delay(10);
  }
  if((digitalRead(bt6)==LOW)  && (pos2 > 0)){
    pos2 -= 1;
    servo2.write(pos2);
    delay(10);
  }

  if((digitalRead(bt3)==LOW) && (pos3 < 180)){
    pos3 += 1;
    servo3.write(pos3);
    delay(10);
  }
  if((digitalRead(bt4)==LOW)  && (pos3 > 0)){
    pos3 -= 1;
    servo3.write(pos3);
    delay(10);
  }
}
