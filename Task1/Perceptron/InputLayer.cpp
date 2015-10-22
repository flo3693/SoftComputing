#include "InputLayer.h"

InputLayer::InputLayer()
{
    for(int i=0; i<4; i++)
    {
        inputNeurons[i]=new InputNeuron();
    }
}

InputLayer::~InputLayer()
{
}

void InputLayer::process(int inputs[4], int j)
{
    for(int i=0;i<4;i++)
    {
        this->results[j][i]=this->inputNeurons[i]->weightedSum(inputs[i]);
    }
}
