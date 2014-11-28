 /*\
  * Last Modified       : 28th November, 2014
  * Target Hardware	: Arduino Uno Rev 3
  * Description	        : A small file to test receiving byte arrays
 \*/


// test data
// 1,2,3,4,5,6,7,8,9

int BT_RX = 4;
int BT_TX = 5;
int LED_STRING_LENGTH = 9;
#include <SoftwareSerial.h>

SoftwareSerial btSerial(BT_RX, BT_TX); // RX, TX

void setup() {
    // Set the serial speed
    Serial.begin(9600);
    btSerial.begin(9600);
}

void loop() {
    String content = "";
    char character;

    if (Serial.available() > 0) {
        while (Serial.available()) {
            character = Serial.read();
            content.concat(character);
            delay(10);
        }
    }

    if (btSerial.available() > 0) {
        while (btSerial.available()) {
            character = btSerial.read();
            content.concat(character);
            delay(10);
        }
    }

    if (content != "") {
        byte data[LED_STRING_LENGTH];
        for (byte i = 0; i < LED_STRING_LENGTH; i++) {
            byte index = content.indexOf(",");
            data[i] = content.substring(0, index).toInt();
            content = content.substring(index + 1);
        }

        printArray(data);
        content = "";
    }
}

void printArray(byte data[]) {
    for (byte i = 0; i < LED_STRING_LENGTH; i++) {
        Serial.print(data[i]);
        Serial.print(", ");
    }
    Serial.println();
}

