#include "RF24.h"

#define RADIO_CE_PIN 9
#define RADIO_CS_PIN 10
#define RADIO_RETRY_DELAY 15
#define RADIO_RETRY_COUNT 15
#define LED_PIN 3

int msg[1];
RF24 radio(RADIO_CE_PIN,RADIO_CS_PIN);
const uint64_t pipe = 0x12CB46E68BLL; #MUST MATCH

const int TURN_ON_COMMAND = 0x10042;
const int TURN_OFF_COMMAND = 0x10043;

void setup(void){
  
 pinMode(LED_PIN, OUTPUT);
 
 radio.begin();
 radio.setRetries(RADIO_RETRY_DELAY, RADIO_RETRY_COUNT);
 radio.setDataRate(RF24_250KBPS);
 radio.setPayloadSize(1);
 radio.openReadingPipe(1,pipe);
 radio.startListening();
 pinMode(LED_PIN, OUTPUT);
}

void loop(void){

  bool wasDelayed = false;
  
    while (radio.available()){
      
      radio.read(msg,1);

      int command = msg[0];

      if(command == TURN_ON_COMMAND) {
        digitalWrite(LED_PIN, HIGH);
      } else if(command == TURN_OFF_COMMAND) {
        digitalWrite(LED_PIN, LOW);
      }

      delay(10);
      wasDelayed = true;

    }
    
    if(!wasDelayed) {
     delay(10);
    }
 }