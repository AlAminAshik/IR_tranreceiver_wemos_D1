#include <Arduino.h>      //arduino lib
#include <IRremote.hpp>   //IR remote lib

#define IR_LED_PIN 23 // pin 37
#define BOTTOM_BUTTON_PIN 18 // pin 30, IR LED
#define PWR_BUTTON_PIN 27    // pin 12, MIDDLE_BUTTON_PIN, Power Button
#define CH_PD_PIN 13 // pin 16 GPIO 13

void setup()
{
  Serial.begin(115200);
  Serial.println("Started");
  pinMode(BOTTOM_BUTTON_PIN, INPUT_PULLUP);
  
    // Power on schedule
     pinMode(PWR_BUTTON_PIN, INPUT_PULLUP);
    pinMode(CH_PD_PIN, OUTPUT);    // sets GPIO0 as an output which will pull the mosfet ON
    digitalWrite(CH_PD_PIN, HIGH); // keep the mosfet off
    delay(2000);                   // wait for a defined delay time the device to boot up
    digitalWrite(CH_PD_PIN, LOW);  // latches the transistor to keep device on
    Serial.println("Device is ON");
    
    // if(ledcAttach(IR_LED_PIN, 40000, 8)){ // attach the IR LED pin to the LEDC channel
    //     Serial.println("IR LED pin attached to LEDC channel");
    // }
    // else{
    //     Serial.println("IR LED pin not attached to LEDC channel");
    // }

    // if(ledcDetach(IR_LED_PIN)){ // detach the IR LED pin from the LEDC channel
    //     Serial.println("IR LED pin detached from LEDC channel");
    // }
    // else{
    //     Serial.println("IR LED pin not detached from LEDC channel");
    // }
    IrSender.begin(IR_LED_PIN); // Start with IR_SEND_PIN -which is defined in PinDefinitionsAndMore.h- as send pin
}

void loop()
{
    // IR LED AC ON
    if (digitalRead(BOTTOM_BUTTON_PIN) == LOW)
    {
        //office AC on signal|||||||||||||
        uint64_t tRawData[] = {0x41006000008FC3, 0x5845002000};
        IrSender.sendPulseDistanceWidthFromArray(38, 8950, 4600, 550, 1700, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 0, 0);
        delay(200);
        //my AC on signal|||||||||||||
        //uint64_t tRawData2[]={0x56A900FF00FF00FF, 0x55AA2AD5};
        uint64_t tRawData2[]={0x56A900FF00FF00FF, 0x55AA2CD3};
        IrSender.sendPulseDistanceWidthFromArray(38, 6100, 7300, 600, 1650, 600, 550, &tRawData[0], 97, PROTOCOL_IS_LSB_FIRST, 0, 0);
        delay(200);
        IrSender.sendNEC(0x0, 0x40, 0);
        delay(200);
    }

    // IR LED AC OFF
    if (digitalRead(PWR_BUTTON_PIN) == LOW)
    {
      // office AC off signal|||||||||||||
      uint64_t tRawData[] = {0x41006000008FC3, 0x3845000000};
      IrSender.sendPulseDistanceWidthFromArray(38, 9000, 4550, 550, 1700, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 0, 0);
      delay(200);
      //my AC OFF signal|||||||||||
      //uint64_t tRawData2[]={0x54AB00FF00FF00FF, 0x55AA2AD5};
      uint64_t tRawData2[]={0x54AB00FF00FF00FF, 0x55AA2CD3};
      //IrSender.sendPulseDistanceWidthFromArray(38, 6050, 7350, 600, 1700, 600, 550, &tRawData[0], 97, PROTOCOL_IS_LSB_FIRST, 0, 0);
      IrSender.sendPulseDistanceWidthFromArray(38, 6100, 7300, 600, 1700, 600, 550, &tRawData[0], 97, PROTOCOL_IS_LSB_FIRST, 0, 0);
      delay(200);
    }
}