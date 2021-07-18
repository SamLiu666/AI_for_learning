'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-18 16:43:55
LastEditors: lxp
LastEditTime: 2021-07-18 17:10:53
'''
import numpy as np
import paddle
from paddle.nn import Linear
import paddle.nn.functional as F


def sigmoid(x):
    # activation function: f(x) = 1 / (1 + e^(-x))
    return 1 / (1 + np.exp(-x))


class Neuron(object):
    def __init__(self, weights, bias):
        self.weights = weights
        self.bias = bias

    def forward(self, x):
        x = np.dot(self.weights, x) + self.bias
        x = sigmoid(x)
        return x


class Linear_np(object):
    def __init__(self, in_features, out_features, bias=True):
        self.weight = np.random.rand(in_features, out_features)
        if bias:
            self.bias = np.random.rand(in_features, 1)
        else:
            self.bias = np.random.zeros(in_features, 1)

    def step(self, x):
        x = np.dot(self.weight, x) + self.bias
        return x


class Linear_model(object):
    def __init__(self, in_features, out_features, bias=True):
        self.fc1 = Linear_np(in_features, out_features, bias)

    def forward(self, x):
        x = self.fc1.step(x)
        x = sigmoid(x)
        return x


weights = np.array([0, 1])  # w1 = 0, w2 = 1
bias = 4  # b = 4
n = Neuron(weights, bias)
linear_c = Linear_model(1, 2)

x = np.array([2, 3])  # x1 = 2, x2 = 3
print(n.forward(x))  # 0.9990889488055994
print(linear_c.forward(x))  # 0.9990889488055994
