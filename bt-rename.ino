#if 0

#include <SoftwareSerial.h>

// Define TX and RX pins for HC-05
SoftwareSerial mySerial(4, 5); // RX, TX

void setup() {
  const byte vcc = 7, gnd = 6;
  pinMode(vcc, OUTPUT);
  digitalWrite(vcc, HIGH);
  pinMode(gnd, OUTPUT);
  digitalWrite(gnd, LOW);

  Serial.begin(9600);      // Communication with PC
  mySerial.begin(38400);   // Communication with HC-05 (default AT mode baud rate)
  Serial.println("Enter AT commands:");
}

void loop() {
  if (Serial.available()) {          // If data from PC
    mySerial.write(Serial.read());   // Send to HC-05
  }
  if (mySerial.available()) {        // If data from HC-05
    Serial.write(mySerial.read());   // Send to PC
  }
}


#endif