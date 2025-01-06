/*
    * If you want to send a raw HEX value directly like e.g. 0xCB340102 you must use sendNECRaw()
    * example
    * Serial.println(F("Send 32 bit LSB 0xCB340102 with NECRaw()"));
    * IrSender.sendNECRaw(0xCB340102, sRepeats);
*/ 

/*
    * If you want to send an "old" MSB HEX value used by IRremote versions before 3.0 like e.g. 0x40802CD3 you must use sendNECMSB()
    * example
    * Serial.println(F("Send old 32 bit MSB 0x40802CD3 with sendNECMSB()"));
    * IrSender.sendNECMSB(0x40802CD3, 32, sRepeats);
*/

/*
    * Set up the data to be sent.
    * For most protocols, the data is build up with a constant 8 (or 16 byte) address
    * and a variable 8 bit command.
    * There are exceptions like Sony and Denon, which have 5 bit address.
*/

    // //my light control signal|||||||||||||
    // IrSender.sendNEC(0x0, 0x40, sRepeats);     //can also be sent using raw data 0xBF40FF00
    // delay(100);
    // //my AC on signal|||||||||||||
    // uint64_t tRawData[]={0x56A900FF00FF00FF, 0x55AA2AD5};
    // IrSender.sendPulseDistanceWidthFromArray(38, 6100, 7300, 600, 1650, 600, 550, &tRawData[0], 97, PROTOCOL_IS_LSB_FIRST, 0,sRepeats);
    // delay(100);
    // //my TV signal|||||||||||||
    // IrSender.sendPulseDistanceWidth(38, 4600, 4550, 600, 1700, 600, 600, 0xFD020707, 32, PROTOCOL_IS_LSB_FIRST, 0, sRepeats);
    // //office AC off signal|||||||||||||
    // uint64_t tRawData[]={0x41006000008FC3, 0x3845000000};
    // IrSender.sendPulseDistanceWidthFromArray(38, 9000, 4550, 550, 1700, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, <RepeatPeriodMillis>, <numberOfRepeats>);
    // //office AC on signal|||||||||||||
    // uint64_t tRawData[]={0x41006000008FC3, 0x5845002000};
    // IrSender.sendPulseDistanceWidthFromArray(38, 8950, 4600, 550, 1700, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, <RepeatPeriodMillis>, <numberOfRepeats>);
    // //office AC increase temp signal|||||||||||||
    // uint64_t tRawData[]={0x410060000097C3, 0x5B40002000};
    // IrSender.sendPulseDistanceWidthFromArray(38, 9000, 4550, 550, 1750, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, <RepeatPeriodMillis>, <numberOfRepeats>);
    // //Office AC decrease temp signal|||||||||||||
    // uint64_t tRawData[]={0x41006000008FC3, 0x5441002000};
    // IrSender.sendPulseDistanceWidthFromArray(38, 9050, 4550, 550, 1700, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, <RepeatPeriodMillis>, <numberOfRepeats>);



#include <Arduino.h>
#include <IRremote.hpp> // include the library

//#define SEND_PWM_BY_TIMER         // Disable carrier PWM generation in software and use (restricted) hardware PWM.
//#define USE_NO_SEND_PWM           // Use no carrier PWM, just simulate an active low receiver signal. Overrides SEND_PWM_BY_TIMER definition

const uint16_t IR_SEND_PIN = 4; // D5 on a NodeMCU board.
#define inputButton 5         // D1 on a NodeMCU board.

uint8_t sRepeats = 0;

void setup() {
    pinMode(inputButton, INPUT_PULLUP);

    Serial.begin(115200);

    IrSender.begin(IR_SEND_PIN); // Start with IR_SEND_PIN -which is defined in PinDefinitionsAndMore.h- as send pin and enable feedback LED at default feedback LED pin
}

void loop() {
    //Serial.println(F("Send standard NEC with 8 bit address"));
    if(digitalRead(inputButton)==LOW){

        delay(1000);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
    }
    delay(50);
}