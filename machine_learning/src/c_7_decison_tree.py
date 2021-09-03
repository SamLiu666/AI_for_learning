'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-09-03 16:41:52
LastEditors: lxp
LastEditTime: 2021-09-03 16:45:01
'''
import numpy as np

# 条件熵


def cond_entropy(X, y, cond):
    N = len(y)
    cond_X = X[:, cond]
    tmp_entro = []
    for val in set(cond_X):
        tmp_y = y[np.where(cond_X == val)]
        tmp_entro.append(len(tmp_y)/N * entropy(tmp_y))
    cond_entro = sum(tmp_entro)
    return cond_entro

# 信息增益
def info_gain(X, y, cond):
    return entropy(y) - cond_entropy(X, y, cond)

# 信息增益比
def info_gain_ratio(X, y, cond):
    return (entropy(y) - cond_entropy(X, y, cond))/cond_entropy(X, y, cond)


def best_split(X, y, method='info_gain'):
    """根据method指定的方法使用信息增益或信息增益比来计算各个维度的最大信息增益（比），返回特征的axis"""
    _, M = X.shape
    info_gains = []
    if method == 'info_gain':
        split = info_gain
    elif method == 'info_gain_ratio':
        split = info_gain_ratio
    else:
        print('No such method')
        return
    for i in range(M):
        tmp_gain = split(X, y, i)
        info_gains.append(tmp_gain)
    best_feature = np.argmax(info_gains)

    return best_feature


class DecisionTreeClassifer:
    """
    决策树生成算法，
    method指定ID3或C4.5,两方法唯一不同在于特征选择方法不同
    info_gain:       信息增益即ID3
    info_gain_ratio: 信息增益比即C4.5
    """

    def __init__(self, threshold, method='info_gain'):
        self.threshold = threshold
        self.method = method

    def fit(self, X, y, labels):
        labels = labels.copy()
        M, N = X.shape
        if len(np.unique(y)) == 1:
            return y[0]

        if N == 1:
            return majorityCnt(y)

        bestSplit = best_split(X, y, method=self.method)
        bestFeaLable = labels[bestSplit]
        Tree = {bestFeaLable: {}}
        del (labels[bestSplit])

        feaVals = np.unique(X[:, bestSplit])
        for val in feaVals:
            idx = np.where(X[:, bestSplit] == val)
            sub_X = X[idx]
            sub_y = y[idx]
            sub_labels = labels
            Tree[bestFeaLable][val] = self.fit(sub_X, sub_y, sub_labels)

        return Tree
