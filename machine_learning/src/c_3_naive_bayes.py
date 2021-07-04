'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-04 14:13:23
LastEditors: lxp
LastEditTime: 2021-07-04 15:14:19
'''
import numpy as np
import pandas as pd
from collections import defaultdict


class Native_Bayes(object):
    def __init__(self):
        self.y = []  #标签集合
        self.x = []  #每个属性的数值集合
        self.py = defaultdict(float)  #标签的概率分布
        self.pxy = defaultdict(dict)  #每个标签下的每个属性的概率分布
        self.n = 5  #分级的级数

    def prob(self, element, arr):
        '''
        计算元素在列表中出现的频率
        '''
        prob = 0.0
        for a in arr:
            if element == a:
                prob += 1 / len(arr)
        if prob == 0.0:
            prob = 0.001
        return prob

    def fit(self, x, y):
        '''
        训练模型
        '''
        self.y = y
        #1. 获取p(y)
        for yi in self.y:
            self.py[yi] = self.prob(yi, y)
        #2. 获取p(x|y)
        for yi in self.y:
            for i in range(x.shape[1]):
                sample = x[y == yi, i]  #标签yi下的样本
                #获取该列的概率分布
                pxy = [self.prob(xi, sample) for xi in self.x[i]]
                self.pxy[yi][i] = pxy
        print("train score", self.score(x, y))

    def predict_one(self, x):
        '''
        预测单个样本
        '''
        max_prob = 0.0
        max_yi = self.y[0]
        for yi in self.y:
            prob_y = self.py[yi]
            for i in range(len(x)):
                prob_x_y = self.pxy[yi][i][self.x[i].index(x[i])]  #p(xi|y)
                prob_y *= prob_x_y  #计算p(x1|y)p(x2|y)...p(xn|y)p(y)
            if prob_y > max_prob:
                max_prob = prob_y
                max_yi = yi
        return max_yi

    def predict(self, X):
        '''
        预测函数
        '''
        y_list = []
        for m in range(X.shape[0]):
            yi = self.predict_one(X[m, :])
            y_list.append(yi)
        return np.array(y_list)

    def preprocess(self, x):
        '''
        因为不同特征的数值集大小相差巨大，造成部分概率矩阵变得稀疏，需要进行数据分割
        '''
        for i in range(x.shape[1]):
            x[:, i] = self.step(x[:, i], self.n)
        return x

    def step(self, arr, n):
        '''
        分为n阶
        '''
        ma = max(arr)
        mi = min(arr)
        for i in range(len(arr)):
            for j in range(n):
                a = mi + (ma - mi) * (j / n)
                b = mi + (ma - mi) * ((j + 1) / n)
                if arr[i] >= a and arr[i] <= b:
                    arr[i] = j + 1
                    break
        return arr