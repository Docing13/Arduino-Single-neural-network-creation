
#ifndef LAYER_H
#define LAYER_H
#include"neuron.h"
class Layer
{
    private:
        int num_inputs;
        string activation = "linear";
        int neurons_num;
        vector<float> out;
        vector<Neuron> neurons;

    public:
        Layer(){}
        Layer(int nuron_num,int input_num,string activation);

    
    void init_weights(const vector<vector<float> > ,const vector<float> biases );
    void calculate(const vector<float>);
    vector<float>  get_out(const vector<float>);
    int get_neurons_num();
};

#endif // LAYER_H


