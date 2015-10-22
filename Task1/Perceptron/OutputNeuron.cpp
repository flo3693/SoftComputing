#include "OutputNeuron.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string>
#include <math.h>

using namespace std;

OutputNeuron::OutputNeuron()
{

    string buff;
    double w1;
    double w2;
    srand(time(NULL));
    ifstream myfile ("weightLimits.txt");
    if(myfile.is_open())
    {
        getline(myfile, buff);
        w1=atof(buff.c_str());
        getline(myfile, buff);
        w2=atof(buff.c_str());
        for(int j=0;j<2;j++)
        {
            weights[j]=((w2-w1)/RAND_MAX)*rand()+w1;
        }
        weightBias=((w2-w1)/RAND_MAX)*rand()+w1;
    }
}

OutputNeuron::~OutputNeuron()
{
    //dtor
}

double OutputNeuron::weightedSum(double inputs[2])
{
    double result=0;
    for(int i=0;i<2;i++)
    {
        result+=this->weights[i]*inputs[i];
    }
    result+=weightBias; //Comment this line to remove Bias
    return result;
}

double OutputNeuron::activationFunction(double inputs[2])
{
    double result=0;
    double sum=weightedSum(inputs);
    result=1/(1+exp(-sum));
    return result;
}
