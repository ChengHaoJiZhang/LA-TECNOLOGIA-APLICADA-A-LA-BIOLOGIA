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
    unsigned int realservo = (servopos1 * 256);
    Serial.println(realservo);
    Serial.println(servopos1);
    Serial.println(servopos);
  }
}  

