/* 
Arduino_IR_receiver
Implement IR receiver for Arduino 
Developed by: Walid Amriou
www.walidamriou.com

This work is licensed under:
Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.

Last update: September 2020
*/

#include <Arduino.h>

#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(115200);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
}