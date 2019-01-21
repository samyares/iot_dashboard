#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char *ssid = "msi";
const char *password = "amirmasoud";
const char *mqtt_server = "192.168.137.139";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msgA[50];
char msgD[50];
int value = 0;
int valueA = 0;
int valueD = 0;
int val = 0;

void setup_wifi()
{

  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  if ((char)payload[0] == '1')
  {
    digitalWrite(BUILTIN_LED, LOW);
  }
  else
  {
    digitalWrite(BUILTIN_LED, HIGH);
  }
}

void reconnect()
{
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
      client.publish("outTopic", "hello world");
      client.subscribe("inTopic");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup()
{
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(A0 , INPUT) ;
  pinMode(D0 , INPUT) ;
}

void loop()
{

  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 1000)
  {
    lastMsg = now;
    //++value;
    val = analogRead(0);
    valueA = map(val, 0, 1023, 0, 100);
    valueD = digitalRead(0);
    snprintf(msgA, 50, "%ld", valueA);
    snprintf(msgD, 50, "%ld", valueD);
    Serial.print("Brightness: ");
    Serial.print(msgA);
    Serial.print("  light: ");
    Serial.println(msgD);
    client.publish("brightness", msgA);
    client.publish("light", msgD);
  }
}
