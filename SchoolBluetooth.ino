#include <SoftwareSerial.h>

// Define the bluetooth ports
const int txPin = 9;
const int rxPin = 8;

// Pins to write to
const int greenLed  = 11;
const int yellowLed = 12;
const int redLed    = 13;

// Read value from Bluetooth
char bluetoothValue;

// Toggle states
int greenState  = 0;
int yellowState = 0;
int redState    = 0;

// Define the bluetooth serial
// (For connecting to the HC-05)
SoftwareSerial bluetoothSerial(rxPin, txPin);

void setup() {

  // Debugging
  Serial.begin(38400);

  while (!Serial) {
    ;  
  }


  // Define baud rate for the bluetooth connection
  bluetoothSerial.begin(38400);
  
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

  bluetoothSerial.print("AT+NAME=BBBBB\r\n");
  delay(1000);
  while (bluetoothSerial.available()) {
    Serial.write(bluetoothSerial.read());
  }

  // Pinmodes 
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}


void loop() {

  if (bluetoothSerial.available())
    Serial.println(bluetoothSerial.readString());

  if (Serial.available())
    bluetoothSerial.println(Serial.readString());

  // Read from the BLuetooth module
  bluetoothValue = bluetoothSerial.read();

  // Print the Bluetooth value
  Serial.println(bluetoothValue);
 
  if (bluetoothValue == 'a') {
    yellowState = !yellowState;
    digitalWrite(yellowLed, yellowState);
  }

  digitalWrite(yellowLed, HIGH);

  delay(500);
}

