#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
#include <U8g2lib.h>

#include "Button.h"
Button Button1(8);
Button Button2(9);

 LiquidCrystal_I2C lcd(0x27,16,2);

int lee_temperatura(int);
int lee_humedad(int);
void muestra_puerto_serie();
void muestra_lcd();
void botones();
int temp; 
int hum; 
int SENSOR = 2;			// pin DATA de DHT22 a pin digital 2
int TEMPERATURA;
int HUMEDAD;

DHT dht(SENSOR, DHT22);		// creacion del objeto

void setup() {

  Serial.begin(9600);		// inicializacion de monitor serial
  dht.begin();			// inicializacion de sensor
   
  lcd.init();                      // initialize the lcd 
  lcd.setBacklight(HIGH);

}

void loop() {
 TEMPERATURA=lee_temperatura(temp);
 HUMEDAD=lee_humedad(hum);
 //muestra_puerto_serie();
 muestra_lcd();
 botones();
  
 
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

void muestra_lcd(){
 lcd.setCursor(0,0);
  lcd.print("Temp");
  lcd.setCursor(5,0);
  lcd.print(TEMPERATURA);
  lcd.setCursor(0,1);
  lcd.print("Hume");
  lcd.setCursor(5,1);
  lcd.print(HUMEDAD);
}
void botones(){
  Button1.Refresh();
 

  switch (Button1.GetPressType())
  {
  case Button::PressTypes::None:
  {
    break;
  }
  case Button::PressTypes::SingleClick:
  {
    Serial.println("A single click");
    break;
  }
  case Button::PressTypes::DoubleClick:
  {
    Serial.println("That was a double click!");
    break;
  }
  case Button::PressTypes::LongClick:
  {
    Serial.println("Aaaaannnnnndddd that was a long press");
    break;
  }
  }

 Button2.Refresh();
  switch (Button2.GetPressType())
  {
  case Button::PressTypes::None:
  {
    break;
  }
  case Button::PressTypes::SingleClick:
  {
    Serial.println("A single click");
    break;
  }
  case Button::PressTypes::DoubleClick:
  {
    Serial.println("That was a double click!");
    break;
  }
  case Button::PressTypes::LongClick:
  {
    Serial.println("Aaaaannnnnndddd that was a long press");
    break;
  }
  }
}