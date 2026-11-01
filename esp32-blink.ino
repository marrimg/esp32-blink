#include <ESP32Servo.h>

Servo blinkServo;
Servo attitudeServo;

const int BLINK_SERVO_PIN = 12;
const int ATTITUDE_SERVO_PIN = 13;

const int BLINK_OPEN_ANGLE = 0;
const int BLINK_CLOSED_ANGLE = 180;

const int ATTITUDE_MIN_ANGLE = 10;
const int ATTITUDE_MAX_ANGLE = 90;

unsigned long previousBlinkTime = 0;
unsigned long previousAttitudeChangeTime = 0;
long blinkInterval = 3000;
long attitudeChangeInterval = 3000;

void setup()
{
  blinkServo.attach(BLINK_SERVO_PIN);
  blinkServo.write(BLINK_OPEN_ANGLE);
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
    blinkServo.write(BLINK_CLOSED_ANGLE);
    delay(500);

    blinkServo.write(BLINK_OPEN_ANGLE);

    blinkInterval = random(3000, 8000);

    previousBlinkTime = currentTime;
  }

  if (currentTime - previousAttitudeChangeTime >= attitudeChangeInterval)
  {

    int attitudeAngle = random(ATTITUDE_MIN_ANGLE, ATTITUDE_MAX_ANGLE);
    attitudeServo.write(attitudeAngle);

    attitudeChangeInterval = random(3000, 8000);

    previousAttitudeChangeTime = currentTime;
  }
}
