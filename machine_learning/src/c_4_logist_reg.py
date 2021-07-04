'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-04 22:45:13
LastEditors: lxp
LastEditTime: 2021-07-04 22:48:27
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
