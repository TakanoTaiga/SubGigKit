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
}


namespace SubGigKit{
  void Serialbegin(int SerialChannel = 0){
    Serial.begin(38400);
    Serial.setTimeout(5);
  }
  void Serialprintln(int inputPrintObject , unsigned int address = 0){
    String sendObject = "TXDA" + SerialComsKit::Serialprint(inputPrintObject , address);    
    Serial.println(sendObject);
  }
  void Serialprintln(double inputPrintObject, unsigned int address = 0){
    String sendObject = "TXDA" + SerialComsKit::Serialprint(inputPrintObject , address);      
    Serial.println(sendObject);
  }
  void Serialprintln(unsigned int inputPrintObject, unsigned int address = 0){
    String sendObject = "TXDA" + SerialComsKit::Serialprint(inputPrintObject, address);
    Serial.println(sendObject);
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
