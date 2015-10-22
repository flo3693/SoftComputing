#ifndef INPUT_NEURON_H
#define INPUT_NEURON_H

class InputNeuron
{
public:
        int weight;
        InputNeuron();
        virtual ~InputNeuron();
        double weightedSum(double input);
};

#endif // INPUT_NEURON_H
