#include <WiFi.h>
#include <WebServer.h>
#include <WiFiClient.h>

const char* ssid = "CDIOIII";
const char* pass = "Contrasena123";


//IP Local
IPAddress ip(192,168,4,2);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

WiFiClient cliente;
WebServer  server1(80);



int clienteax;

void setup() {
 Serial.begin(115200);
 

 WiFi.softAP(ssid,pass);



 Serial.println(WiFi.softAPIP());
 Serial.println("La Red es: ");
 Serial.println(ssid);

 server1.on("/",handleConnectionRoot);

 server1.begin();
 Serial.println("Servidor HTTP iniciado");
 delay(150);
}

void loop() {
  server1.handleClient();
 }


void handleConnectionRoot(){  
  server1.send(200,"text/plain","Hola desde la ESP32");  
}
