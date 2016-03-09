#include <SoftwareSerial.h>

// Define the bluetooth ports
const int txPin = 9;
const int rxPin = 8;


// Define the bluetooth serial
// (For connecting to the HC-05)
SoftwareSerial bluetoothSerial(rxPin, txPin);

void setup() {

  // Debugging
  Serial.begin(9600);

  // Define baud rate for the bluetooth connection
  bluetoothSerial.begin(9600);

}

void loop() {

  Serial.println( bluetoothSerial.read() );

  delay(500);
}

