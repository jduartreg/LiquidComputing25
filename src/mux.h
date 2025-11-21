#include <CD74HC4067.h>
#include <stdbool.h>
extern unsigned long ibi;
bool heartbeatPulseState = false;
#define pin1 0 //configuration of multiplexer pins
#define pin2 1 
#define pin3 2 
#define pin4 3 
#define pin5 21 //common output pin
const int g_common_output = pin5;


CD74HC4067 output_mux(pin1,pin2,pin3,pin4);
int incomingByte = 0; // for incoming serial data

void setup_mux() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT); 
  pinMode(pin5, OUTPUT);
  digitalWrite(g_common_output, LOW);
  delay(1000);
  Serial.println("ESP32-C3 MUX test");
}

void all_mux(){
   digitalWrite(g_common_output, HIGH);
    for (int i = 0; i < 4; i++) { //16 max
        output_mux.channel(i);
        delay(100);
    }
    delay(250);
   digitalWrite(g_common_output, LOW);
    for (int i = 0; i < 4; i++) {
        output_mux.channel(i);
        delay(100);
    }
    delay(250);
}

struct OutputAction {
  int channel;             // 0–15 or however many channels you use
  unsigned long duration;  // milliseconds
  const char* name;        // optional label
};

OutputAction sequence[] = { // Here you create a sequence
  {0, 1000, "12V-1"},   
  {0, 0, "heartbeat-sync"}, // duration will be replaced by ibi dynamically
  {-1, 1000, "pause"}, // pinNumber, ms miliseconds, label   
};


// OutputAction sequence[] = { // Here you create a sequence
//   {2, 250, "valve1"},   
//   {-1, 1000, "pause"}, // pinNumber, ms miliseconds, label  
//   {12, 150, "airpump"},   
//   {-1, 1000, "pause"},  
//   {2, 150, "valve1"},
//   {-1, 1000, "pause"},   
// };

const int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);

int currentStep = 0;
bool stepActive = false;
unsigned long stepStartTime = 0;

void mux_sequence_runner() {
  unsigned long now = millis();

  if (!stepActive) {
      OutputAction &action = sequence[currentStep];

      if (strcmp(action.name, "heartbeat-sync") == 0) {
          if (heartbeatPulseState) {
              output_mux.channel(action.channel);
              digitalWrite(g_common_output, HIGH);
              Serial.println("Heartbeat pulse ON");
          } else {
              digitalWrite(g_common_output, LOW);
              Serial.println("Heartbeat pulse OFF");
          }
          stepStartTime = now;
          stepActive = true;
          return;
      }

      if (action.channel >= 0) {
          output_mux.channel(action.channel);
          digitalWrite(g_common_output, HIGH);
          Serial.printf("Starting %s (channel %d) for %lu ms\n",
                        action.name, action.channel, action.duration);
      } else {
          digitalWrite(g_common_output, LOW);
          Serial.printf("Pausing for %lu ms\n", action.duration);
      }

      stepStartTime = now;
      stepActive = true;
  }

  if (strcmp(sequence[currentStep].name, "heartbeat-sync") == 0) {
      if (!heartbeatPulseState) {
          digitalWrite(g_common_output, LOW);
          stepActive = false;
          currentStep++;
      }
      return;
  }

  unsigned long effectiveDuration = sequence[currentStep].duration;

  if (stepActive && now - stepStartTime >= effectiveDuration) {
    // End this step
    digitalWrite(g_common_output, LOW);
    stepActive = false;
    currentStep++;

    if (currentStep >= sequenceLength) {
      // sequence done, reset or stop
      currentStep = 0; // repeat sequence
      Serial.println("Sequence complete, restarting...");
    }
  }
}


void mux_test(){

}