'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-25 23:12:01
LastEditors: lxp
LastEditTime: 2021-07-25 23:41:17
'''
import torch


def softmax(x):
    x_exp = torch.exp(x)
    x_sum = x_exp.sum(1, keepdims=True)
    return x_exp / x_sum  # 广播机制


def cross_entropy(y_hat, y):
    return -torch.log(y_hat[range(len(y_hat)), y])


def accuracy(y_hat, y):
    y_hat = y_hat.argmax(axis=1)
    cmp_ = y_hat.type(y.dtype) == y
    return float(cmp_.type(y.dtype).sum())


x = torch.arange(6).reshape((2, 3))
print(x / x.sum(1, keepdims=True))
print("softmax func: ", softmax(x))

y = torch.tensor([0, 2])
y_hat = torch.tensor([[0.1, 0.2, 0.7], [0.3, 0.2, 0.5]])
print(y_hat[[0, 1], y])  # 拿出label中真实标号预测值
print("cross_entropy: ", cross_entropy(y_hat, y))
print("accuracy: ", accuracy(y_hat, y))

net = nn.Sequential(nn.Flatten(), nn.Linear(784, 10))

def init_weights(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, std=0.01)
        
net.apply(init_weights)
loss = nn.CrossEntropyLoss()
trainer = torch.optim.SGD(net.parameters(), lr=0.1)