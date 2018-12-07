
#include"layer.h"
#include<vector>

Layer::Layer(int neuron_num,int input_num,string activation_)
{   num_inputs = input_num;
    activation = activation_;
    neurons_num = neuron_num;
    out.resize(neuron_num);
    for (int i = 0 ; i <neurons_num; i++)
    {
        neurons.push_back(Neuron(input_num,activation));
    }
}


void Layer::init_weights(const vector<vector<float> > w_initiate,const vector<float> biases)
{
    for (int i = 0 ; i < neurons_num; i++)
    {
        neurons[i].init(w_initiate[i],biases[i]);
    }
}

void Layer::calculate(const vector<float> input)
{
    for (int i = 0 ; i < neurons_num; i ++)
    {
        out[i] = neurons[i].calculate(input);
    }

}
vector<float> Layer::get_out(const vector<float> input)
{
    calculate(input);
    return out;
}

int Layer::get_neurons_num()
{
    return neurons_num;
}
