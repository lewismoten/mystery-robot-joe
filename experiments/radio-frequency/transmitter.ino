#include <RF24.h>

#define RADIO_CE_PIN 9
#define RADIO_CS_PIN 10
#define RADIO_RETRY_DELAY 15
#define RADIO_RETRY_COUNT 15
#define SWITCH_PIN 2
#define LED_PIN 3

int msg[1];
int switchState = -999;

RF24 radio(RADIO_CE_PIN,RADIO_CS_PIN);

const uint64_t pipe = 0x12CB46E68BLL; # MUST MATCH

const int TURN_ON_COMMAND = 0x10042;
const int TURN_OFF_COMMAND = 0x10043;
                
void setup(void){
  
 radio.begin();
 radio.setRetries(RADIO_RETRY_DELAY, RADIO_RETRY_COUNT);
 radio.setDataRate(RF24_250KBPS);
 radio.setPayloadSize(1);
 radio.openWritingPipe(pipe);

 pinMode(SWITCH_PIN, INPUT);
 pinMode(LED_PIN, OUTPUT);
}

void loop(void){

  int state = digitalRead(SWITCH_PIN);
  
  if(switchState != state) {
    
    switchState = state;
    int command = TURN_OFF_COMMAND;

    if(state == HIGH) {
      command = TURN_ON_COMMAND;
    }
    
    digitalWrite(LED_PIN, state);
    
    msg[0] = command;
    radio.write(msg, 1);
    
  }

  delay(10);
}
 