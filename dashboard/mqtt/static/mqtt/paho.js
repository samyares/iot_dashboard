// Create a client instance
var client = new Paho.MQTT.Client("192.168.137.139", 1884, "", "06ce7952");


// set callback handlers
client.onConnectionLost = onConnectionLost;
client.onMessageArrived = onMessageArrived;

// connect the client
client.connect({onSuccess:onConnect});


// called when the client connects
function onConnect() {
  // Once a connection has been made, make a subscription and send a message.
  console.log("onConnect");
  client.subscribe("#");
}

// called w+hen the client loses its connection
function onConnectionLost(responseObject) {
  if (responseObject.errorCode !== 0) {
    console.log("onConnectionLost:"+responseObject.errorMessage);
  }
}

// called when a message arrives
function onMessageArrived(message) {
    if(message.destinationName == 'brightness')
    {
        console.log('brightness:' + message.payloadString);
        $('#easypiechart-teal').data('easyPieChart').update(parseInt(message.payloadString));
        $('#brightness_monitor').html(message.payloadString+'%');
    }
    if(message.destinationName == 'light')
    {
        console.log('light:' + message.payloadString);
        $('#easypiechart-blue').data('easyPieChart').update(parseInt(message.payloadString)*100)
        $('#light_monitor').html(message.payloadString==="1"? "on":"off");
    }
    
}