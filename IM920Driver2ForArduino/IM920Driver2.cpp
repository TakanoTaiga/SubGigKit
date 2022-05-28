// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2021 Taiga Takano. All Rights Reserved.

#include <arduino.h>
#include "IM920Driver2Core.hpp"
#include "IM920Driver2.hpp"

void IM920Driver::PipelineStart() {
  IM920Driver2Core Core;
  Core.PipeLineStart();
  Serial1.begin(38400);
  while (!Serial1) {
    ;
  }
}


void IM920Driver::SendCommandINT() {
  IM920Driver2Core Core;
  Core.output_object_INT = OutputObjectINT;
  Core.output_size_INT = OutputSizeINT;
  char obj[256];
  Serial1.println(Core.send_command_INT());
}

void IM920Driver::SendCommandFP() {
  IM920Driver2Core Core;
  Core.output_object_FP = OutputObjectFP;
  Core.output_size_FP = OutputSizeFP;
  char obj[256];
  Serial1.println(Core.send_command_FP());
}

void IM920Driver::ReadCommand() {
  int i = 0;
  char inputDataChar[256];
  int16_t mem = 0;
  while(1){
    if(Serial1.available()){
      char index = Serial1.read();
      inputDataChar[i] = index;
      i++;
      if(index == '\n'){
        break;
      }
    }
  }
  //Serial.println(InputLAWData);
  
  IM920Driver2Core Core;

  Core.input_object_data = inputDataChar;
  Core.read_command();



  InputObjectINT = Core.input_object_INT;
  InputSizeINT = Core.input_size_INT;

  InputObjectFP = Core.input_object_FP;
  InputSizeFP = Core.input_size_FP;
}
