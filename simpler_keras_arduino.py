from keras.models import Sequential
from keras.layers import Dense
import numpy as np

f0 = open("datasetRoma1.txt","r").readlines()
f1 = open("datasetRoma2.txt","r").readlines()
t_arr = []
ans_arr = []
for i in f0:
    t_arr.append([float(i)])
    ans_arr.append([10,0])

for i in f1:
    t_arr.append([float(i)])
    ans_arr.append([0,10])
train_arr = np.array((t_arr))
answer_arr = np.array(ans_arr)

np.random.seed(1)
np.random.shuffle(train_arr)
np.random.seed(1)
np.random.shuffle(answer_arr)
model = Sequential()

model.add(Dense(2,activation='linear',input_dim=1))
model.add(Dense(100,activation='linear'))
model.add(Dense(50,activation='linear'))
model.add(Dense(2,activation='linear'))
model.compile(loss='MSE', optimizer='adam', metrics=['accuracy'])

model.fit(x=train_arr,y=answer_arr,batch_size=4,nb_epoch=10)

nn_file_w = open('arduino_dNNR_w.txt','w')
nn_file_b = open('arduino_dNNR_b.txt','w')
for layer in model.layers:

    layer_weights = layer.get_weights()[0]
    layer_biases = layer.get_weights()[1]

    for neuron_index in range(len(layer_weights[0])):
        for weight_index in range(len(layer_weights)):
            nn_file_w.write(str(layer_weights[weight_index][neuron_index]))
            nn_file_w.write(',')

    for bias in layer_biases:
        nn_file_b.write(str(bias))
        nn_file_b.write(',')

nn_file_w.close()
nn_file_b.close()
