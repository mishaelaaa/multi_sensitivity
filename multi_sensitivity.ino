#include <DHT.h>
#include <DHT_U.h>

const int LEDpin=13;//the anode of the LED connects to digital pin D13

//for MQ3
const int AOUTpin1=0;//the AOUT pin of the Alcohol sensor goes into analog pin A0
const int DOUTpin1=8;//the DOUT pin of the Alcohol sensor goes into digital pin D8

//for MQ4
const int AOUTpin2=1;//the AOUT pin of the Methane sensor goes into analog pin A1
const int DOUTpin2=9;//the DOUT pin of the Methane sensor goes into digital pin D9

//for MQ7
const int AOUTpin3=2;//the AOUT pin of the Carbon Monoxide sensor goes into analog pin A2
const int DOUTpin3=10;//the DOUT pin of the Carbon Monoxide sensor goes into digital pin D10

//for MQ135
const int AOUTpin4=3;//the AOUT pin of the Air Quality sensor goes into analog pin A3
const int DOUTpin4=11;//the DOUT pin of the Air Quality sensor goes into digital pin D11

#define DHTPIN 7 // the connected pin
#define DHTTYPE DHT22 // type of the sensor 
// DHT22 (AM2302)
// or DHT11 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

//by MQ3
int value1;
int limit1;

//by MQ4
int value2;
int limit2;

//by MQ7
int value3;
int limit3;

//by MQ135
int value4;
int limit4;

void setup()
{
  Serial.begin(9600);//baud rate
  //by DHT sensor
  Serial.println("DHT");
  dht.begin();
 
  //MQ3
  pinMode(DOUTpin1, INPUT);//set pin as an input to the arduino
  //MQ4
  pinMode(DOUTpin2, INPUT);
  //MQ7
  pinMode(DOUTpin3, INPUT);
  //MQ135
  pinMode(DOUTpin4, INPUT);
  pinMode(LEDpin, OUTPUT);//set pin as an output to the arduino
}

void loop() {
  //reading the temperatre && humidity about 250 milliseconds
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  delay(10000);

  //MQ3
  value1=analogRead(AOUTpin1);
  limit1=digitalRead(DOUTpin1);
  //MQ4
  value2=analogRead(AOUTpin2);
  limit2=digitalRead(DOUTpin2);
  //MQ7
  value3=analogRead(AOUTpin3);
  limit3=digitalRead(DOUTpin3);
  //MQ135
  value4=analogRead(AOUTpin4);
  limit4=digitalRead(DOUTpin4);
  
  //print of the valute for DHT
  if (isnan(t) || isnan(h))
    Serial.println("You have not the data to DHT");
    else
    {
        Serial.print("Humidity: ");
        Serial.print(h);
        Serial.println(" %\t");
        Serial.print("Temperature: ");
        Serial.print(t);
        Serial.print("°C");

    }
    if (value1, value2, value3, value4 >=0)
    {
   //print of the valute for MQ3
      Serial.print("Alcohol Value: ");
      Serial.println(value1);
      Serial.print("Limit: ");
      Serial.print(limit1);
   //print of the valute for MQ4
      Serial.print("Methane Value: ");
      Serial.println(value2);
      Serial.print("Limit: ");
      Serial.print(limit2);
   //print of the valute for MQ7   
      Serial.print("Carbon Value: ");
      Serial.println(value3);
      Serial.print("Limit: ");
      Serial.print(limit3);
   //print of the valute for MQ135   
      Serial.print("CO2 Value: ");
      Serial.println(value4);
      Serial.print("Limit: ");
      Serial.print(limit4);
    }
      if (limit1, limit2, limit3, limit4 == HIGH)
        {
          digitalWrite(LEDpin, HIGH);//if limit has been reached, LED turns on as status indicator
        }
      else
        {
          digitalWrite(LEDpin, LOW);//if threshold not reached, LED remains off
        }
}
