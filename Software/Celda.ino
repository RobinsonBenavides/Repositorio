#include "HX711.h"
const int CELDA_DATA_PIN = 19;
const int CELDA_SCK_PIN = 18;
HX711 bascula;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  bascula.begin(CELDA_DATA_PIN, CELDA_SCK_PIN);
  delay(250);

  bascula.set_scale(1001.19);//Calibración de la celda
  bascula.tare(10);  // Hacer 10 lecturas, el promedio es la tara

}

void loop() {
  // put your main code here, to run repeatedly:
  if (bascula.is_ready())
  {
    float reading = bascula.get_units(10);
    Serial.println(reading);
  }
  else
  Serial.println("Celda no encontrada");
  delay(500);

}
