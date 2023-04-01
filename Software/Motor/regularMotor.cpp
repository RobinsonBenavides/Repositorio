#include "regularmotor.h"
//#include "Arduino.h"
#include <analogWrite.h>
RegularMotor::RegularMotor(uint8_t pinv , uint8_t ping1,uint8_t ping2)
  {
  estadoMotor(estado);
  pin_velocidad=pinv;
  pin_giro1=ping1;
  pin_giro2=ping2;
  }

RegularMotor::~RegularMotor(){
  if( pin_giro1 >= 0 ) pinMode(pin_giro1,INPUT);
  if( pin_giro2 >= 0) pinMode(pin_giro2,INPUT);
  if( pin_velocidad >= 0) pinMode(pin_velocidad,INPUT);
}

void RegularMotor::conf(void){
  pinMode(pin_giro1,OUTPUT);
  pinMode(pin_giro2,OUTPUT);
  pinMode(pin_velocidad,OUTPUT);

  digitalWrite(pin_giro1,LOW);
  digitalWrite(pin_giro2,LOW);
  analogWrite(pin_velocidad,0);
}

void RegularMotor::dirGiro(uint8_t c1){
 if((c1 == 1) || (c1 == 2)){
  direccion=c1;
  switch(c1){
      
    case ADELANTE:
          digitalWrite(pin_giro1,HIGH);
          digitalWrite(pin_giro2,LOW);
          
    break;
    case ATRAS:
          digitalWrite(pin_giro2,HIGH);
          digitalWrite(pin_giro1,LOW);
          
    break;
    }
}
 
}

void RegularMotor::velGiro(uint8_t vel){
  velocidad = vel;
  if(estado==true){
    analogWrite(pin_velocidad,velocidad);
  }
}

void RegularMotor::estadoMotor(bool n){
    estado=n;
   if(n==false){
    analogWrite(pin_velocidad,0);
    }else if(n==true){analogWrite(pin_velocidad,velocidad);}
}
