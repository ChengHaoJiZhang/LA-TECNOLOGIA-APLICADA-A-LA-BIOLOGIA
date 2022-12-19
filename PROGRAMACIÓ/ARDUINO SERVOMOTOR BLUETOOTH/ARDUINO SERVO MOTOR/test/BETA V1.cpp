#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo1, myservo2, myservo3, myservo4, myservo5;
int bluetoothTX = 7;
int bluetoothRX = 8;
int servo = 9;
char letra;
SoftwareSerial bluetooth(bluetoothTX, bluetoothRX);

void setup()
{
  Serial.begin(9600);
  myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);
  bluetooth.begin(9600);
}

void loop()
{
  if (bluetooth.available() > 0)
  {
    letra = bluetooth.read();
    Serial.println(letra);

    if (letra == '0')
    {
      Serial.println("0 graus");
      myservo1.write(0);
    }
    if (letra == '1')
    {
      Serial.println("30 grados");
      myservo1.write(30);
    }
    if (letra == '2')
    {
      Serial.println("60 grados");
      myservo1.write(60);
    }
    if (letra == '3')
    {
      Serial.println("90 grados");
      myservo1.write(90);
    }
    if (letra == '4')
    {
      Serial.println("120 grados");
      myservo1.write(120);
    }
    if (letra == '5')
    {
      Serial.println("150 grados");
      myservo1.write(150);
    }
    if (letra == '6')
    {
      Serial.println("180 grados");
      myservo1.write(180);
    }
    if (letra == '7')
    {
      Serial.println("180 grados");
      myservo1.write(14);
    }
  }
}
