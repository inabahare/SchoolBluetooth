#include <SoftwareSerial.h>

// Define the bluetooth ports
const int txPin = 6;
const int rxPin = 5;

// Pins to write to
const int greenLed  = 11;
const int yellowLed = 12;
const int redLed    = 13;

// Values for the leds
const int greenValue  = 97; // = a
const int yellowValue = 98; // = b 
const int greenLed    = 99; // = c

// Read value from Bluetooth
int bluetoothValue;
int previousBluetoothValue;

// Define the bluetooth serial
// (For connecting to the HC-05)
SoftwareSerial bluetoothSerial(rxPin, txPin);

void setup() {

  // Debugging
  Serial.begin(9600);

  // Define baud rate for the bluetooth connection
  bluetoothSerial.begin(9600);

  pinMode(greenLed, OUTPUT);

}


void loop() {

  // Read from the BLuetooth module
  bluetoothValue = bluetoothSerial.read();

  // Print the Bluetooth value
  Serial.println(bluetoothValue);
 
  sendLed(97, greenLed);

  // This is to make sure that the toggle isn't repeated
  previousBluetoothValue = bluetoothValue;
  
  delay(100);
}

void sendLed(int ledValue, int led){
  if (bluetoothValue == ledValue && bluetoothValue != previousBluetoothValue){
      digitalWrite(led, !digitalRead(led);
      delay(500);
  }
}
