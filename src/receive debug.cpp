// /*
//  * SimpleReceiver.cpp
//  *
//  * Demonstrates receiving ONLY NEC protocol IR codes with IRremote
//  * If no protocol is defined, all protocols (except Bang&Olufsen) are active.
//  */

// #include <Arduino.h>

// /*
//  * Specify which protocol(s) should be used for decoding.
//  * If no protocol is defined, all protocols (except Bang&Olufsen) are active.
//  * This must be done before the #include <IRremote.hpp>
//  */
// //#define DECODE_DENON        // Includes Sharp
// //#define DECODE_JVC
// //#define DECODE_KASEIKYO
// //#define DECODE_PANASONIC    // alias for DECODE_KASEIKYO
// //#define DECODE_LG
// #define DECODE_NEC          // Includes Apple and Onkyo. To enable all protocols , just comment/disable this line.
// //#define DECODE_SAMSUNG
// //#define DECODE_SONY
// //#define DECODE_RC5
// //#define DECODE_RC6

// //#define DECODE_BOSEWAVE
// //#define DECODE_LEGO_PF
// //#define DECODE_MAGIQUEST
// //#define DECODE_WHYNTER
// //#define DECODE_FAST

// #define DECODE_DISTANCE_WIDTH // Universal decoder for pulse distance width protocols
// #define DECODE_HASH         // special decoder for all protocols

// //#define DECODE_BEO          // This protocol must always be enabled manually, i.e. it is NOT enabled if no protocol is defined. It prevents decoding of SONY!

// //#define DEBUG               // Activate this for lots of lovely debug output from the decoders.

// //#define RAW_BUFFER_LENGTH  750 // For air condition remotes it requires 750. Default is 200.

// /*
//  * This include defines the actual pin number for pins like IR_RECEIVE_PIN, IR_SEND_PIN for many different boards and architectures
//  */

// #include <IRremote.hpp> // include the library
// const uint16_t IR_RECEIVE_PIN = 14; // D5 on a NodeMCU board.

// void setup() {
//     Serial.begin(115200);

//     // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
//     IrReceiver.begin(IR_RECEIVE_PIN);

//     Serial.print(F("Ready to receive IR signals of protocols: "));
//     printActiveIRProtocols(&Serial);
// }

// void loop() {
//     /*
//      * Check if received data is available and if yes, try to decode it.
//      * Decoded result is in the IrReceiver.decodedIRData structure.
//      *
//      * E.g. command is in IrReceiver.decodedIRData.command
//      * address is in command is in IrReceiver.decodedIRData.address
//      * and up to 32 bit raw data in IrReceiver.decodedIRData.decodedRawData
//      */
//     if (IrReceiver.decode()) {

//         if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
//             Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
//             // We have an unknown protocol here, print extended info
//             IrReceiver.printIRResultRawFormatted(&Serial, true);

//             IrReceiver.resume(); // Do it here, to preserve raw data for printing with printIRResultRawFormatted()
//         } else {
//             IrReceiver.resume(); // Early enable receiving of the next IR frame

//             IrReceiver.printIRResultShort(&Serial);     // Print a short result as a summary
//             IrReceiver.printIRSendUsage(&Serial);       // Print the library usage to send
//         }
//         Serial.println();

//         /*
//          * Finally, check the received data and perform actions according to the received command
//          */
//         if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
//             Serial.println(F("Repeat received. Here you can repeat the same action as before."));
//         } else {
//             if (IrReceiver.decodedIRData.command == 0x10) {
//                 // do something
//             } else if (IrReceiver.decodedIRData.command == 0x11) {
//                 // do something else
//             }
//         }
//     }
// }