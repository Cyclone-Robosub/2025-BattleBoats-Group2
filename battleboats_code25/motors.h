#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define IN1_PIN 4 // Left Motor
#define IN2_PIN 5 // Left Motor
#define IN3_PIN 6 // Right Motor
#define IN4_PIN 7 // Right Motor
#define ENA_PIN 10   // Pin must support PWM!
#define ENB_PIN 111  // Pin must support PWM!

// ==============================
//         Motor Control
// ==============================
void motorInit();
void driveForward(int speed);
void driveBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void driveStop();

#endif
