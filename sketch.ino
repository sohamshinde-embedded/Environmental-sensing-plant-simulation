#include<LiquidCrystal_I2C.h> // library file for LiquidCrystel Display
#include<DHT.h>               //library file for DHT Sensor
#include<Wire.h>              ////library filr for I2C Communication
#define DHTTYPE DHT22
#define DHTPIN 25
#define LDR    34
#define LED    4
#define TRIPIN 2
#define ECHOPIN 0
LiquidCrystal_I2C lcd(0x27,20,4);  // address 0x27,20x4 display
DHT dht(DHTPIN,DHTTYPE);

void setup(){

  Serial.begin(115200);
  dht.begin();
  pinMode(DHTPIN,INPUT);
  pinMode(LDR,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(TRIPIN,OUTPUT);
  pinMode(ECHOPIN,INPUT);
  lcd.init();
  lcd.backlight();


}
void loop(){
  //For LDR

  int rawvalue = analogRead(LDR);
  int lightvalue =  (rawvalue * 100) / 4095;
Serial.println(lightvalue);
  if(rawvalue > 2000){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }

// For DHT22 sensor to measure humidity and temperature

float humidity = dht.readHumidity();
float temperature = dht.readTemperature();

//For ultrasonic sensor
// Send ultrasonic pulses

digitalWrite(TRIPIN,LOW);
delayMicroseconds(2);
digitalWrite(TRIPIN,HIGH);
delayMicroseconds(10);
digitalWrite(TRIPIN,LOW);
delayMicroseconds(2);
// Read echo pulse
long duration = pulseIn(ECHOPIN,HIGH);
// Convert into a distance
 float distance = (duration * 0.034 / 2);

displaystatus(lightvalue, humidity, temperature, distance);

  delay(2000);
}
void displaystatus(int light, float hum, float temp, float dist)
{
lcd.setCursor(0,0);
lcd.print("intensity: ");
lcd.print(light);
lcd.print("%");

lcd.setCursor(0,1);
lcd.print("humidity: ");
lcd.print(hum);
lcd.print("%");

lcd.setCursor(0,2);
lcd.print("temperature: ");
lcd.print(temp);
lcd.print(char(223));
lcd.print("c");

lcd.setCursor(0,3);
lcd.print("distance: ");
lcd.print(dist);
lcd.print("cm");

}
