'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-03 15:47:45
LastEditors: lxp
LastEditTime: 2021-07-05 22:48:15
'''
import numpy as np
import random
from collections import namedtuple
from pprint import pformat
from sklearn.neighbors import NearestNeighbors


class Knn_sk(NearestNeighbors):
    def __init__(self, k=3):
        super().__init__()
        self.n_neighbors = 3

    def predict(self, X):
        pass


class KNN_numpy(object):
    def __init__(self, k=3):
        self.k = k

    def fit(self, X, y):
        '''
        @description: knn 不需要训练，值传递
        @param {*}
        @return {*}
        '''
        self.data = X
        self.label = y

    def predict(self, X):
        trainset = self.data
        train_labels = self.label
        k = self.k
        testset = X
        ans = []
        for test_vec in testset:
            knn_list = []  # 当前k个最近邻居
            max_index = -1  # 当前k个最近邻居中距离最远点的坐标
            max_dist = 0  # 当前k个最近邻居中距离最远点的距离

            # 先将前k个点放入k个最近邻居中，填充满knn_list
            for i in range(k):
                label = train_labels[i]
                train_vec = trainset[i]

                dist = np.linalg.norm(train_vec - test_vec)  # 计算两个点的欧氏距离

                knn_list.append((dist, label))

            # 剩下的点
            for i in range(k, len(train_labels)):
                label = train_labels[i]
                train_vec = trainset[i]

                dist = np.linalg.norm(train_vec - test_vec)  # 计算两个点的欧氏距离

                # 寻找k个邻近点钟距离最远的点
                if max_index < 0:
                    for j in range(k):
                        if max_dist < knn_list[j][0]:
                            max_index = j
                            max_dist = knn_list[max_index][0]

                # 如果当前k个最近邻居中存在点距离比当前点距离远，则替换
                if dist < max_dist:
                    knn_list[max_index] = (dist, label)
                    max_index = -1
                    max_dist = 0

            # 统计选票
            class_total = k
            class_count = [0 for i in range(class_total)]
            for dist, label in knn_list:
                class_count[label] += 1

            # 找出最大选票
            mmax = max(class_count)

            # 找出最大选票标签
            for i in range(class_total):
                if mmax == class_count[i]:
                    ans.append(i)
                    break

        return np.array(ans)


class Node(namedtuple('Node', 'location left_child right_child')):
    def __repr__(self):
        return pformat(tuple(self))


class KNN(KNN_numpy):
    '''
    @description:  kd tree
    @param {*} self
    @param {*} k
    @param {*} p
    @return {*}
    '''
    def __init__(self, k=3, p=2):
        """
        :param k: knn
        :param p:
        """
        self.k = k
        self.p = p
        self.kdtree = None

    @staticmethod
    def _fit(X, depth=0):
        try:
            k = X.shape[1]
        except IndexError as e:
            return None
        # todo: 这里可以展开，通过方差选择
        axis = depth % k
        X = X[X[:, axis].argsort()]
        median = X.shape[0] // 2

        try:
            X[median]
        except IndexError:
            return None

        return Node(location=X[median],
                    left_child=KNN._fit(X[:median], depth + 1),
                    right_child=KNN._fit(X[median + 1:], depth + 1))

    def _distance(self, x, y):
        return np.linalg.norm(x - y, ord=self.p)

    def _search(self, point, tree=None, depth=0, best=None):
        if tree is None:
            return best

        k = point.shape[0]
        # update best
        if best is None or self._distance(
                point, tree.location) < self._distance(best, tree.location):
            next_best = tree.location
        else:
            next_best = best

        # update branch
        if point[depth % k].all() < tree.location[depth % k].all():
            next_branch = tree.left_child
        else:
            next_branch = tree.right_child
        return self._search(point,
                            tree=next_branch,
                            depth=depth + 1,
                            best=next_best)

    def fit(self, X, y):
        self.kdtree = KNN._fit(X)
        return self.kdtree

    def predict(self, X):
        rst = self._search(X, self.kdtree)
        return rst

    def predict_proba(self, X):
        pass