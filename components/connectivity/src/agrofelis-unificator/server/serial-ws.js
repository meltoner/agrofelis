"use strict";
process.title = 'node-serial-ws';

// apt-get update;apt-get install python3;npm install http serialport websocket axios


var vocabulary = ["exit", "powerOn", "powerOff"]
var nodes = [
    ["Motors Hub back", "192.168.0.55", -1] , ["Motors Hub Front", "192.168.0.56", -1], ["Remote Controller", "192.168.0.60", -1]
]

var powerRelays = ["192.168.0.51", "192.168.0.52"];

const axios = require('axios');
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
    connection.on('message', onReceive);
    connection.on('close', function(connection) {clients.splice(index, 1);});
});

function isMessageActionable(msg){
    var result = (msg.utf8Data.indexOf("|") != -1);
    if(!result)
        for(var i=0;i<vocabulary.length;i++)//strangely indexOf didn't work return undefined
            if(vocabulary[i] == msg.utf8Data)
                return true;        
    return result
}

function onReceive(msg){    

    if(isMessageActionable(msg)){
        switch(vocabulary.indexOf(msg.utf8Data)){
            case -1: break;
            case 0:process.exit(0);brake;
            case 1:                            
                setTimeout(function(){axios.get("http://"+powerRelays[0]+"/RELAY=ON")}, 2000)
                setTimeout(function(){axios.get("http://"+powerRelays[1]+"/RELAY=ON")}, 4000)
                return;
            case 2:                 
                setTimeout(function(){axios.get("http://"+powerRelays[0]+"/RELAY=OFF")}, 2000)
                setTimeout(function(){axios.get("http://"+powerRelays[1]+"/RELAY=OFF")}, 4000)
                return;
        }

        var command = parseInt(msg.utf8Data.substring(1, msg.utf8Data.indexOf("|")))
        
        if( command <= 20){   
            for(var i = 0; i < 2;i++)
              if(nodes[i][2] != -1){
                nodes[i][2].send(msg.utf8Data)
              }
                
        }else{            
            serialPort.write(msg.utf8Data);
        }
    }
}

function onSerial(msg){
  console.log("Serial msg:" + msg);

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

function createNewConnection(index){
    var ip = nodes[index][1]
    const WebSocketClient = require('websocket').client;
    var client = new WebSocketClient();

    client.on('connectFailed', function(error) {
        console.log("EEEEEEEEEEEEEEEEEERRRRRRRRRRRRORRRR")
        console.log('Connect Error: ' + error.toString());
    });

    client.on('connect', function(connection) {
        console.log('Connection established with ' + ip);
        console.log('\n');

        nodes[index][2] = connection;
            
        connection.on('error', function(error) {
            console.log("EEEEEEEEEEEEEEEEEERRRRRRRRRRRRORRRR")
            nodes[index][2] = -1;
        });
        
 
        connection.on('close', function(reasonCode, description) {
            console.log((new Date()) + ' Peer ' + connection.remoteAddress + ' disconnected.');
        });

        connection.on('message', function(msg) {
            console.log(msg.utf8Data);
            //broadcast uart messate to ws clients
            for (var i = 0; i < clients.length; i++) 
              clients[i].sendUTF(msg.utf8Data);

            if(isMessageActionable(msg))
                onReceive(msg);

        });
    });

    client.connect('ws://localhost/ws'.replace("localhost", ip), '');

}

for(var i = 0;i<nodes.length;i++)
  if(nodes[i][2] == -1)
     createNewConnection(i)
