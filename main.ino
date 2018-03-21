#include <Arduino.h>
#include <joystick.h>

//Pines
int pinX = A0;
int pinY = A1;
int pinSW = 2;

//Variables
int valX = 0;
int valY = 0;
int valSW = 0;
int porX = 0;
int porY = 0;
String dir = "";

//Definir objeto
joystick Joy = joystick(pinX, pinY, pinSW);

void setup() {
  Serial.begin(19200);
  delay(500);
  Joy.calibrar();
}

void loop() {

  valX = Joy.leerX();
  porX = Joy.leerporX();
  Serial.println(valX);
  Serial.println(porX);

  valY = Joy.leerY();
  porY = Joy.leerporY();
  Serial.println(valY);
  Serial.println(porY);

  valSW = Joy.SW();
  Serial.println(valSW);

  dir = Joy.Direccion();
  Serial.println(dir);

  delay(2000);

}
