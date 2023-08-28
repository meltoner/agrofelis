/** 
 * Dual motor driver - Agrofelis 
 *
 * The project uses an esp32 and various componentes to sense and control two motor hub drivers of 250w each. The module utilises websockets to share the 
 * internal state of the components as well as to control it. Via this method a solid interface and a compact protocol allows 
 * for multiple actors to view, control or relay the information. The project providing a web and a websocket server allows for over the air firmware updates.
 * The module consist of an esp32, a logic level shifter two current sensors, six relays, two of which are connected in series with 
 * high (20amp) amperage relays. The source code is accompanied by a pcb board design and cnc files to reproduce the module.
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023 Agrofelis project 
 */

#include <Arduino.h>
#include "Context.h"
#include "Invoker.h"

#include "MotorsHubController.h"

#include <WiFi.h>
#include <AsyncTCP.h>

#include <ESPAsyncWebSrv.h>
#include <AsyncElegantOTA.h>

Context context = Context();
MotorsHubController controller = MotorsHubController();
Invoker invoker = Invoker();

// const char* ssid = "xxxx-Change-me";
// const char* password = "xxxx-Change-me";

const char* ssid = "agrofelis";
const char* password = "felisagrofelistobor_";


// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");


const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>

<title>ESP Motors web Server</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" href="data:,">
</head>
<body>
Agrofelis - Front - Motors hub controller. Open related control application - https://github.com/meltoner/agrofelis/
</body>
</html>)rawliteral";

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    controller.parseData((char*)data);
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
  controller.setup(context);
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
}

void apply_interval_2(){
  controller.apply();
}

void apply_interval_3(){ 

  controller.print();
}

void apply_interval_4(){
  context.apply();
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
  controller.fastApply();
  
 int actionIndex = invoker.apply();
  while(actionIndex != 100){
    run_invoker(actionIndex);
    actionIndex = invoker.apply();
  }
 
}