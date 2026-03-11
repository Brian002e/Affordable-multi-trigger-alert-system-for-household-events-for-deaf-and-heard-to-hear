#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  
const byte address[6] = "00001";

// Sensor pins
const int doorSensorPin = 2;     
const int babySensorPin = 3;     
const int smokeSensorPin = A0;   
const int alertButtonPin = 4;    

void setup() {
  Serial.begin(9600);

  pinMode(doorSensorPin, INPUT_PULLUP);
  pinMode(babySensorPin, INPUT_PULLUP);
  pinMode(alertButtonPin, INPUT_PULLUP);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();  // Transmitter mode
}

void loop() {
  if (digitalRead(doorSensorPin) == LOW) {
    const char text[] = "DOOR";
    radio.write(&text, sizeof(text));
    Serial.println("Sent: DOOR");
  }

  if (digitalRead(babySensorPin) == LOW) {
    const char text[] = "BABY";
    radio.write(&text, sizeof(text));
    Serial.println("Sent: BABY");
  }

  int smokeValue = analogRead(smokeSensorPin);
  if (smokeValue > 400) {
    const char text[] = "SMOKE";
    radio.write(&text, sizeof(text));
    Serial.print("Sent: SMOKE, value=");
    Serial.println(smokeValue);
  }

  if (digitalRead(alertButtonPin) == LOW) {
    const char text[] = "ALERT";
    radio.write(&text, sizeof(text));
    Serial.println("Sent: ALERT");
  }
}
