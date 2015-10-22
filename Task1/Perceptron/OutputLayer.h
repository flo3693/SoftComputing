#include "HiddenLayer.h"
#include "InputLayer.h"
#include "OutputNeuron.h"
#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H


class OutputLayer
{
    public:
        OutputNeuron* outputNeurons[4];
        double results[4][4];
        double errors[4][4];

        OutputLayer();
        virtual ~OutputLayer();

        void process(HiddenLayer* layer, int j);
};

#endif // OUTPUTLAYER_H
