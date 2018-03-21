#ifndef joystick_h
#define joystick_h

#include <Arduino.h>

class joystick {
public:
  joystick(int PinX, int PinY, int PinSW);
  int leerX();
  int leerY();
  int leerporX();
  int leerporY();
  int SW();
  void calibrar();
  String Direccion();

private:
  int _PinX;
  int _PinY;
  int _PinSW;
  int x_ini;
  int y_ini;
  int por_x;
  int por_y;
  String dir;
};

#endif
