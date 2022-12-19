#include <Arduino.h>
// Servo Library
#include <Servo.h>
// Bluetooth library
#include <SoftwareSerial.h>

Servo myservo1, myservo2, myservo3, myservo4, myservo5; // servo name

int bluetoothTx = 7; // bluetooth tx to 10 pin
int bluetoothRx = 8; // bluetooth rx to 11 pin
int pinmyservo1 = 3;
int pinmyservo2 = 5;
int pinmyservo3 = 6;
int pinmyservo4 = 9;
int pinmyservo5 = 10;
int letra;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  // Attach servo signal wire to the software
  myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);
  //Setup usb serial connection to computer
  Serial.begin(9600);
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  if (bluetooth.available() >= 2)
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 * 256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo < 1180)
    {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      myservo1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
    }
    if (realservo >= 2000 && realservo < 2180)
    {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      Serial.println("Servo 2 ON");
      delay(10);
    }
    if (realservo >= 3000 && realservo < 3180)
    {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      myservo3.write(servo3);
      Serial.println("Servo 3 ON");
      delay(10);
    }
    if (realservo >= 4000 && realservo < 4180)
    {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      myservo4.write(servo4);
      Serial.println("Servo 4 ON");
      delay(10);
    }
    if (realservo >= 5000 && realservo < 5180)
    {
      int servo5 = realservo;
      servo5 = map(servo5, 5000, 5180, 0, 180);
      myservo5.write(servo5);
      Serial.println("Servo 5 ON");
      delay(10);
    }
    // if (bluetooth.available() >= 0)
    {
      if (realservo == 0)
      {
        myservo1.write(20);
        myservo2.write(20);
        myservo3.write(20);
        myservo4.write(20);
        myservo5.write(20);
      }

      if (realservo == 1)
      {
        myservo1.write(30);
        myservo2.write(30);
        myservo3.write(30);
        myservo4.write(30);
        myservo5.write(30);
      }
      if (realservo == 2)
      {
        myservo1.write(40);
        myservo2.write(40);
        myservo3.write(40);
        myservo4.write(40);
        myservo5.write(40);
      }
      if (realservo == 3)
      {
        myservo1.write(50);
        myservo2.write(50);
        myservo3.write(50);
        myservo4.write(50);
        myservo5.write(50);
      }
      if (realservo == 4)
      {
        myservo1.write(60);
        myservo2.write(60);
        myservo3.write(60);
        myservo4.write(60);
        myservo5.write(60);
      }
      if (realservo == 5)
      {
        myservo1.write(70);
        myservo2.write(70);
        myservo3.write(70);
        myservo4.write(70);
        myservo5.write(70);
      }
      if (realservo == 6)
      {
        myservo1.write(80);
        myservo2.write(80);
        myservo3.write(80);
        myservo4.write(80);
        myservo5.write(80);
      }
      if (realservo == 7)
      {
        myservo1.write(90);
        myservo2.write(90);
        myservo3.write(90);
        myservo4.write(90);
        myservo5.write(90);
      }
    }
  }
}  
