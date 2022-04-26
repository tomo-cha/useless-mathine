// サーボモータを使うlibrary
#include <Servo.h>

// 2 serbo mortor named
Servo armservo;
Servo upservo;
// create servo object to control a servo
// twelve servo objects can be created on most boards
const int arm = 7;
const int up = 9;
const int checkPin = 12;

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(checkPin, INPUT_PULLUP);
  armservo.attach(arm);  // attaches the servo on pin 9 to the servo object
  upservo.attach(up); // attaches the servo on pin 10 to the servo object
  Serial.begin(9600);
}

void loop() {
  armservo.write(-pos+180);
  upservo.write(pos+90);
  Serial.print(pos);
  Serial.print(",");
    if(pos<0){
    pos = 0;
    Serial.println(digitalRead(checkPin));
  }
  else if(pos>95){
    pos = 95;
    Serial.println(digitalRead(checkPin));
  }else{
    // while toggle switch is on
    if(digitalRead(checkPin) == 0){
      pos += 1;
      Serial.println(digitalRead(checkPin));
    }
    // while toggle switch is off
    else{
      pos -= 1;
      //デバッグ用
      Serial.println(digitalRead(checkPin));
    }
  }
}
