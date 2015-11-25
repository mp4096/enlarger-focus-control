/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PRESSEDIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define PRG_UP_SINGLE  0x00000020
#define PRG_UP_PRESSED 0x00000820
#define PRG_DN_SINGLE  0x00000021
#define PRG_DN_PRESSED 0x00000821

#define VOL_UP_SINGLE  0x00000010
#define VOL_UP_PRESSED 0x00000810
#define VOL_DN_SINGLE  0x00000011
#define VOL_DN_PRESSED 0x00000811



int RECV_PIN = 6;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {

    if ((results.value == PRG_UP_SINGLE) || (results.value == PRG_UP_PRESSED)){
      Serial.println("UP fine");
      delay(500);
    }

    if ((results.value == VOL_UP_SINGLE) || (results.value == VOL_UP_PRESSED)){
      Serial.println("UP coarse");
      delay(100);
    }

    if ((results.value == PRG_DN_SINGLE) || (results.value == PRG_DN_PRESSED)){
      Serial.println("DN fine");
      delay(500);
    }

    if ((results.value == VOL_DN_SINGLE) || (results.value == VOL_DN_PRESSED)){
      Serial.println("DN coarse");
      delay(100);
    }

    //Serial.println(results.value, HEX);


  irrecv.resume(); // Receive the next value
  }

}
