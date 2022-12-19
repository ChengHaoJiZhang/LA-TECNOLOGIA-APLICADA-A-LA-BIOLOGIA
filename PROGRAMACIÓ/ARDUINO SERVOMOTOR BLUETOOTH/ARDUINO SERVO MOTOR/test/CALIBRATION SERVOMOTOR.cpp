#include <Arduino.h>
#include <Servo.h>

Servo pulgar;
Servo index;
Servo cor;
Servo anular;
Servo menovell;

int pinpulgar = 3;
int pinindex = 5;
int pincor = 6;
int pinanular = 9;
int pinmenovell = 10;

void setup()
{
  pulgar.attach(3);
  index.attach(5);
  cor.attach(6);
  anular.attach(9);
  menovell.attach(10);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:

  //Simple code
  index.write(180);
  cor.write(180);
  anular.write(180);
  menovell.write(180);
  pulgar.write(180);

  // //Coordinated code
  //   pulgar.write(90);
  //   delay(100);
  //   index.write(90);
  //   cor.write(90);
  //   delay(100);
  //   anular.write(90);
  //   menovell.write(90);
  //   delay(1000);
  //   pulgar.write(10);
  //   delay(100);
  //   index.write(10);
  //   cor.write(10);
  //   delay(100);
  //   anular.write(10);
  //   menovell.write(10);
  //   delay(1000);

  //   pulgar.write(90);
  //   index.write(90);
  //   cor.write(90);
  //   anular.write(90);
  //   menovell.write(90);
  //   delay(1000);
  //   pulgar.write(10);
  //   index.write(10);
  //   cor.write(10);
  //   anular.write(10);
  //   menovell.write(10);
  //   delay(1000);
}