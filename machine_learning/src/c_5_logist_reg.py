'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-04 22:45:13
LastEditors: lxp
LastEditTime: 2021-07-10 10:08:11
'''
import numpy as np
import pandas as pd
import random
import math


class LogisticRegression_numpy(object):
    def __init__(self):
        self.learning_step = 0.00001
        self.max_iteration = 5000

    def predict_(self, x):
        wx = sum([self.w[j] * x[j] for j in range(len(self.w))])
        exp_wx = math.exp(wx)

        predict1 = exp_wx / (1 + exp_wx)
        predict0 = 1 / (1 + exp_wx)

        if predict1 > predict0:
            return 1
        else:
            return 0

    def fit(self, features, labels):
        self.w = [0.0] * (len(features[0]) + 1)

        correct_count = 0
        time = 0

        while time < self.max_iteration:
            index = random.randint(0, len(labels) - 1)
            x = list(features[index])
            x.append(1.0)
            y = labels[index]

            if y == self.predict_(x):
                correct_count += 1
                if correct_count > self.max_iteration:
                    break
                continue

            time += 1
            correct_count = 0

            wx = sum([self.w[i] * x[i] for i in range(len(self.w))])
            exp_wx = math.exp(wx)

            # 更新梯度
            for i in range(len(self.w)):
                self.w[i] -= self.learning_step * \
                    (-y * x[i] + float(x[i] * exp_wx) / float(1 + exp_wx))

    def predict(self, features):
        labels = []

        for feature in features:
            x = list(feature)
            x.append(1)
            labels.append(self.predict_(x))

        return labels


class Network_reg_np(object):
    def __init__(self, num_of_weights):
        # 随机产生w的初始值
        # 为了保持程序每次运行结果的一致性，
        # 此处设置固定的随机数种子
        np.random.seed(0)
        self.w = np.random.randn(num_of_weights, 1)
        self.b = 0.

    def forward(self, x):
        z = np.dot(x, self.w) + self.b
        return z

    def loss(self, z, y):
        error = z - y
        cost = error * error
        cost = np.mean(cost)
        return cost

    def gradient(self, x, y):
        z = self.forward(x)
        gradient_w = (z - y) * x
        # axis = 0 表示把每一行做相加然后再除以总的行数
        gradient_w = np.mean(gradient_w, axis=0)
        gradient_w = gradient_w[:, np.newaxis]
        gradient_b = (z - y)
        gradient_b = np.mean(gradient_b)
        return gradient_w, gradient_b

    def update(self, gradient_w, gradient_b, eta=0.01):
        self.w = self.w - eta * gradient_w
        self.b = self.b - eta * gradient_b

    def fit(self, x, y, iterations=100, eta=0.01, verbose=False):
        losses = []
        for i in range(iterations):
            z = self.forward(x)
            L = self.loss(z, y)
            gradient_w, gradient_b = self.gradient(x, y)
            self.update(gradient_w, gradient_b, eta)
            losses.append(L)
            if verbose:
                if (i + 1) % 100 == 0:
                    print('iter {}, loss {}'.format(i, L))
        return losses
    
    def predict(self, x):
        z = self.w * x + self.b
        