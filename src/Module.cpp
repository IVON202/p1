#include "module.h"

const char* ssid = "Npas";
const char* password = "123456789";

AsyncWebServer server(80);

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup_wifiAP(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);

    Serial.print("\nWiFi shared on SSID: ");
    Serial.print(ssid);
    Serial.print(" ,PSK: ");
    Serial.println(password);
    Serial.print("AP IP address: ");      // AP IP address: 192.168.4
    Serial.println(WiFi.softAPIP());    
}

void ConfigServer(){
  if(!SPIFFS.begin(true)){
    Serial.println("Error Starting SPIFFS!!!");
    return;
  }

  //2nd setp shere WiFi AP
  setup_wifiAP();

  //3rd step Create DNS
  if(!MDNS.begin("nanthawat")) {
    Serial.println("Error Starting DNS");
    return;
  }

  //4th step Server on index.html
  server.on("/styles.css",HTTP_GET,[](AsyncWebServerRequest *request)
            { request->send (SPIFFS,"/styles.css"); });
  server.on("/dscripts.js",HTTP_GET,[](AsyncWebServerRequest *request)
            { request->send (SPIFFS,"/dscripts.js"); });
  server.on("/",HTTP_GET,[](AsyncWebServerRequest *request)
            { request->send (SPIFFS,"/index.html"); });           

MDNS.addService("http","tcp",80);
server.begin();
}

void handleIndex (AsyncWebServerRequest *request){

}