#include <DHT.h>
#include <DHT_U.h>

int sensor = 2;
int temp;
int humedad;

DHT dht (sensor, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  temp = dht.readTemperature();
  humedad = dht.readHumidity();
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(". Humedad: ");
  Serial.println(humedad);
  delay(500);
}
