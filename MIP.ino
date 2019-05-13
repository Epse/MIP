#include <Arduino.h>
#include <Servo.h>

#define MAGNET_PIN A0

#define BRAKE_PIN 10
#define BRAKE_OPEN 5
#define BRAKE_CLOSE 50
#define CATAPULT_PIN 5
#define CATAPULT_LOCK 90
#define CATAPULT_RELEASE 5
#define CATAPULT_TIME 3000

// in ms
#define STOP_DELAY 10
#define REVERSE_DELAY 500

#define ROTATIONS 4
byte rotations = ROTATIONS;

long timeStart;

bool registeredRotation = false;
bool forwards = true;
bool done = false;

Servo brake;
Servo catapult;

void setup() {
  // put your setup code here, to run once:
  pinMode(BRAKE_PIN, OUTPUT);
  pinMode(CATAPULT_PIN, OUTPUT);
  pinMode(MAGNET_PIN, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  brake.attach(BRAKE_PIN);
  catapult.attach(CATAPULT_PIN);
  brake.write(BRAKE_CLOSE);
  catapult.write(CATAPULT_LOCK);
  delay(20);
  // Wait 3 seconds
  delay(3000);
  brake.write(BRAKE_OPEN);
  timeStart = millis();
  delay(20);
}

void loop() {
  if (done) {
    return;
  }

  if (millis() - timeStart >= CATAPULT_TIME) {
    catapult.write(CATAPULT_RELEASE);
    delay(10);
  }

}
