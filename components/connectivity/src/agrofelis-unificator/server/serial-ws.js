"use strict";
process.title = 'node-serial-ws';

// apt-get update;apt-get install python3;npm install http serialport websocket
 
// Websocket
var webSocketsServerPort = 8080;
var webSocketServer = require('websocket').server;
var http = require('http');

var server = http.createServer(function(request, response) { console.log(request) });

var clients = [];
server.listen(webSocketsServerPort, function() {console.log((new Date()) + " Server is listening on port " + webSocketsServerPort);});
var wsServer = new webSocketServer({httpServer: server});

wsServer.on('request', function(request) {

    console.log((new Date()) + ' Connection from origin ' + request.origin + '.');
    var connection = request.accept(null, request.origin);     
    var index = clients.push(connection) - 1;  
    connection.on('message', function(message) {onReceive(message);});
    connection.on('close', function(connection) {clients.splice(index, 1);});

});

function onReceive(msg){
  if(msg.utf8Data == "exit")
     process.exit(0);
   
  console.log("ws msg:" + msg.utf8Data);
  serialPort.write(msg.utf8Data);
}

function onSerial(msg){
  console.log("uart msg:" + msg);

  //broadcast uart messate to ws clients
  for (var i = 0; i < clients.length; i++) 
    clients[i].sendUTF(msg);
}

// Serial port
var SerialPort = require("serialport").SerialPort
var buffer = "";

var serialPort = new SerialPort({ path: '/dev/ttyACM0', baudRate: 9600 })
serialPort.on("open", function () {  
    serialPort.on('data', function(data) {
      buffer += new String(data);
      var lines = buffer.split("\n");
      while ( lines.length > 1 )
        onSerial( lines.shift() );
      buffer = lines.join("\n");
  });  
});  