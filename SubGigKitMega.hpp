#include <arduino.h>
#include "SerialComsKit.hpp"

namespace privateSubGigKit{
String edttingString(String inputObjectString){
    int positions = (int)inputObjectString.indexOf(":");
    
    for (int i = 0; i < positions + 1; i++) {
        inputObjectString.setCharAt(i,' ');
    }
    inputObjectString.replace(" ","");
    inputObjectString.replace(",","");
    return inputObjectString;
}

int SerialChannel = 0;

void Serialprintln(String sendObject){
    if (privateSubGigKit::SerialChannel == 0) {
        Serial.println(sendObject);
    }
    else if (privateSubGigKit::SerialChannel == 1) {
        Serial1.println(sendObject);
    }
    else if (privateSubGigKit::SerialChannel == 2) {
        Serial2.println(sendObject);
    }
    else if (privateSubGigKit::SerialChannel == 3) {
        Serial3.println(sendObject);
    }
    else{
        Serial.println(sendObject);
    }
}

}

namespace SubGigKit{
void Serialbegin(int SerialChannel = 0){
    if (SerialChannel == 0) {
        Serial.begin(38400);
        Serial.setTimeout(5);
        privateSubGigKit::SerialChannel = 0;
    }
    else if(SerialChannel == 1){
        Serial1.begin(38400);
        Serial1.setTimeout(5);
        privateSubGigKit::SerialChannel = 1;
    }
    else if(SerialChannel == 2){
        Serial2.begin(38400);
        Serial2.setTimeout(5);
        privateSubGigKit::SerialChannel = 2;
    }
    else if(SerialChannel == 3){
        Serial3.begin(38400);
        Serial3.setTimeout(5);
        privateSubGigKit::SerialChannel = 3;
    }
    else{
        Serial.begin(38400);
        Serial.setTimeout(5);
        privateSubGigKit::SerialChannel = 0;
    }
    
}


void Serialprintln(int inputPrintObject , unsigned int address = 0){
    String sendObject = "TXDA" + SerialComsKit::Serialprint(inputPrintObject , address);
    privateSubGigKit::Serialprintln(sendObject);
}
void Serialprintln(double inputPrintObject, unsigned int address = 0){
    String sendObject = "TXDA" + SerialComsKit::Serialprint(inputPrintObject , address);
    privateSubGigKit::Serialprintln(sendObject);
}
void Serialprintln(unsigned int inputPrintObject, unsigned int address = 0){
    String sendObject = "TXDA" + SerialComsKit::Serialprint(inputPrintObject, address);
    privateSubGigKit::Serialprintln(sendObject);
}


int SerialreadString(String inputReadString,int swichValue,unsigned int address = 0){
    inputReadString = privateSubGigKit::edttingString(inputReadString);
    return SerialComsKit::SerialreadString(inputReadString,swichValue,address);
}
double SerialreadString(String inputReadString,double swichValue , unsigned int address = 0){
    inputReadString = privateSubGigKit::edttingString(inputReadString);
    return SerialComsKit::SerialreadString(inputReadString,swichValue,address);
}
unsigned int SerialreadString(String inputReadString,unsigned int swichValue , unsigned int address = 0){
    inputReadString = privateSubGigKit::edttingString(inputReadString);
    return SerialComsKit::SerialreadString(inputReadString,swichValue,address);
}
}
