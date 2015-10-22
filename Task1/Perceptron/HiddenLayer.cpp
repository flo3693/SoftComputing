#include "HiddenLayer.h"

HiddenLayer::HiddenLayer()
{
    for(int i=0;i<2;i++)
    {
        hiddenNeurons[i]= new HiddenNeuron();
    }
}

HiddenLayer::~HiddenLayer()
{
    //dtor
}

void HiddenLayer::process(InputLayer* layer, int j)
{
    double inputs[4];
    for(int i=0;i<4;i++)
    {
        inputs[i]=layer->results[j][i];
    }
    for(int i=0;i<2;i++)
    {
        this->results[j][i]=this->hiddenNeurons[i]->activationFunction(inputs);
    }
}
