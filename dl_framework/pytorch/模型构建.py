'''
Description:
Version: 2.0
Autor: lxp
Date: 2021-07-26 20:27:53
LastEditors: lxp
LastEditTime: 2021-07-26 21:35:07
'''
import torch
import torch.nn as nn
import torch.nn.functional as F


def init_normal(m):
    """初始化参数 替换"""
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, mean=0, std=0.01)
        nn.init.zeros_(m.bias)


def init_42(m):
    if type(m) == nn.Linear:
        nn.init.constant_(m.weight, 42)


def xavier(m):
    if type(m) == nn.Linear:
        nn.init.xavier_uniform_(m.weight)


class MySequential(nn.Module):
    def __init__(self, *args):
        super().__init__()
        for block in args:
            self._modules[block] = block

    def forward(self, x):
        for block in self._modules.values():
            x = block(x)
        return x


class MLP(nn.Module):
    def __init__(self):
        super(MLP, self).__init__()
        self.hidden = nn.Linear(10, 256)
        self.out = nn.Linear(256, 10)

    def forward(self, x):
        return self.out(F.relu(self.hidden(x)))


def canshu_guanli(net):
    print("net: ", net)
    print("net[2].state_dict(): ", net[2].state_dict())

    # 一次性访问
    print(*[(name, param.shape) for name, param in net[0].named_parameters()])
    print(*[(name, param.shape) for name, param in net.named_parameters()])

    # 初始化
    # net.apply(xavier)
    net.apply(init_42)
    print("net[0].weight.data[0]: ", net[0].weight.data[0])


"""自定义层"""


class MyLayer(nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, x):
        return x - x.mean()


class MyLinear(nn.Module):
    def __init__(self, in_units, units):
        super().__init__()
        self.weight = nn.Parameter(torch.randn(in_units, units))
        self.bias = nn.Parameter(torch.randn(units,))

    def forward(self, X):
        linear = torch.matmul(X, self.weight.data) + self.bias.data
        return F.relu(linear)


if __name__ == '__main__':
    x = torch.rand(2, 10)
    # net = MLP()
    # net = MySequential(nn.Linear(10, 256), nn.ReLU(), nn.Linear(256, 10))
    net = nn.Sequential(nn.Linear(10, 256), nn.ReLU(), nn.Linear(256, 10))
    print(net(x))

    canshu_guanli(net)

    # 自定义层
    myl = MyLayer()
    print("mylayer: ", myl(torch.arange(6, dtype=torch.float32)))

    # 自定义层
    dense = MyLinear(5, 3)
    print(dense.weight)
