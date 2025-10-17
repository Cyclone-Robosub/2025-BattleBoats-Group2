#include "ultrasonic.h"

void ultrasonicInit() {
  // configure ultrasonic pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
}

//only use below when front senses something
bool interpret() {
  bool right = false;
  if(readDistanceLeft() <= 15) {
    bool right = true; // turn right
  }
  else {
    bool right = false; // turn left
  }
  return bool right;
}

float readDistanceLeft() {
   // Set TRIG low 
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO_PIN2, HIGH);

  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;
  return distance;
}

float readDistanceCM() {
  // Set TRIG low 
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO_PIN, HIGH);

  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;
  return distance;
}
