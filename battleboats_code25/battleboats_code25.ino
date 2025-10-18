#include "motors.h"
#include "ultrasonic.h"
#include "logic.h"

void setup() {
  Serial.begin(9600);
  motorInit();
  ultrasonicInit();
  
}
int turning = 0;
void loop() {
  float dist_front = readDistanceCMF();
  Serial.print("Distance Front: ");
  Serial.print(dist_front);
  Serial.println(" cm");

  float dist_right = readDistanceCMR();
  Serial.print("Distance Right: ");
  Serial.print(dist_right);
  Serial.println(" cm");

  if (turning < 3) {
    if (dist_front > 15) {
      delay(100);
      Serial.print("FORWARD");
      driveForward(1500);
    } else {
      if (dist_right > 15) {
        turning += 1;
        turnRight(150);
        Serial.print("TURN RIGHT!!");
      } else {
        turning += 1;
        turnLeft(150);
        Serial.print("TURN LEFT!!");
      }
    }
  } else {
    driveStop();
  }
  delay(100);
}
