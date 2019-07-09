// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
#include <IRremote.h>

#define REDPIN 8
#define GREENPIN 9
#define BLUEPIN 10
#define FADESPEED 100 // make this higher to slow down
int sensorPin = 1; 
int sensorValue = 0; 
const int max_val= 600 ;
const int min_val= 200 ;

void setup()
{
   Serial.begin(9600);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  

}

void loop()
{
 
  int r=255, g=255, b=255;
  int new_r, new_g, new_b;
  int ratio;
  
  sensorValue = analogRead(sensorPin);

if(sensorValue>max_val){
  sensorValue=max_val-1;
}else if(sensorValue<min_val+10){
  sensorValue=min_val+10;
}

ratio=(float)sensorValue/(float)max_val;
ratio=1-ratio;

new_r=r*ratio;
new_g=g*ratio;
new_b=b*ratio;

 analogWrite(REDPIN, new_r);
 analogWrite(BLUEPIN, new_b);
 analogWrite(GREENPIN, new_g);

 //delay(FADESPEED);
 
 
}
