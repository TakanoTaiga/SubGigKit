#include <arduino.h>
#include <SerialComsKit.hpp>

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
  void Serialprintln(int inputPrintObject){
    String sendObject = "TXDA" + SerialComsKit::Serialprint(inputPrintObject);
    Serial.println(sendObject);
  }
  void Serialprintln(double inputPrintObject){
    String sendObject = "TXDA" + SerialComsKit::Serialprint(inputPrintObject);
    Serial.println(sendObject);
  }
  void Serialprintln(unsigned int inputPrintObject){
    String sendObject = "TXDA" + SerialComsKit::Serialprint(inputPrintObject);
    Serial.println(sendObject);
  }

  int SerialreadString(String inputReadString,int swichValue){
    
    inputReadString = privateSubGigKit::edttingString(inputReadString);
    return SerialComsKit::SerialreadString(inputReadString,swichValue);
  }
  double SerialreadString(String inputReadString,double swichValue){
    inputReadString = privateSubGigKit::edttingString(inputReadString);
    return SerialComsKit::SerialreadString(inputReadString,swichValue);
  }
  unsigned int SerialreadString(String inputReadString,unsigned int swichValue){
    inputReadString = privateSubGigKit::edttingString(inputReadString);
    return SerialComsKit::SerialreadString(inputReadString,swichValue);
  }
}
