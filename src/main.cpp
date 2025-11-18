#include <Arduino.h>
#include "mux.h" // Multiplexer for Valves, Pumps, and Motors 1-0 
#include "adc.h" // analog sensors Analog to Digital Converter
#include "i2c.h" // Detect digital I2C devices
#include "pwm.h" // Pulse Width Modulation for Pumps amount of speed control
#include "temperature.h"
#include "bmp.h" // BMP280 Temperature and Pressure Sensor
#include "heartbeat.h"
#include "displayA.h" // OLED Display
#include "touch.h" // MPR121 Capacitive Touch Sensor



void setup() {
  Serial.begin(115200);
  // set_scan();
  setup_bmp();
  // set_disA();
  // setup_touch();

  // setup_mux();
  // setup_heartbeat();
  // setup_pwm();
  // pinMode(7, INPUT);
  // setup_temperature();
  // setup_adc();
  // setup_air();

}

void loop() {
  loop_bmp();
  delay(500);


  // plotValues();
  // displayTouchedChannel();
  // delay(10);

  //scani2c();
  // set_disA();

  // loop_heartbeat();
  // mux_sequence_runner();

  // loop_bmp();
  // printPressure();
  // int x = digitalRead(7);
  // // Serial.print("Analog Read Pin 7: ");
  // // Serial.println(x);
  // if (x == HIGH) {
  //   digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
  // } else {
  //   digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
  // }
  // delay(100);

  // all_mux();
  // ramp();
  // pump_half_speed();
  // delay(100);
  // lfo();
  
  // loop_adc();
  //loop_temperature();
}


void ldr(){
  int sensorValue = analogRead(0); // read the input on analog pin 0
  Serial.print("Analog Read LDR Pin 36: ");
  Serial.println(sensorValue);
  delay(100);
}

