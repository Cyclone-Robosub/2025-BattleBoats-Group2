#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define TRIG_PIN 2
#define ECHO_PIN 3 

#define TRIG_PIN2 4
#define ECHO_PIN2 5

void ultrasonicInit();
float readDistanceCM();

#endif
