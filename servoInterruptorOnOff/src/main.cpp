#include <esp_wifi.h>
#include <esp_event.h>
#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include "esp_netif.h"
#include "esp_eth.h"
#include "protocol_examples_common.h"
#include <esp_https_server.h>
#include "esp_tls.h"
#include <string.h>
#include "driver/gpio.h"
#include <stdio.h>

//#include <Arduino.h>
//#include <WiFi.h>
//#include <WebServer.h>

const char* ssid="******";    // soft access point name
const char* password="****";  // soft access point password

//IPAddress ip(192, 168, 4, 22);      // local IP of soft access point
//IPAddress gateway(192, 168, 4, 9);  // soft access point gateway
//IPAddress subnet(255, 255, 255, 0); // soft access point subnet mask

//WebServer server(80);   // WebServer object created

// Output pins
const byte servo1PinData = 19;    // output pin for servo 1
const byte servo2PinData = 5;     // output pin for servo 2

void setup() {
  // put your setup code here, to run once:
  //pinMode(servo1PinData, OUTPUT);   // servo1PinData pin configured as output
  //pinMode(servo2PinData, OUTPUT);   // servo2PinData pin configured as output

  //WiFi.softAP(ssid, password);      // creates the access point
  //IPAddress ip = WiFi.softAPIP();   // getting the soft access point IP
  //WiFi.softAPConfig(ip, gateway, subnet);   // configures soft access point

  //server.on("/", handleConnectionRoot);   // if root address is consulted, execute handleConnectionRoot function
  //server.on("/turnOn", handleTurnOn);     // if /turnOn address is consulted, execute handleTurnOn function
  //server.on("/turnOff", handleTurnOff);   // if /turnOff address is consulted, exevute handleTurnOff function

}

void loop() {
  // put your main code here, to run repeatedly:
}

String answer = "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n    <meta charset=\"UTF-8\">\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n    <title>My Page</title>\n</head>\n<body>\n    <div class=\"container\">\n        <h1>Welcome to My Page</h1>\n        <p>This is a sample HTML page. Edit the code to create your HTML.</p>\n        \n    </div>\n</body>\n</html>";

/*void handleConnectionRoot(){

  server.send(200, "text/html", answer);

}*/

// Function for the event to turn on the light
/*void handleTurnOn(){

  server.send(200, "text/html", answer);

}*/