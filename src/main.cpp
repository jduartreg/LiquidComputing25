#include <Arduino.h>
#include "mux.h"
#include "adc.h"

void setup() {
  Serial.begin(115200);
  setup_mux();
  setup_adc();
}

void loop() {
  // mux_sequence_runner();
  delay(10);
  all_mux();
  // loop_adc();
  //all_mux_odd_even();
  //all_mux_ramping();
  // all_mux_nonblocking();
  //loop_compass();
  //pwm_loop();
}
