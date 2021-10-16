 
/*monaja remote control project 17/11/2017*/
 
#include <IRremote.h> 
const int recevPin = 2;
const int relay = 4;
const int ledRed = 3;
bool State = LOW;

IRrecv switchLite(recevPin);
decode_results results;
void setup() { 
  pinMode(recevPin,INPUT);
  pinMode(relay,OUTPUT);
  pinMode(ledRed,OUTPUT);
  switchLite.enableIRIn();
  
  Serial.begin(9600);
  Serial.println("Pressed Ch- to switch the light ... on/off:...");
}

void loop() {
 
  if(switchLite.decode(&results)){
    Serial.println(results.value, HEX);
    if(results.value == 0xFFA25D){
       if(State == LOW){
          State = HIGH;
          digitalWrite(relay,State);
          digitalWrite(ledRed,State);
        }else{
          State = LOW;
          digitalWrite(relay,State);
          digitalWrite(ledRed,LOW);
        }
    }else{
      Serial.println(results.value,HEX);
    }
    delay(200);
    switchLite.resume();
  }
 
}
