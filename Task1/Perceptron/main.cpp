#include <iostream>
#include "Perceptron.h"

using namespace std;

int main()
{

    Perceptron* perceptron=new Perceptron();
    int datas[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    int expected[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    //int datas[2][4]={{1,0,0,0},{0,1,0,0}};
    //int expected[2][4]={{1,0,0,0},{0,1,0,0}};

    perceptron->trainingProcess(datas,expected);
    cout<<"OUTPUT LAYER"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"Pattern number "<<i+1<<endl;
        for(int j=0;j<4;j++)
        {
            cout<<"Neuron "<<j+1<<": "<<perceptron->output->results[i][j]<<endl;
        }
        cout<<endl;
    }
    cout<<"-----------------------------"<<endl<<endl;
    cout<<"HIDDEN LAYER"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"Pattern number "<<i+1<<endl;
        for(int j=0;j<2;j++)
        {
            cout<<"Neuron "<<j+1<<": "<<perceptron->hidden->results[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}
