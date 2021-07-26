'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-26 21:35:24
LastEditors: lxp
LastEditTime: 2021-07-26 21:43:41
'''
import torch
from torch import nn
from torch.nn import functional as F

x = torch.arange(4)
torch.save(x, 'x-file')

# 加载和保存模型参数


def direct_save():
    # 当网络结构发生改变的时候，用torch.save()保存的模型，在load的时候相比于state_dict会遇到一些麻烦，
    model = nn.Sequential(nn.Linear(10, 100), nn.ReLU(), nn.Linear(100, 10))
    torch.save(model, 'model.pt')
    m = torch.load('model.pt')


class MLP(nn.Module):
    def __init__(self):
        super().__init__()
        self.hidden = nn.Linear(20, 256)
        self.output = nn.Linear(256, 10)

    def forward(self, x):
        return self.output(F.relu(self.hidden(x)))


net = MLP()
X = torch.randn(size=(2, 20))
Y = net(X)

torch.save(net.state_dict(), 'mlp.params')
clone = MLP()
clone.load_state_dict(torch.load('mlp.params'))
clone.eval()
Y_clone = clone(X)
print(Y_clone == Y)
