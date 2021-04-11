#include <WiFi.h>
#include <PubSubClient.h>

#define wifi_ssid ""
#define wifi_password ""

#define mqtt_server "130.136.2.70"
#define mqtt_port 1883
#define mqtt_user ""
#define mqtt_password ""

#define in_topic "temperature/damianobellucci"

WiFiClient espClient;
PubSubClient client;

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setClient(espClient);
  client.setServer(mqtt_server, mqtt_port);  

}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    // If you do not want to use a username and password, change next line to
    // if (client.connect("ESP8266Client")) {
    if (client.connect("ESPClient8798yh98", mqtt_user, mqtt_password)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  // Publishes a random 0 and 1 like someone switching off and on randomly (random(2))
  client.publish(in_topic, String(random(2)).c_str(), true);
  delay(1000);
  client.subscribe(in_topic);
  delay(1000);
}
