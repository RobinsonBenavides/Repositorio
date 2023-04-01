#ifndef REGULARMOTOR_H
#define REGULARMOTOR_H
#include "Arduino.h"

#define ADELANTE  1
#define ATRAS     2

class RegularMotor{

  public:
    RegularMotor(uint8_t pinv , uint8_t ping1,uint8_t ping2);/*constructor*/
    
    void conf(void);
    void dirGiro(uint8_t c1);/*configurar valor dentro de la funcion*/
    void velGiro(uint8_t vel);
    void estadoMotor(bool n);

    uint8_t getDirgiro(void) const {return direccion;};
    uint8_t getVelgiro(void) const {return velocidad;};
    
    ~RegularMotor();/*destructor*/

  protected:
  uint8_t pin_velocidad;
  uint8_t pin_giro1;
  uint8_t pin_giro2;
  bool estado;
  uint8_t direccion;
  uint8_t velocidad;
};

#endif
