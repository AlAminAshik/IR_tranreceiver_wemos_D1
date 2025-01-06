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
    // IrSender.sendPulseDistanceWidthFromArray(38, 9000, 4550, 550, 1700, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 0, 0);
    // //office AC on signal|||||||||||||
    // uint64_t tRawData[]={0x41006000008FC3, 0x5845002000};
    // IrSender.sendPulseDistanceWidthFromArray(38, 8950, 4600, 550, 1700, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 0, 0);
    // //office AC increase temp signal|||||||||||||
    // uint64_t tRawData[]={0x410060000097C3, 0x5B40002000};
    // IrSender.sendPulseDistanceWidthFromArray(38, 9000, 4550, 550, 1750, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 0, 0);
    // //Office AC decrease temp signal|||||||||||||
    // uint64_t tRawData[]={0x41006000008FC3, 0x5441002000};
    // IrSender.sendPulseDistanceWidthFromArray(38, 9050, 4550, 550, 1700, 550, 600, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 0, 0);



#include <Arduino.h>
#include <IRremote.hpp> // include the library

const uint16_t IR_SEND_PIN = 4; // D5 on a NodeMCU board.
#define incButton 12    // D6 on a NodeMCU board.
#define menuButton 13   // D7 on a NodeMCU board.
#define decButton 15    // D8 on a NodeMCU board.

String menu_Items[] = {"idle", "AC turn on", "Temp mode", "AC turn off"}; //items
uint8_t curr_Menu_Item_Num = 0;             //keepinig track of which menu being displayed
uint8_t total_Menu_Item_Num = (sizeof(menu_Items)/sizeof(menu_Items[0])); //store the number of menu items. divide the array for proper counting of large arrays size

uint8_t sRepeats = 0;

IRAM_ATTR void activateMenu(){          //dont use ICACHE as it will cause a crash. use IRAM_ATTR instead
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 200) {
    curr_Menu_Item_Num++;         //cycle through menus
    Serial.println(menu_Items[curr_Menu_Item_Num]); //print the current menu item
    if(curr_Menu_Item_Num > total_Menu_Item_Num-1) curr_Menu_Item_Num = 0;    //close menu all options have been once shown
  }
  last_interrupt_time = interrupt_time;
}

void setup() {
    Serial.begin(115200);
    IrSender.begin(IR_SEND_PIN); // Start with IR_SEND_PIN -which is defined in PinDefinitionsAndMore.h- as send pin
    pinMode(menuButton, INPUT_PULLUP);
    pinMode(incButton, INPUT_PULLUP); 
    pinMode(decButton, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(menuButton), activateMenu, FALLING); //when menu button is pressed execute activateMenu
}


// void runMainMenu(){
//   Serial.println(menu_Items[curr_Menu_Item_Num]); //print the current menu item
//   delay(1000);
//   if(digitalRead(incButton) == LOW){ //if inc button is pressed
//     sRepeats++; //increase the number of repeats
//     Serial.print("sRepeats: ");
//     Serial.println(sRepeats);
//     delay(1000);
//   }
//   if(digitalRead(decButton) == LOW){ //if dec button is pressed
//     sRepeats--; //decrease the number of repeats
//     Serial.print("sRepeats: ");
//     Serial.println(sRepeats);
//     delay(1000);
//   }
// }

void loop() {
//activateMenu();
delay(100);
}