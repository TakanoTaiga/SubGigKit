#include <arduino.h>

namespace SerialComsKit {
String Serialprint(int SerialPrintObject) {
  String returnObject = "";

  if (SerialPrintObject > 0) {
    //int+ , Format 1
    returnObject = String(SerialPrintObject);
    returnObject = "F1" + returnObject;
  }
  else {
    //int- , Format 2
    returnObject = String(SerialPrintObject * -1);
    returnObject = "F2" + returnObject;
  }
  return returnObject + "E0";
}

String Serialprint(double floatSerialPrintObject) {
  long intSerialPrintObject = (int)(floatSerialPrintObject * 1000);
  String returnObject = "";

  if (intSerialPrintObject > 0) {
    //float+ , Format 1
    returnObject = String(intSerialPrintObject);
    returnObject = "F3" + returnObject;
  }
  else {
    //float- , Format 2
    returnObject = String(intSerialPrintObject * -1);
    returnObject = "F4" + returnObject;
  }
  return returnObject + "E0";
}

String Serialprint(unsigned int SerialPrintObject){
  //flag obj
  String returnObject = "F5" + String(SerialPrintObject);
  return returnObject + "E0";
}

int SerialreadString(String inputObjectString , int swichValue){
  if(inputObjectString.indexOf("F1") >= 0){
    inputObjectString.replace("F1","");
    return inputObjectString.toInt();
  }
  else if (inputObjectString.indexOf("F2") >= 0){
    inputObjectString.replace("F2","");
    return inputObjectString.toInt() * -1;
  }
  else{
    return NULL;
  } 
}

double SerialreadString(String inputObjectString , double swichValue){
  if(inputObjectString.indexOf("F3") >= 0){
    inputObjectString.replace("F3","");
    return inputObjectString.toDouble() / 1000;
  }
  else if (inputObjectString.indexOf("F4") >= 0){
    inputObjectString.replace("F4","");
    return inputObjectString.toDouble() * -1 /1000;
  }
  else{
    return NULL;
  } 
}

unsigned int SerialreadString(String inputObjectString,unsigned int){
  if(inputObjectString.indexOf("F5") >= 0){
    inputObjectString.replace("F5","");
    return (unsigned int)(inputObjectString.toInt());
  }
  else{
    return NULL;
  }
}


}
