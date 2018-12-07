#include<iostream>
#include"model_sequential.h"

Sequential::Sequential(int input_num_)
{
    input_num = input_num_;
}

void Sequential::add_layer(int neurons_num,string activation)
{
    //Layer::Layer(int neuron_num,int input_num,string activation_)//
    Layer l = Layer(neurons_num,input_num,activation);
    layers.push_back(l);
    input_num = neurons_num;
}

vector<float> Sequential::predict(vector<float> input_data)
{

   prediction = layers[0].get_out(input_data);

   for(int i = 1; i <layers.size(); i++)
   {
       prediction = layers[i].get_out(prediction);
   }
   return prediction;
}

void Sequential::init(const vector<vector<vector<float> > > w_initiate, const vector<vector<float>> biases)
{
    for (int i =0; i <layers.size(); i++)
    {
        layers[i].init_weights(w_initiate[i],biases[i]);
    }
}

vector<vector< float > > read_biases(vector<int> b_in_layers, vector<float> biases)
{   int bias_iterator = 0;
    vector<vector<float>> B;
    for (int l = 0; l<b_in_layers.size();l++)
    {
        vector<float> b;
        for (int neuron = 0; neuron < b_in_layers[l]; neuron++)
        {
            b.push_back(biases[bias_iterator]);
            bias_iterator += 1;
        }
        B.push_back(b);

    }
    return B;
}
vector<vector<vector<float > > > read_weights(int num_input_,vector<int> w_in_layers, vector<float> weights)
{
    int weight_iterator = 0;
    int input = num_input_;

    vector<vector<vector<float > > > W;
    for(int layer = 0; layer < w_in_layers.size(); layer++)
    {   //generating layer
        vector<vector<float>> L;

        for(int neuron = 0; neuron< w_in_layers[layer]; neuron ++)
        {
            //generating neuron
            vector<float> neuron_w;
            for (int w =0; w < input; w++)
            {   
           
                neuron_w.push_back(weights[weight_iterator]);
                weight_iterator +=1 ;

            }

            L.push_back(neuron_w);

        }
        input = w_in_layers[layer];
        W.push_back(L);
    }

    return W;
}
