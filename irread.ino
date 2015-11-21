/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define ARR_UP_S 0xE0E006F9
#define ARR_UP_P 0xC26BF044
#define ARR_DN_S 0xE0E08679
#define ARR_DN_P 0xC4FFB646

#define VOL_UP_S 0xE0E0E01F
#define VOL_UP_P 0x68733A46
#define VOL_DN_S 0xE0E0D02F
#define VOL_DN_P 0x83B19366



int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {

    if ((results.value == ARR_UP_S) || (results.value == ARR_UP_P)){
      Serial.println("UP fine");
      delay(500);
    }
    
    if ((results.value == VOL_UP_S) || (results.value == VOL_UP_P)){
      Serial.println("UP coarse");
      delay(100);
    }
    
    if ((results.value == ARR_DN_S) || (results.value == ARR_DN_P)){
      Serial.println("DN fine");
      delay(500);
    }
    
    if ((results.value == VOL_DN_S) || (results.value == VOL_DN_P)){
      Serial.println("DN coarse");
      delay(100);
    }

    // Serial.println(results.value, HEX);
    
    
  irrecv.resume(); // Receive the next value
  }
  
}
