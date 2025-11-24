/**
 * Author Teemu Mäntykallio
 * Initializes the library and runs the stepper
 * motor in alternating directions.
 */

#include <TMCStepper.h>

#define EN_PIN           20 // Enable
#define DIR_PIN          10 // Direction
#define STEP_PIN         7 // Step

// #define CS_PIN           42 // Chip select
// #define SW_MOSI          66 // Software Master Out Slave In (MOSI)
// #define SW_MISO          44 // Software Master In Slave Out (MISO)
// #define SW_SCK           64 // Software Slave Clock (SCK)
// #define SW_RX            63 // TMC2208/TMC2224 SoftwareSerial receive pin
// #define SW_TX            40 // TMC2208/TMC2224 SoftwareSerial transmit pin
// #define SERIAL_PORT Serial1 // TMC2208/TMC2224 HardwareSerial port
// #define DRIVER_ADDRESS 0b00 // TMC2209 Driver address according to MS1 and MS2

// #define R_SENSE 0.11f // Match to your driver
//                       // SilentStepStick series use 0.11
//                       // UltiMachine Einsy and Archim2 boards use 0.2
//                       // Panucatt BSD2660 uses 0.1
//                       // Watterott TMC5160 uses 0.075

// // Select your stepper driver type
// //TMC2130Stepper driver(CS_PIN, R_SENSE);                           // Hardware SPI
// //TMC2130Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK); // Software SPI
// //TMC2660Stepper driver(CS_PIN, R_SENSE);                           // Hardware SPI
// //TMC2660Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);
// //TMC5160Stepper driver(CS_PIN, R_SENSE);
// //TMC5160Stepper driver(CS_PIN, R_SENSE, SW_MOSI, SW_MISO, SW_SCK);

// TMC2208Stepper driver(&SERIAL_PORT, R_SENSE);                     // Hardware Serial
// //TMC2208Stepper driver(SW_RX, SW_TX, R_SENSE);                     // Software serial
// //TMC2209Stepper driver(&SERIAL_PORT, R_SENSE, DRIVER_ADDRESS);
// //TMC2209Stepper driver(SW_RX, SW_TX, R_SENSE, DRIVER_ADDRESS);

void setup_stepper() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW);     // enable driver
  digitalWrite(DIR_PIN, LOW);    // direction
}

void loop_stepper() {

  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(2000);       // adjust for speed
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(2000);
}
