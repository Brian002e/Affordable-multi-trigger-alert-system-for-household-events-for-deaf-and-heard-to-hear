#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  
const byte address[6] = "00001";

const int vibMotorPin = 3;
const int ackButtonPin = 4;

// LEDs
const int doorLedPin = 5;
const int babyLedPin = 6;
const int smokeLedPin = 7;
const int alertLedPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(vibMotorPin, OUTPUT);
  pinMode(ackButtonPin, INPUT_PULLUP);

  pinMode(doorLedPin, OUTPUT);
  pinMode(babyLedPin, OUTPUT);
  pinMode(smokeLedPin, OUTPUT);
  pinMode(alertLedPin, OUTPUT);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void buzzPattern(String type) {
  // Reset LEDs
  digitalWrite(doorLedPin, LOW);
  digitalWrite(babyLedPin, LOW);
  digitalWrite(smokeLedPin, LOW);
  digitalWrite(alertLedPin, LOW);

  if (type == "DOOR") {
    digitalWrite(doorLedPin, HIGH);
    for (int i = 0; i < 2; i++) {
      digitalWrite(vibMotorPin, HIGH);
      delay(150);
      digitalWrite(vibMotorPin, LOW);
      delay(150);
    }
    digitalWrite(doorLedPin, LOW);

  } else if (type == "BABY") {
    digitalWrite(babyLedPin, HIGH);
    for (int i = 0; i < 3; i++) {
      digitalWrite(vibMotorPin, HIGH);
      delay(400);
      digitalWrite(vibMotorPin, LOW);
      delay(200);
    }
    digitalWrite(babyLedPin, LOW);

  } else if (type == "SMOKE") {
    digitalWrite(smokeLedPin, HIGH);
    for (int i = 0; i < 3; i++) {
      digitalWrite(vibMotorPin, HIGH);
      delay(2000);
      digitalWrite(vibMotorPin, LOW);
      delay(500);
      if (digitalRead(ackButtonPin) == LOW) break;
    }
    digitalWrite(smokeLedPin, LOW);

  } else if (type == "ALERT") {
    digitalWrite(alertLedPin, HIGH);
    digitalWrite(vibMotorPin, HIGH);
    delay(300);
    digitalWrite(vibMotorPin, LOW);
    digitalWrite(alertLedPin, LOW);
  }
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.print("Received: ");
    Serial.println(text);

    for (int repeat = 0; repeat < 3; repeat++) {
      if (digitalRead(ackButtonPin) == LOW) {
        Serial.println("Alert acknowledged, stopping vibration.");
        digitalWrite(vibMotorPin, LOW);
        digitalWrite(doorLedPin, LOW);
        digitalWrite(babyLedPin, LOW);
        digitalWrite(smokeLedPin, LOW);
        digitalWrite(alertLedPin, LOW);
        break;
      }
      buzzPattern(String(text));
    }
  }
}
