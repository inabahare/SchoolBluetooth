#include <SoftwareSerial.h>

// Define the bluetooth ports
const int txPin = 9;
const int rxPin = 8;

// Read value from Bluetooth
int bluetoothValue;

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

  // Read from the BLuetooth module
  bluetoothValue = bluetoothSerial.read();

  // Print the Bluetooth value
  Serial.println(bluetoothValue);

  delay(500);
}

