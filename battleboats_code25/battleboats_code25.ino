#include "motors.h"
#include "ultrasonic.h"

void setup() {
  Serial.begin(9600);
  motorInit();
  ultrasonicInit();
}

void loop() {
  float dist = readDistanceCM();
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist > 15) {
    driveForward(150);
  } else {
    driveStop();
    bool turn = interpret();

    if (turn == true) {
      turnRight(15);
    } else {
      turnLeft(15);
    }
  }

  delay(100);
}
