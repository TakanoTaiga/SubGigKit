// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2021 Taiga Takano. All Rights Reserved.

#include <arduino.h>

class IM920Driver2Core
{
public:
    //---Pipe Line---//
    void PipeLineStart();
    
    //---Send Command---//
    String send_command_INT(); //Send command
    String send_command_FP(); //Send command
    
    int16_t *output_object_INT; //Integer object to send
    int8_t output_size_INT = 0; //INT object size
    
    float *output_object_FP; //FP object to send
    int8_t output_size_FP = 0; //FP object size
    
    //---Read Command---//
    void read_command();
    
    int8_t input_size_INT = 0;
    int16_t *input_object_INT;
    
    int8_t input_size_FP = 0;
    float *input_object_FP;
    
    String input_object_data = "";
    
private:
    int16_t INT_LAW_DATA[64] = {0};
    float FP_LAW_DATA[64] = {0};
};
