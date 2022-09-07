#include <Servo.h>

Servo servo2;
Servo servo3;
Servo servo4;

int button1 = 12;
int button2 = 13;
int button3 = 10;
int button4 = 11;
int button5 = 4;
int button6 = 6;

int pos2 = 0;
int pos3 = 0;
int pos4 = 0;

void setup() {
  // put your setup code here, to run once:
  servo2.attach(9);
  servo3.attach(5);
  servo4.attach(7);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP); 
  pinMode(button3, INPUT_PULLUP); 
  pinMode(button4, INPUT_PULLUP); 
  pinMode(button5, INPUT_PULLUP); 
  pinMode(button6, INPUT_PULLUP); 

}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead(button1)==LOW) && (pos2 < 180)){
    pos2 += 1;
    servo2.write(pos2);
    delay(10);
  }
  if((digitalRead(button2)==LOW) && (pos2 > 0)){
    pos2 -= 1;
    servo2.write(pos2);
    delay(10);
  }
  if((digitalRead(button3)==LOW) && (pos3 < 180)){
    pos3 += 1;
    Serial.println(pos3);
    servo3.write(pos3);
    delay(10);
  }
  if((digitalRead(button4)==LOW) && (pos3 > 0)){
    pos3 -= 1;
    Serial.println(pos3);
    servo3.write(pos3);
    delay(10);
  }
  if((digitalRead(button5)==LOW) && (pos4 < 180)){
    pos4 += 1;
    Serial.println(pos4);
    servo4.write(pos4);
    delay(10);
  }
  if((digitalRead(button6)==LOW) && (pos4 > 0)){
    pos4 -= 1;
    Serial.println(pos4);
    servo4.write(pos4);
    delay(10);
  }

}
