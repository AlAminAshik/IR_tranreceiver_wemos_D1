/*
 * IRremoteESP8266: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * This is very simple teaching code to show you how to use the library.
 * If you are trying to decode your Infra-Red remote(s) for later replay,
 * use the IRrecvDumpV2.ino (or later) example code instead of this.
 * An IR detector/demodulator must be connected to the input kRecvPin.
 * Copyright 2009 Ken Shirriff, http://arcfn.com
 * Example circuit diagram:
 *  https://github.com/crankyoldgit/IRremoteESP8266/wiki#ir-receiving
 */
//6DEFF85F or 1844443231 ac turn on/off
//FF02FD or 16712445 light on/off

#include <Arduino.h>
#define DECODE_NEC              //for chinese remotes
#define DECODE_DISTANCE_WIDTH   //for AC remotes
#include <IRremote.hpp> // include the library

const uint16_t IR_RECEIVE_PIN = 14; // D5 on a NodeMCU board.

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
    if (IrReceiver.decode()) {
        IrReceiver.resume(); // Early enable receiving of the next IR frame
        IrReceiver.printIRResultShort(&Serial);     // Print a short result as a summary
        IrReceiver.printIRSendUsage(&Serial);       // Print the library usage to send
    }
    delay(50);
}