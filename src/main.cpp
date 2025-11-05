#include <Arduino.h>
#include "mux.h"
#include "adc.h"

#define LED_BUILTIN 8

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int x = analogRead(A0);
  Serial.printf("Analog read A0: %d\n", x);
  delay(250);
  if(x < 1000){
    digitalWrite(LED_BUILTIN, LOW);  
  } else{
    digitalWrite(LED_BUILTIN, HIGH);  
  }
}
