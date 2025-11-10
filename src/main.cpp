#include <Arduino.h>
#include "mux.h"
#include "adc.h"
#include "i2c.h"
#include "pwm.h"

#define LED_BUILTIN 8

void setup() {
  Serial.begin(115200);
  setup_pwm();
  setup_mux();

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

}

void loop() {

  mux_sequence_runner();
  
}
