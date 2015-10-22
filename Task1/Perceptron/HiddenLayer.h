#include "HiddenNeuron.h"
#include "InputLayer.h"
#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H


class HiddenLayer
{
    public:
        HiddenNeuron* hiddenNeurons[2];
        double results[4][2];
        double errors[4][2];

        HiddenLayer();
        virtual ~HiddenLayer();

        void process(InputLayer* layer, int j);
};

#endif // HIDDENLAYER_H
