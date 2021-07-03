'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-03 14:18:28
LastEditors: lxp
LastEditTime: 2021-07-03 14:54:17
'''
import numpy as np
import random
import torch
from torch.nn import functional as F


class Perceptron_numpy(object):
    def __init__(self, max_iter=5000, eta=0.00001, verbose=True):
        self.eta_ = eta
        self.max_iter_ = max_iter
        self.w = 0
        self.verbose = verbose

    def fit(self, X, y):
        # self.w = np.zeros(X.shape[1] + 1)
        self.w = np.random.random(X.shape[1] + 1)
        # correct_count = 0
        n_iter_ = 0

        while n_iter_ < self.max_iter_:
            index = random.randint(0, y.shape[0] - 1)
            xx_ = np.hstack([X[index], 1])
            # for y∈\Y={0,1} case
            yy_ = 2 * y[index] - 1  # 变为0, 1
            wx = np.dot(self.w, xx_)

            # if wx * yy_ > 0:
            #     correct_count += 1
            #     if correct_count > self.max_iter_:
            #         logger.info(correct_count)
            #         break
            #     continue
            #
            # self.w += self.eta_ * yy_ * xx_
            # n_iter_ += 1
            # if self.verbose:
            #     print(n_iter_)
            # 上面这部分换个表达方式，希望更好理解
            if wx * yy_ <= 0:
                self.w += self.eta_ * yy_ * xx_
            n_iter_ += 1
            if self.verbose:
                print("epoch {}".format(n_iter_))

    def predict(self, X):
        # for b
        X = np.hstack([X, np.ones(X.shape[0]).reshape((-1, 1))])
        # activation function for perceptron: sign
        rst = np.array([1 if rst else -1 for rst in np.dot(X, self.w) > 0])
        # np.sign(0) == 0
        # rst = np.sign(np.dot(X, self.w))
        return rst


class Perceptron_torch(Perceptron_numpy):
    def fit(self, X, y):
        self.w = torch.randn(X.shape[1] + 1, dtype=np.float)
        n_iter_ = 0
        while n_iter_ < self.max_iter_:
            index = random.randint(0, y.shape[0] - 1)
            xx_ = np.hstack([X[index], 1])
            # for y∈\Y={0,1} case
            yy_ = 2 * y[index] - 1  # 变为0, 1
            wx = torch.dot(self.w, torch.tensor(xx_, dtype=np.float))
            if wx * yy_ <= 0:
                self.w += self.eta_ * yy_ * xx_
            n_iter_ += 1
            if self.verbose:
                print("epoch {}".format(n_iter_))
