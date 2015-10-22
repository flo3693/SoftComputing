#include "OutputLayer.h"
#include "HiddenLayer.h"
#include "InputLayer.h"
#include <math.h>

#ifndef PERCEPTRON_H
#define PERCEPTRON_H


class Perceptron
{
    public:
        InputLayer* input;
        HiddenLayer* hidden;
        OutputLayer* output;

        Perceptron();
        virtual ~Perceptron();

        void trainingProcess(int datas[4][4],int expected[4][4]);
        void updateErrorOutput(int expected[4], int j);
        void updateErrorHidden(int j);
        void updateWeightsOutput(int k);
        void updateWeightsHidden(int k);

        double derivativeFunction(double sum);
        double weightedErrorSum(int i, int k);
};

#endif // PERCEPTRON_H
