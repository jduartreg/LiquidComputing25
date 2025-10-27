#include <Arduino.h>
#include "mux.h"
#include "compass.h"
#include "adc.h"


void setup() {
  Serial.begin(115200);
  // setup_compass();
  // setup_mux();
  setup_adc();
}


void loop() {
  loop_adc();
  all_mux();
  //all_mux_odd_even();
  //all_mux_ramping();
  // all_mux_nonblocking();
  //loop_compass();
  //pwm_loop();
}