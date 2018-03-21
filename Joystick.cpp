#include <Arduino.h>
#include <joystick.h>

joystick::joystick(int PinX, int PinY, int PinSW){
  _PinX = PinX;
  _PinY = PinY;
  _PinSW = PinSW;
  pinMode(_PinSW, INPUT);
  digitalWrite(_PinSW, HIGH);
}

int joystick::leerX (){
  int X = analogRead(_PinX);
  return(X);
}

int joystick::leerY (){
  int Y = analogRead(_PinY);
  return(Y);
}

int joystick::leerporX (){

  int X = leerX();
  if (X > x_ini){
    por_x = ((X-x_ini)/(1023.0-x_ini))*100.0;
    return(por_x);
  }
  else if (X < x_ini){
    por_x = -100.0+((X*100.0)/x_ini);
    return(por_x);
  }
  else if (X == x_ini){
    por_x = 0;
    return(por_x);
  }
}

int joystick::leerporY (){

  int Y = leerY();
  if (Y > y_ini){
    por_y = ((Y-y_ini)/(1023.0-y_ini))*100.0;
    return(por_y);
  }
  else if (Y < y_ini){
    por_y = -100.0+((Y*100.0)/y_ini);
    return(por_y);
  }
  else if (Y == y_ini){
    por_y = 0;
    return(por_y);
  }
}

int joystick::SW (){
  if (digitalRead(_PinSW) == HIGH){
    return(0);
  }
  else {
    return(1);
  }
}

String joystick::Direccion(){
  int X = leerporX();
  int Y = leerporY();
  dir = "";
  if (X > 0){
    dir = "-Adelante";
  }
  else if (X < 0){
    dir = "-Atras";
  }
  if (Y > 0){
    dir = dir + "-Derecha";
  }
  else if (Y < 0){
    dir = dir + "-Izquierda";
  }
  if (X == 0 && Y == 0){
    dir = "Neutro";
  }
  return(dir);
}

void joystick::calibrar (){
  Serial.println("Dejar joystick en estado de reposo");
  delay(3000);
  x_ini = leerX();
  y_ini = leerY();
  Serial.println("Joystick calibrado");
}
