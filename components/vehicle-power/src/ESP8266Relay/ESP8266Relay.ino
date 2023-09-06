#include <ESP8266WiFi.h>

// Basic on / off relay 

const char* ssid = "agrofelis";
const char* password = "felisagrofelistobor_";
// fix so it dosn't flicker on power up
#define RELAY 3 // relay connected to  GPIO3
WiFiServer server(80);
int value = HIGH;

void setup() {
  Serial.begin(115200); // must be same baudrate with the Serial Monitor
 
  pinMode(RELAY,OUTPUT);
  digitalWrite(RELAY, HIGH);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  
  WiFiClient client = server.available();
  if (!client)
    return;
  Serial.println("new client");
  while(!client.available())
    delay(1);
    
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  
  if (request.indexOf("/RELAY=ON") != -1) {
    Serial.println("RELAY=ON");
    digitalWrite(RELAY,LOW);
    value = LOW;
  }
  if (request.indexOf("/RELAY=OFF") != -1){
    Serial.println("RELAY=OFF");
    digitalWrite(RELAY,HIGH);
    value = HIGH;
  }
  
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  this is a must
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><title>ESP8266 RELAY Control</title></head>");
  client.print("Relay is now: ");
 
  if(value == HIGH)
    client.print("OFF");
  else   
    client.print("ON");

  client.println("<br><br>");
  client.println("Turn <a href=\"/RELAY=OFF\">OFF</a> RELAY<br>");
  client.println("Turn <a href=\"/RELAY=ON\">ON</a> RELAY<br>");
    client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
