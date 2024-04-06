#include "Arduino.h"
#include "Adafruit_PCF8575.h"
Adafruit_PCF8575 pcf;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); 
  for ( uint8_t i = 0; i<=28 ; i++) {
    if(i!=10 && i!=11 && i!=22){
      pinMode(i, OUTPUT);
    }
  }
  pinMode(22, INPUT);
  delay(2000);
//    while (!Serial) { delay(10); }
  Serial.begin(115200);
  Serial.println("Adafruit PCF8575 LED blink test");

  if (!pcf.begin(0x20, &Wire)) {
    Serial.println("Couldn't find PCF8575");
  }
  for (uint8_t p=0; p<16; p++) {
    pcf.pinMode(p, OUTPUT);
  }
pcf.begin(0x21, &Wire);
  for (uint8_t p=0; p<16; p++) {
    pcf.pinMode(p, OUTPUT);
  }
pcf.begin(0x23, &Wire);
  for (uint8_t p=0; p<16; p++) {
    pcf.pinMode(p, OUTPUT);
  }
  
Serial.println("Config done");
delay(100);
  
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 
  digitalWrite(LED_BUILTIN, HIGH);  
  Serial.println("LED_BUILTIN, HIGH");
  delay(100);
  pcf.begin(0x20, &Wire);
  for (uint8_t p=0; p<16; p++) {
    pcf.digitalWrite(p, LOW);  // turn LED on by sinking current to ground
  }
  Serial.println("PCFs low");
  delay(1000);
  for (uint8_t p=0; p<16; p++) {
    pcf.digitalWrite(p, HIGH); // turn LED off by turning off sinking transistor
  }
  Serial.println("PCFs high");
  delay(1000);

  pcf.begin(0x21, &Wire);
    for (uint8_t p=0; p<16; p++) {
    pcf.digitalWrite(p, LOW);  // turn LED on by sinking current to ground
  }
    Serial.println("PCFs low");
delay(1000);
  for (uint8_t p=0; p<16; p++) {
    pcf.digitalWrite(p, HIGH); // turn LED off by turning off sinking transistor
  }
  Serial.println("PCFs high");

  pcf.begin(0x23, &Wire);
    for (uint8_t p=0; p<16; p++) {
    pcf.digitalWrite(p, LOW);  // turn LED on by sinking current to ground
  }
    Serial.println("PCFs low");
delay(1000);
  for (uint8_t p=0; p<16; p++) {
    pcf.digitalWrite(p, HIGH); // turn LED off by turning off sinking transistor
  }
  Serial.println("PCFs high");
  
  digitalWrite(LED_BUILTIN, LOW);   
  for(uint8_t i=0; i<28 ; i++){
     if(i!=10 && i!=11 && i!=22){
      digitalWrite(i, HIGH);
    }
    delay(100);
    if(i!=10 && i!=11 && i!=22){
      digitalWrite(i, LOW);
    }
  }
}
