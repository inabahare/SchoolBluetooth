#include <SoftwareSerial.h>

// Define the bluetooth ports
const int txPin = 6;
const int rxPin = 5;

// Pins to write to
const int greenLed  = 11;
const int yellowLed = 13;
const int redLed    = 13;

// Values for the leds
const int greenValue  = 97; // = a
const int yellowValue = 98; // = b 
const int redValue    = 99; // = c

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
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);

}


void loop() {

  // Read from the BLuetooth module
  bluetoothValue = bluetoothSerial.read();

  // Print the Bluetooth value
  Serial.println(bluetoothValue);

  // The LEDs
  toggleLed(greenValue, greenLed);
  toggleLed(yellowValue, yellowLed);
  toggleLed(redValue, redLed);

  // This is to make sure that the toggle isn't repeated
  previousBluetoothValue = bluetoothValue;
  
  delay(100);
}

/* 
*   Toggles the LED
*   
*   Value to toggle the LED with
*   Pin the LED is connected to
*/
void toggleLed(int ledValue, int ledPin){
  if (bluetoothValue == ledValue && bluetoothValue != previousBluetoothValue){
      digitalWrite(ledPin, !digitalRead(ledPin));
  }
}
