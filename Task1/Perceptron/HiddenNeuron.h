#ifndef HIDDENNEURON_H
#define HIDDENNEURON_H


class HiddenNeuron
{
    public:
        double weights[4];
        double weightBias;

        HiddenNeuron();
        virtual ~HiddenNeuron();

        double weightedSum(double inputs[4]);
        double activationFunction(double inputs[4]);
};

#endif // HIDDENNEURON_H
