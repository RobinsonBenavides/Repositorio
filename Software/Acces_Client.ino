#include <WiFi.h>
#include <WebServer.h>
#include <HTTPClient.h>
#include "HX711.h"

HX711 bascula;
const char* ssid = "CDIOIII";
const char* pass = "Contrasena123";
String strReading;
int pin = 22;
bool flag=1;
const int CELDA_DATA_PIN = 19;
const int CELDA_SCK_PIN = 18;



void ConnecttoWifi(){

  WiFi.begin(ssid,pass);
  delay(500);
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  
  while(WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");
  }

   Serial.println(WiFi.localIP()); 


  
}




void setup() {
  Serial.begin(115200);
  bascula.begin(CELDA_DATA_PIN, CELDA_SCK_PIN);
  delay(250);

  bascula.set_scale(1001.19);//Calibración de la celda
  bascula.tare(10);  // Hacer 10 lecturas, el promedio es la tara
  //pinMode(pin,OUTPUT);
  //digitalWrite(pin,HIGH);
  
 

}  
void loop(){

  if (bascula.is_ready())
  {
    float reading = bascula.get_units(10);
    //Serial.println(reading);
    strReading += reading; 
  }
  else
  Serial.println("Celda no encontrada");
  delay(500);

    
  if(flag==1)
  {
   ConnecttoWifi();    
  }
  else
  {
   Serial.print("Error en la conexión"); 
  }

  if(WiFi.status() == WL_CONNECTED)
  {
   HTTPClient http;
   String send_data = "?value=" + strReading;

   http.begin("http://192.168.4.1/"+send_data);
   

   int response = http.GET();

   if(response>0)
   {
    Serial.println("Codigo HTTP" + String(response));

    if(response==200)
    {
     String body_response = http.getString();
     Serial.println("El servidor respondio: ");
     Serial.println(body_response); 
    }

    
   }
   
  }
    

}
