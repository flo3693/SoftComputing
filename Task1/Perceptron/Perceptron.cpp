#include "Perceptron.h"

Perceptron::Perceptron()
{

    output=new OutputLayer();
    hidden=new HiddenLayer();
    input=new InputLayer();
}

Perceptron::~Perceptron()
{
}

void Perceptron::trainingProcess(int datas[4][4],int expected[4][4])
{
    for(int j=0;j<80000;j++)
    {
        for(int i=0;i<4;i++)
        {
            // up phase
            input->process(datas[i],i);
            hidden->process(input, i);
            output->process(hidden, i);


            //backtrack
            updateErrorOutput(expected[i],i);
            updateErrorHidden(i);
            updateWeightsOutput(i);
            updateWeightsHidden(i);
        }
    }
}

void Perceptron::updateErrorOutput(int expected[4], int j)
{
    for(int i=0;i<4;i++)
    {
        output->errors[j][i]=(expected[i]-(output->results[j][i]))*derivativeFunction(output->outputNeurons[i]->weightedSum(hidden->results[j]));
    }
}

void Perceptron::updateErrorHidden(int j)
{
    for(int i=0;i<2;i++)
    {
        hidden->errors[j][i]=derivativeFunction(hidden->hiddenNeurons[i]->weightedSum(input->results[j]))*weightedErrorSum(i,j);
    }
}

void Perceptron::updateWeightsOutput(int k)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
            output->outputNeurons[i]->weights[j]+=0.1*(output->errors[k][i])*(hidden->results[k][j]);
        }
        output->outputNeurons[i]->weightBias+=0.1*(output->errors[k][i]);
    }
}

void Perceptron::updateWeightsHidden(int k)
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            hidden->hiddenNeurons[i]->weights[j]+=0.1*(hidden->errors[k][i])*(input->results[k][j]);
        }
        hidden->hiddenNeurons[i]->weightBias+=0.1*(hidden->errors[k][i]);
    }
}


double Perceptron::derivativeFunction(double sum)
{
    return ((exp(-sum))/(pow(1+exp(-sum),2)));
}

double Perceptron::weightedErrorSum(int i, int k)
{
    double sum=0;
    for(int j=0;j<4;j++)
    {
        sum+=(output->errors[k][j])*(output->outputNeurons[j]->weights[i]);
    }
    return sum;
}
