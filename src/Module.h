
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
#include <map>
#include <Ultrasonic.h>

/*----------End Lid-----------*/

/*----------Start Variable-----------*/

extern IPAddress ip;
extern IPAddress gateways;
extern IPAddress subnets;
extern IPAddress dns;

extern std::map<String, String> env_vars;

extern String MODES;
extern String AP_SSID;
extern String AP_PSK;
extern String STA_SSID;
extern String STA_PSK;
extern String mqtt_enable;
extern String mqtt_broker;
extern String mqtt_port;
extern String mqtt_topic;
extern String mqtt_username;
extern String mqtt_password;
extern String mqtt_interval;
extern String RTU_enable;
extern String RTU_deviceID;
extern String RTU_baudRate;
extern String TCP_wifi_enable;
extern String TCP_eth_enable;
extern String local_IP;
extern String gateway;
extern String subnet;
extern String dnss;

extern AsyncWebServer server;

extern const char* ssid;
extern const char* password;

extern int Vul;
extern int Vull;


/*----------End Variable-----------*/

/*-------------Start Funtion----
---------*/
void writeEnvFile();
void readEnvFile();
void updteEnvVariable(const String &ket,const String &value);
bool configureNetwork(String IPAddressStr,String gatewayStr,String subnetStr,String dnse);
IPAddress stringToIPAddress(String ipStr);

void setup_wifi();
void setup_wifiAP();

void ConfigServer();

void handleIndex (AsyncWebServerRequest *requset);
void handleSaveConfig (AsyncWebServerRequest *requset);
void handleNetworksConfig (AsyncWebServerRequest *requset);
int ULSC();
int ULSC2();

#endif
