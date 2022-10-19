#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>

int lee_temperatura(int);
int lee_humedad(int);
void muestra_puerto_serie();
int temp; 
int hum; 
int SENSOR = 2;			// pin DATA de DHT22 a pin digital 2
int TEMPERATURA;
int HUMEDAD;

DHT dht(SENSOR, DHT22);		// creacion del objeto

void setup() {
  Serial.begin(9600);		// inicializacion de monitor serial
  dht.begin();			// inicializacion de sensor
}

void loop() {
 TEMPERATURA=lee_temperatura(temp);
 HUMEDAD=lee_humedad(hum);
 muestra_puerto_serie();
  
}

int lee_temperatura(int temp){
 temp = dht.readTemperature();	// obtencion de valor de temperatura
 return temp;
}
int lee_humedad(int hum){
  hum = dht.readHumidity();		// obtencion de valor de humedad
   return hum;
}
void muestra_puerto_serie(){
  Serial.print("Temperatura: ");	// escritura en monitor serial de los valores
  Serial.print(TEMPERATURA);
  Serial.print(" Humedad: ");
  Serial.println(HUMEDAD);
  delay(500);
}