
#ifndef MODULE_H
#define MODULE_H

/*
WiFi 3 Mode
1 -> AP (Access Point)
2 -> STA (Station)
3 -> APSTA (Access Point and Station)
*/

/*----------Start Lid-----------*/

#include <Arduino.h>
#include <WiFi.h>

#include <SPIFFS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>

/*----------End Lid-----------*/

/*----------Start Variable-----------*/

extern AsyncWebServer server;

extern const char* ssid;
extern const char* password;


/*----------End Variable-----------*/

void setup_wifi();
void setup_wifiAP();

void ConfigServer();

void handleIndex (AsyncWebServerRequest *requset);


#endif
