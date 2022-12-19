#include <Arduino.h>
// Include Servo Library
#include <Servo.h>
// Include Bluetooth library
#include <SoftwareSerial.h>

Servo myservo1, myservo2, myservo3, myservo4, myservo5; // Create different Servo's variables.

int bluetoothTx = 7; // Assign bluetoothTx to Digital Pin 7.
int bluetoothRx = 8; // Assign bluetoothRx to Digital Pin 8.
int letra;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx); // Create different SoftwareSerial's variables.

void setup()
{
  // Attach servo signal wire to the software / Determine in which pin is every servo connected.
  myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);
  //Setup usb serial connection to computer (BautRate)
  Serial.begin(9600);
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

// 0 DEGREE = FINGERS CLOSED & 180 DEGREES = FINGERS OPEN
// servo1 = polze, servo2 = índex, servo3 = cor, servo4 = anular i servo5 = menovell

void loop()
{
  if (bluetooth.available() >= 2) // The line tests if the number of bytes currently in the serial buffer is greater than 2. When I programmed the app, the commands always send a 2-byte number.
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

    if (realservo == 0) // If what the app sends is 0, OPEN THE HAND, this type of expression (IF) is a conditional. Only the commands inside the brackets "{}" will be executed if the condition written inside the parentheses "()" next to the expression "if" is met. Si el que envia l'app és un 0, OBRE LA MÀ, aquest tipus d'expressió (IF) és condicional. Només s'executarà el que està dintre dels claudàtors "{}" si és compleix el que està dintre dels parèntesis "()" al costat de l'expressió "if",
    {
      myservo1.write(180); // If what is inside the parentheses is met, send the degrees (180) to the servomotor that is connected to pin number 3. // Si es compleix el que està dintre del parèntesis, envia els graus (180) al servomotor que està conectat al pin número 3.
      myservo2.write(180);
      myservo3.write(180);
      myservo4.write(180);
      myservo5.write(180);
    }

    if (realservo == 1) // If the app sends 1, CLOSE THE HAND. Si el que envia l'app és un 6, TANCA LA MÀ
    {
      myservo1.write(0);
      myservo2.write(0);
      myservo3.write(0);
      myservo4.write(0);
      myservo5.write(0);
    }
    if (realservo == 2) // If the app sends 2, 2 FINGERS. Si el que envia l'app és un 2, 2 DITS
    {
      myservo1.write(180);
      myservo2.write(180);
      myservo3.write(0);
      myservo4.write(0);
      myservo5.write(0);
    }
    if (realservo == 3) // If the app sends 3, 3 FINGERS. Si el que envia l'app és un 3, 3 DITS
    {
      myservo1.write(180);
      myservo2.write(180);
      myservo3.write(180);
      myservo4.write(0);
      myservo5.write(0);
    }
    if (realservo == 4) // If the app sends  4, 4 FINGERS. Si el que envia l'app és un 4, 4 DITS
    {
      myservo1.write(0);
      myservo2.write(180);
      myservo3.write(180);
      myservo4.write(180);
      myservo5.write(180);
    }
    if (realservo == 5) // If the app sends 5, 1 FINGER. Si el que envia l'app és un 5, 1 DIT
    {
      myservo1.write(180);
      myservo2.write(0);
      myservo3.write(0);
      myservo4.write(0);
      myservo5.write(0);
    }
    if (realservo == 6) // If the app sends 6, COUNTDOWN. Si el que envia l'app és un 6, COMPTE ENRERE
    {
      myservo1.write(180);
      myservo2.write(180);
      myservo3.write(180);
      myservo4.write(180);
      myservo5.write(180);
      delay(1000);
      myservo1.write(0);
      delay(1000); // Wait 1000ms before the next command is executed. Espera 1000 ms (mil·lisegons) abans de que comenci l'ordre a continuació
      myservo2.write(0);
      delay(1000);
      myservo3.write(0);
      delay(1000);
      myservo4.write(0);
      delay(1000);
      myservo5.write(0);
    }
    if (realservo == 7) // If the app sends 7, COUNT UP. Si el que envia l'app és un 7, COMPTE PROGRESSIU
    {
      myservo1.write(0);
      myservo2.write(0);
      myservo3.write(0);
      myservo4.write(0);
      myservo5.write(0);
      delay(1000);
      myservo1.write(180);
      delay(1000);
      myservo2.write(180);
      delay(1000);
      myservo3.write(180);
      delay(1000);
      myservo4.write(180);
      delay(1000);
      myservo5.write(180);
    }
  }
}
