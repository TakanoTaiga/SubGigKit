// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2021 Taiga Takano. All Rights Reserved.

class IM920Driver{
public:
    //---Piepeline---//
    void PipelineStart();
    
    //---Send command---//
    int8_t Channel = 1;

    void SendCommandINT();
    void SendCommandFP();
        
    int16_t *OutputObjectINT;
    int8_t OutputSizeINT = 0;
    
    float *OutputObjectFP;
    int8_t OutputSizeFP = 0;
    
    //---Read command---//
    void ReadCommand();
    
    int8_t InputSizeINT = 0;
    int16_t *InputObjectINT;
    
    int8_t InputSizeFP = 0;
    float *InputObjectFP;
    
    String InputLAWData = "";
};
