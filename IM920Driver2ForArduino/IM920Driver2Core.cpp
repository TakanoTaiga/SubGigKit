// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2021 Taiga Takano. All Rights Reserved.

#include <arduino.h>
#include "IM920Driver2Core.hpp"

void IM920Driver2Core::PipeLineStart() {
  int16_t clearINT[2] = {0};
  output_object_INT = &clearINT[0];
  float clearFP[2] = {0, 0};
  output_object_FP = &clearFP[0];
}

String IM920Driver2Core::send_command_INT() {
  String all_returns = "TXDA"; //return object

  for (int16_t i = 0; i < output_size_INT; i++) {
    if (*(output_object_INT + i) > 0) {
      String object_Flag = "F1"; //Object Type
      String object_Data = String(*(output_object_INT + i)); //Object Data

      all_returns = all_returns + object_Flag + object_Data; //Make && Make
    }
    else if (*(output_object_INT + i) < 0) {
      String object_Flag = "F2"; //Object Type
      String object_Data = String(*(output_object_INT + i) * -1); //Object Data

      all_returns = all_returns + object_Flag + object_Data; //Make && Make
    }
    else {
      all_returns = all_returns + "F00"; //Make && Make
    }
  }
  all_returns += "E0\n"; //END marker

  return (all_returns);
}

String IM920Driver2Core::send_command_FP() {
  String all_returns = "TXDA";

  for (int16_t i = 0; i < output_size_FP; i++) {
    if (*(output_object_FP + i) > 0) {
      String object_Flag = "F3"; //Object Type
      int16_t object_data_int = (int) * (output_object_FP + i);
      int16_t object_data_fp = (int)((*(output_object_FP + i) - (int) * (output_object_FP + i)) * 1000);

      all_returns = all_returns + object_Flag + String(object_data_int) + "C" + String(object_data_fp);
    }
    else if (*(output_object_FP + i) < 0) {
      String object_Flag = "F4"; //Object Type
      int16_t object_data_int = (int) * (output_object_FP + i) * -1;
      int16_t object_data_fp = ((int)((*(output_object_FP + i) - (int) * (output_object_FP + i)) * 1000)) * -1;

      all_returns = all_returns + object_Flag + String(object_data_int) + "C" + String(object_data_fp);
    }
    else {
      all_returns = all_returns + "F00"; //Make && Make
    }
  }
  all_returns += "E0\n"; //END marker

  return (all_returns);
}

void IM920Driver2Core::read_command() {
  String object_data = ""; //Optimized Data
  for (int32_t i = 11; input_object_data[i] != 'E'; i++) {
    if (input_object_data[i] != ',') {
      object_data += input_object_data[i];
    }
  }
  object_data += 'E';

  int32_t counter = 0;
  for (int32_t i = 0; object_data[i] != 'E'; i++) {
    if (object_data[i] == 'F') {
      String task; //String Number ex("12345")
      int32_t JG = 0; //Global 'j'

      switch (object_data[i + 1]) {
        case '0':
          INT_LAW_DATA[counter] = 0;
          counter++;
          break;

        case '1':
          //---F1--- (int +)
          task = "";

          for (int32_t j = i + 2; object_data[j] != 'F' && object_data[j] != 'E'; j++) {
            task += object_data[j];
          }
          task += "\n";

          INT_LAW_DATA[counter] = task.toInt();
          //std::cout << INT_LAW_DATA[counter];
          counter++;
          break;

        case '2':
          //---F2--- (int -)
          task = "";

          for (int32_t j = i + 2; object_data[j] != 'F' && object_data[j] != 'E'; j++) {
            task += object_data[j];
          }
          task += "\n";

          INT_LAW_DATA[counter] = task.toInt() * -1;
          counter++;
          break;

        case '3':
          //---F3--- (FP +)
          task = "";
          for (JG = i + 2; object_data[JG] != 'C'; JG++) {
            task += object_data[JG];
          }
          task += ".";
          for (int32_t j = JG + 1; object_data[j] != 'F' && object_data[j] != 'E'; j++) {
            task += object_data[j];
          }
          FP_LAW_DATA[counter] = task.toFloat();
          counter++;
          break;

        case '4':
          //---F4--- (FP -)
          task = "";

          for (JG = i + 2; object_data[JG] != 'C'; JG++) {
            task += object_data[JG];
          }
          task += ".";
          for (int32_t j = JG + 1; object_data[j] != 'F' && object_data[j] != 'E'; j++) {
            task += object_data[j];
          }
          FP_LAW_DATA[counter] = task.toFloat() * -1;
          counter++;
          break;

        default:
          //Error
          break;
      }
    }
  }

  input_object_INT = &INT_LAW_DATA[0];
  input_object_FP = &FP_LAW_DATA[0];
}
