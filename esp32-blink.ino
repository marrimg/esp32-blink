#include <ESP32Servo.h>

Servo blinkServo;
Servo attitudeServo;

// PROJECT SETTINGS - OK TO EDIT
const int BLINK_SERVO_PIN = 12;
const int ATTITUDE_SERVO_PIN = 13;

const int BLINK_MIN_ANGLE = 0;
const int BLINK_MAX_ANGLE = 160;

const int BLINK_DELAY = 200;

const int BLINK_MIN_VALUE = 1000;
const int BLINK_MAX_VALUE = 12000;

const int ATTITUDE_MIN_ANGLE = 10;
const int ATTITUDE_MAX_ANGLE = 90;

const int ATTITUDE_MIN_VALUE = 3000;
const int ATTITUDE_MAX_VALUE = 8000;
//

unsigned long previousBlinkTime = 0;
unsigned long previousAttitudeChangeTime = 0;
long blinkInterval = 3000;
long attitudeChangeInterval = 3000;

void setup()
{
  blinkServo.attach(BLINK_SERVO_PIN);
  blinkServo.write(BLINK_MIN_ANGLE);
  randomSeed(analogRead(0));
  previousBlinkTime = millis();

  attitudeServo.attach(ATTITUDE_SERVO_PIN);
  attitudeServo.write(ATTITUDE_MIN_ANGLE);
  previousAttitudeChangeTime = millis();
}

void loop()
{
  unsigned long currentTime = millis();

  if (currentTime - previousBlinkTime >= blinkInterval)
  {
    blinkServo.write(BLINK_MAX_ANGLE);
    delay(BLINK_DELAY);

    blinkServo.write(BLINK_MIN_ANGLE);

    blinkInterval = random(BLINK_MIN_VALUE, BLINK_MAX_VALUE);

    previousBlinkTime = currentTime;
  }

  if (currentTime - previousAttitudeChangeTime >= attitudeChangeInterval)
  {

    int attitudeAngle = random(ATTITUDE_MIN_ANGLE, ATTITUDE_MAX_ANGLE);
    attitudeServo.write(attitudeAngle);

    attitudeChangeInterval = random(ATTITUDE_MIN_VALUE, ATTITUDE_MAX_VALUE);

    previousAttitudeChangeTime = currentTime;
  }
}
