#include <arduino.h>

namespace SeriaComsKitAccessory {
String addressPrintController(unsigned int RawAddress) {
  if (RawAddress < 1000) {
    if (RawAddress != 0) {
      return "A" + String(RawAddress);
    }
    else {
      return "";
    }
  }
  else {
    return "";
  }
}

bool addressReadController(String inputRawObjectString, unsigned int address) {
  int finderA = inputRawObjectString.indexOf("A");
  if (finderA < 0) {
    return false;
  } else {
    if (address == 0) {
      return false;
    }
  }

  int finderE = inputRawObjectString.indexOf("E");
  String valueOfAddress = "";
  for (int i = 1 ; i < finderE - finderA ; i++) {
    valueOfAddress += inputRawObjectString.charAt(i + finderA);
  }

  if (valueOfAddress.toInt() == address) {
    return true;
  }
  else {
    return false;
  }
}
}


namespace SerialComsKit {
String Serialprint(int SerialPrintObject , unsigned int address = 0) {
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

  returnObject += SeriaComsKitAccessory::addressPrintController(address);

  return returnObject + "E0";
}

String Serialprint(double floatSerialPrintObject, unsigned int address = 0) {
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

  returnObject += SeriaComsKitAccessory::addressPrintController(address);

  return returnObject + "E0";
}

String Serialprint(unsigned int SerialPrintObject, unsigned int address = 0) {
  //flag obj
  String returnObject = "F5" + String(SerialPrintObject);

  returnObject += SeriaComsKitAccessory::addressPrintController(address);

  return returnObject + "E0";
}

int SerialreadString(String inputObjectString , int swichValue, unsigned int address = 0) {
  if (SeriaComsKitAccessory::addressReadController(inputObjectString, address)) {
    if (inputObjectString.indexOf("F1") >= 0) {
      inputObjectString.replace("F1", "");
      return inputObjectString.toInt();
    }
    else if (inputObjectString.indexOf("F2") >= 0) {
      inputObjectString.replace("F2", "");
      return inputObjectString.toInt() * -1;
    }
    else {
      return NULL;
    }
  }
}

double SerialreadString(String inputObjectString , double swichValue , unsigned int address = 0) {
  if (SeriaComsKitAccessory::addressReadController(inputObjectString, address)) {
    if (inputObjectString.indexOf("F3") >= 0) {
      inputObjectString.replace("F3", "");
      return inputObjectString.toDouble() / 1000;
    }
    else if (inputObjectString.indexOf("F4") >= 0) {
      inputObjectString.replace("F4", "");
      return inputObjectString.toDouble() * -1 / 1000;
    }
    else {
      return NULL;
    }
  }

}

unsigned int SerialreadString(String inputObjectString, unsigned int swichValue, unsigned int address = 0) {
  if (SeriaComsKitAccessory::addressReadController(inputObjectString, address)) {
    if (inputObjectString.indexOf("F5") >= 0) {
      inputObjectString.replace("F5", "");
      return (unsigned int)(inputObjectString.toInt());
    }
    else {
      return NULL;
    }
  }
}


}
