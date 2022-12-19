#include <Arduino.h>
// Servo Library
#include <Servo.h>
// Bluetooth library
#include <SoftwareSerial.h>

Servo pulgar;
Servo index;
Servo cor;
Servo anular;
Servo menovell;

int pinpulgar = 2;
int pinindex = 3;
int pincor = 4;
int pinanular = 5;
int pinmenovell = 6;
int bluetoothTx = 10; // bluetooth Tx to 10 pin
int bluetoothRx = 11; // bluetooth Rx to 11 pin
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  pulgar.attach(2);
  index.attach(3);
  cor.attach(4);
  anular.attach(5);
  menovell.attach(6);
  //Setup usb serial connection to computer
  Serial.begin(9600);
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  // Put your main code here, to run repeatedly:

  // TEST 1

  index.write(30);
  cor.write(30);
  anular.write(30);
  menovell.write(30);
  pulgar.write(30);


  // TEST 2

  pulgar.write(90);
  delay(100);
  index.write(90);
  cor.write(90);
  delay(100);
  anular.write(90);
  menovell.write(90);
  delay(1000);
  pulgar.write(10);
  delay(100);
  index.write(10);
  cor.write(10);
  delay(100);
  anular.write(10);
  menovell.write(10);
  delay(1000);

  // TEST 3

  pulgar.write(90);
  index.write(90);
  cor.write(90);
  anular.write(90);
  menovell.write(90);
  delay(1000);
  pulgar.write(10);
  index.write(10);
  cor.write(10);
  anular.write(10);
  menovell.write(10);
  delay(1000);
}