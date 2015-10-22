#include "OutputLayer.h"

OutputLayer::OutputLayer()
{
    for(int i=0; i<4; i++)
    {
        outputNeurons[i]=new OutputNeuron();
    }
}

OutputLayer::~OutputLayer()
{
    //dtor
}

void OutputLayer::process(HiddenLayer* layer, int j)
{
    double inputs[2];
    for(int i=0;i<2;i++)
    {
        inputs[i]=layer->results[j][i];
    }

    for(int i=0;i<4;i++)
    {
        this->results[j][i]=this->outputNeurons[i]->activationFunction(inputs);
    }
}

