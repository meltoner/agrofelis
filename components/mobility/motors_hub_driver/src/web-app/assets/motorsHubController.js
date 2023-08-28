var gateway = "ws://ip/ws";
var websocket;
var $console;
var previousMessage = "";

window.addEventListener('load', onLoad);

function initWebSocket() {
  $console =  $("#console")
  websocket = new WebSocket(gateway.replace("ip", $("#ip").val()));
  websocket.onopen    = onOpen;
  websocket.onclose   = onClose;
  websocket.onmessage = onMessage;
}

function onOpen(event) {
  console.log('Connection opened');
  $(".disconnected").removeClass("disconnected")
}

function onClose(event) {
  console.log('Connection closed');
  $("body").addClass("disconnected")
  setTimeout(initWebSocket, 2000);
}

function onLoad(event) {
  //if the ip was provided as a paramater      
  var paramIp = new URLSearchParams(window.location.search).get('ip');
  if(paramIp)
    $("#ip").val(paramIp)

  $("#unhide").click(function(){
    $(".hide").removeClass("hide")
  })
  
  initWebSocket();
  $(".command").on( "change", sendChange)
  $(".msg").on( "change", function(){websocket.send($(this).val())})
}

function sendChange(){
  var $item = $(this)  
  websocket.send("<" + $item.attr("id").replace("c","") + "|" + $item.val() +  ">");
}

function onMessage(event) {

  if(previousMessage != event.data){
    previousMessage = event.data;
    var truncated = event.data + "\n"+ $console.val();      
    $console.val(truncated.substring(0, 1000))

    var result = event.data;
    result = result.replaceAll("<","").split(">")
    result.forEach(function(element){
      if(element != "" && element != "\r"){          
        var atribs = element.split(";");

        var $module = $("#" + atribs[0] )

        // there is a convention here first actuators and then sensors
        var $commands = $module.find(".command");
        for(var i = 0; i < $commands.length; i++)
          $($module.find("#" + $($commands[i]).attr("id") + ":not(:focus)")).val(atribs[ i + 1])

        var $sensors = $module.find(".sensor");
        for(var i = 0; i < $sensors.length; i++)
            $($sensors[i]).val(atribs[i + $commands.length + 1])

      }
    }, Element)
  }
  console.log(event.data)
}