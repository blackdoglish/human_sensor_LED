#include <dht.h>   
#include <Wire.h>  // Arduino IDE 內建  
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // 設定 LCD I2C 位址
#define dht_dpin A0 //定義訊號要從Pin A0 進來  
dht DHT;   

int i=0, y=0, x=1;
int sensor1;
int sensor2; 
const int RECV_PIN1 = 10;
const int RECV_PIN2 = 11;
const int fan=7;
double sensorValue;
const byte ledPin = 13;
int photocellPin = 0;

void setup(){   
 
Serial.begin(9600);   
delay(300);             //Let system settle   
Serial.println("Humidity and temperature\n\n");   
delay(700);             //Wait rest of 1000ms recommended delay before   
                        //accessing sensor   
pinMode(RECV_PIN1, INPUT);
pinMode(RECV_PIN2, INPUT);
pinMode(7, OUTPUT);
digitalWrite(7, HIGH); //close                        
//digitalWrite(7, LOW); //open
delay(3000);
lcd.begin(16, 2);  // 設定LCD有2列16欄  
lcd.backlight();
}
  
void loop(){   
DHT.read11(dht_dpin);   //去library裡面找DHT.read11 
sensor1 = 0;
sensor2 = 0;
sensor2 = digitalRead(RECV_PIN1);
sensor1 = digitalRead(RECV_PIN2);
Serial.print("bath = ");
Serial.println(sensor1);
Serial.print("photocellVal: ");
Serial.println(analogRead(photocellPin));
while (digitalRead(RECV_PIN2) == 0 && digitalRead(RECV_PIN1) == 0) {
   Serial.println("close");
   Serial.println(sensor1);
   digitalWrite(ledPin,LOW);
   digitalWrite(7, LOW);
   i=0;
   delay(500);
  }  
while (analogRead(photocellPin) > 400) {
  Serial.print("photocellVal: ");
  Serial.println(analogRead(photocellPin));  
  Serial.println("close");
  digitalWrite(ledPin,LOW);
  digitalWrite(7, LOW);
  delay(500);
  }
digitalWrite(ledPin,HIGH);
digitalWrite(7, HIGH);
delay(500);
}
