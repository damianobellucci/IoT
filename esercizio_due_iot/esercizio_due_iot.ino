#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);
float temperature;
int counter;

void setup() {
  temperature = -300;
  counter = 0;
  dht.begin();
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  counter = counter + 1;
  Serial.print("Rilevazione temperatura n. : ");
  Serial.println(counter);
  float currentTemperature = dht.readTemperature();
  if ( temperature != currentTemperature ) {
    temperature = currentTemperature;
    Serial.print("Nuova temperatura: ");
    Serial.println(currentTemperature);
  }
  else {
      Serial.println("Temperatura: stabile");
  }
  delay(10000);
}
