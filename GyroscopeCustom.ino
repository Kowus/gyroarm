/*

  Gyroscope Shield Example

  This example shows an application on 1Sheeld's gyroscope shield.

  By using this example, you can turn on some LEDs if the
  smartphone's gyroscope sensor moves in any of the x, y
  and z axises.

  OPTIONAL:
  To reduce the library compiled size and limit its memory usage, you
  can specify which shields you want to include in your sketch by
  defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define.

*/

#define CUSTOM_SETTINGS
#define INCLUDE_GYROSCOPE_SENSOR_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>
#include <Servo.h>

Servo hand;
Servo elbow;
Servo shoulder;

int posh = 0, pose = 0, poss = 0, buttonPin = 12;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  hand.attach(9);
  elbow.attach(10);
  shoulder.attach(11);
  pinMode(buttonPin, INPUT);

}

void loop()
{
  /* Check X-axis motion value. */
  if (GyroscopeSensor.getX() > 1)
  {
    if (poss >= 180) {
      poss = 180;
    } else {
      poss += 1;
    }
    shoulder.write(poss);
  }
  else if (GyroscopeSensor.getX() < -1)
  {
    if (poss <= 0) {
      poss = 0;
    } else {
      poss -= 1;
    }
    shoulder.write(poss);
  }

  /* Check Y-axis motion value. */
  else if (GyroscopeSensor.getY() > 1)
  {
    if (pose >= 180) {
      pose = 180;
    } else {
      pose += 1;
    }
    elbow.write(pose);
  }
  else if (GyroscopeSensor.getY() < -1)
  {
    if (pose <= 0) {
      pose = 0;
    } else {
      pose -= 1;
    }
    elbow.write(pose);
  }

  if (digitalRead(buttonPin) == HIGH)
  {
    hand.write(180);
  } else if (digitalRead(buttonPin) == LOW)
  {
    hand.write(90);
  }
}
