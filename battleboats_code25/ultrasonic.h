#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define TRIG_PINF 2
#define ECHO_PINF 3
#define TRIG_PINR 8
#define ECHO_PINR 9

void ultrasonicInit();
float readDistanceCMF();
float readDistanceCMR();

#endif
