

#include "regularMotor.h"
RegularMotor motor(5,18,19);
int giro=0,vel=0;
void setup() {
  Serial.begin (9600);
  motor.conf();
  motor.velGiro(255);
  motor.dirGiro(ATRAS);
  motor.estadoMotor(false);
  vel=motor.getVelgiro();
  giro=motor.getDirgiro();
  Serial.print("giro:");
  Serial.println(giro);
  Serial.print("velocidad:");
  Serial.println(vel);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
