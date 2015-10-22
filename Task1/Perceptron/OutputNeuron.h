#ifndef OUTPUTNEURON_H
#define OUTPUTNEURON_H


class OutputNeuron
{
    public:
        double weights[2];
        double weightBias;

        OutputNeuron();
        virtual ~OutputNeuron();

        double weightedSum(double inputs[2]);
        double activationFunction(double inputs[2]);
};

#endif // OUTPUTNEURON_H
