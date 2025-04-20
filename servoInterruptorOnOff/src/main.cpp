#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid="******";    // soft access point name
const char* password="****";  // soft access point password

IPAddress ip(192, 168, 4, 22);      // local IP of soft access point
IPAddress gateway(192, 168, 4, 9);  // soft access point gateway
IPAddress subnet(255, 255, 255, 0); // soft access point subnet mask

WebServer server(80);   // WebServer object created

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
}
