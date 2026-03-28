#include <Arduino.h>
#include <Servo.h>

#define servoPin 6
#define rainPin 7

Servo curtain;

bool isRaining = false;

void setup() {
  Serial.begin(9600);
  pinMode(rainPin, INPUT);
  curtain.attach(servoPin);
  curtain.write(0);
}

void loop() {
  int state = digitalRead(rainPin);

  if (state == LOW && !isRaining) {
    Serial.println("Co mua => Dong rem");
    curtain.write(90);
    isRaining = true;
    delay(2000);
  }

  if (state == HIGH && isRaining) {
    Serial.println("Kho => Mo rem");
    curtain.write(0);
    isRaining = false;
    delay(2000);
  }

  delay(200);
}