#include "InputNeuron.h"
#ifndef INPUTLAYER_H
#define INPUTLAYER_H

class InputLayer
{
    public:
        InputNeuron* inputNeurons[4];
        double results[4][4];

        InputLayer();
        virtual ~InputLayer();
        void process(int inputs[4], int j);
};

#endif // INPUTLAYER_H
