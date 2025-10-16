#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define TRIG_PIN 2 //2 formly 51
#define ECHO_PIN 3 //3 formly 53

void ultrasonicInit();
float readDistanceCM();

#endif
