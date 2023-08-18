/** 
 * Remote Controller 
 *
 * The project employs an esp32 and various sensors to control remotely the Agrofelis robot. The controller employs a joystick module composed 
 * of two potentiometer and a switch. The controller moreover, includes two additional potentiometer and two switches providing in total, 7 input sensors.
 * On the left side of the controller, on the first row, the two potentionmeters are used as limiters to the speed of the motors and the breaks.
 * On the left side of the controller, on the second row, two switches are available. 
 * The first switch interchanges the joystic mapping, from the vehicle to its mounted tool.
 * The second switch actuates the brakes. On the right side of the remote controller the joystic allows to dictate the combined desired direction and movement of the vehicle or other mounted tool.
 * 
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023 Agrofelis project 
 */

#include <Arduino.h>
#include "Context.h"
#include "Invoker.h"

#include "Sensors.h"

#include <WiFi.h>
#include <AsyncTCP.h>

#include <ESPAsyncWebSrv.h>
#include <AsyncElegantOTA.h>

Context context = Context(); 
Invoker invoker = Invoker();
Sensors sensors = Sensors();

//const char* ssid = "agrofelis";

const char* ssid = "agrofelis";
const char* password = "felisagrofelistobor_";


// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");


const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>

<title>ESP remote control web Server</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" href="data:,">
</head>
<body>
open https://github.com/meltoner/agrofelis/blob/main/components/connectivity/remote/src/web-app/index.html
</body>
</html>)rawliteral";

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    //controller.parseData((char*)data);
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

String processor(const String& var){
  Serial.println(var);   
  return String();
}

void setup(){
  Serial.begin(115200);
  
  context.setup(ws);
  sensors.setup(context);
  invoker.setup(context);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println(WiFi.localIP());
  initWebSocket();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  AsyncElegantOTA.begin(&server);
  server.begin();
}

void apply_interval_0(){
}

void apply_interval_1(){
  sensors.apply();
}

void apply_interval_2(){
  sensors.detectChange();
}

void apply_interval_3(){
  sensors.print();
  Serial.println("");
}

void apply_interval_4(){
}

void apply_interval_5(){
}

void run_invoker(int i){
    switch(i){
      case 0: apply_interval_0(); break;
      case 1: apply_interval_1(); break;
      case 2: apply_interval_2(); break;
      case 3: apply_interval_3(); break;
      case 4: apply_interval_4(); break;
      case 5: apply_interval_5(); break;
      case 100: break;
    }
}

void loop() {
  ws.cleanupClients();
  
 int actionIndex = invoker.apply();
  while(actionIndex != 100){
    run_invoker(actionIndex);
    actionIndex = invoker.apply();
  }
 
}