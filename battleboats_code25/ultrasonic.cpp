#include "ultrasonic.h"

void ultrasonicInit() {
  // configure ultrasonic pins
  pinMode(TRIG_PINF, OUTPUT);
  pinMode(ECHO_PINF, INPUT);
  pinMode(TRIG_PINR, OUTPUT);
  pinMode(ECHO_PINR, INPUT);
}

float readDistanceCMF() {
  // Set TRIG low 
  digitalWrite(TRIG_PINF, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG_PINF, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINF, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO_PINF, HIGH);

  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;
  return distance;
}

float readDistanceCMR() {
  // Set TRIG low 
  digitalWrite(TRIG_PINR, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG_PINR, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINR, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO_PINR, HIGH);

  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;
  return distance;
}