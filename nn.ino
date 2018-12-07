#include<ArduinoSTL.h>
#include "model_sequential.h"
#include <HCSR04.h>
using namespace std;
//model parameters
vector<float> weights = {-0.31067368,-0.22881195,0.22689581,0.13165164,-0.010496843,0.4764171,-0.94659835,1.0202132,0.8442791,-0.24612279,0.77709454,-0.13162349,-0.791735,-0.61199206};
vector<float> biases = {-0.24372041,0.5385593,1.5389773,-0.3779741,0.49061197,1.4268714,0.17543939};
//model imput dimenstion 
int input_dim = 1;
vector<float> input;
//model structure - put neurons number of every layer here
vector<int> model_structure = {2, 3, 2};
Sequential model = Sequential(input_dim);
UltraSonicDistanceSensor distanceSensor(13, 12);  // Initialize sensor that uses digital pins 13 and 12.

void setup() {
  
  model.add_layer(2,"linear");
  model.add_layer(3,"linear");
  model.add_layer(2,"linear");
  model.init(read_weights(input_dim, model_structure, weights),
             read_biases(model_structure, biases));
  Serial.begin(9600);
}
void loop() {
  input.clear();
  int iter_num = 5;
  float measured_data = distanceSensor.measureDistanceCm();
  for (int i = 0; i < iter_num; i++)
  { measured_data += distanceSensor.measureDistanceCm();
    delay(50);
  }
  measured_data /=5;
  input.push_back(measured_data);
  vector<float> ans = model.predict(input);
  if (ans[0]>ans[1])
  {
    Serial.println("stop");
  }
  else
  {
  Serial.println("go");  
    }
Serial.println("--------------");
}
