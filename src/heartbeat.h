#include <Arduino.h>

#define HEARTBEAT_PIN 20

unsigned long lastBeat = 0;
unsigned long ibi = 600;  // ms between beats (default)
int bpm = 0;

bool prevState = LOW;

void setup_heartbeat() {
    pinMode(HEARTBEAT_PIN, INPUT);
}

void loop_heartbeat() {
    bool state = digitalRead(HEARTBEAT_PIN);
    output_mux.channel(1);

    if (state == HIGH && prevState == LOW) {
        unsigned long now = millis();
        unsigned long interval = now - lastBeat;

        if (interval > 250 && interval < 2000) {
            all_mux();
            ibi = interval;
            bpm = 60000 / ibi;

            // Serial.print("Beat detected — BPM: ");
            // Serial.print(bpm);
            // Serial.print("   IBI: ");
            // Serial.println(ibi);
        }

        lastBeat = now;
    }
    

    prevState = state;
    digitalWrite(g_common_output, LOW);

    
}