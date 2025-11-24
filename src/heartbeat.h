#pragma once
#include <Arduino.h>

const int HEART_PIN = 7;       // your digital pulse pin (D0 from sensor)
//extern int g_common_output;    // defined elsewhere

// For detecting rising edges
static bool prevState = LOW;

void setup_heartbeat() {
    pinMode(HEART_PIN, INPUT);
}

void loop_heartbeat() {
    bool state = digitalRead(HEART_PIN);

    // detect a rising edge: LOW → HIGH
    if (state == HIGH && prevState == LOW) {
        Serial.println("Beat");

        // trigger output for debugging or pulse-driving
        digitalWrite(g_common_output, HIGH);
        delay(30); // short pulse width (30–50 ms usually enough)
        digitalWrite(g_common_output, LOW);
    }

    prevState = state;

    // small delay to reduce bounce and CPU noise
    delay(5);
}