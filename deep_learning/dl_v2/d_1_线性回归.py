'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-25 15:11:50
LastEditors: lxp
LastEditTime: 2021-07-25 16:11:25
'''
import random
import torch
import sklearn
import matplotlib.pyplot as plt
import torch.nn as nn


def setup_seed(seed):
    torch.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)
    # np.random.seed(seed)
    random.seed(seed)
    torch.backends.cudnn.deterministic = True


# 设置随机数种子
setup_seed(42)


# 构造数据集
def make_data(w, b, num_examples):
    '''
    @description: y = wx + b + noise
    @param {*}
    @return {*}
    '''
    X = torch.normal(0, 1, (num_examples, len(w)))
    y = torch.matmul(X, w) + b
    noise = torch.normal(0, 0.01, y.shape)
    return X, y.reshape((-1, 1))


def data_iter(batch_size, features, labels):
    num_examples = len(features)
    indices = list(range(num_examples))

    # 随机读取
    random.shuffle(indices)
    for i in range(0, num_examples, batch_size):
        batch_indices = torch.tensor(indices[i:min(i +
                                                   batch_size, num_examples)])
        yield features[batch_indices], labels[batch_indices]


def linreg(X, w, b):
    return torch.matmul(X, w) + b


def squared_loss(y_hat, y):
    return (y_hat - y.reshape(y_hat.shape))**2 / 2


def sgd(params, lr, batch_size):
    # 小批量梯度下降
    with torch.no_grad():
        for param in params:
            param -= lr * param.grad / batch_size
            param.grad.zero_()


true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = make_data(true_w, true_b, 1000)
# plt.scatter(features[:, 1].detach().numpy(), labels.detach().numpy(), 1)
# plt.show()

batch_size = 10
for X, y in data_iter(batch_size, features, labels):
    print(X, "\n", y)
    break

# 随机初始化参数
w = torch.normal(0, 0.01, size=(2, 1), requires_grad=True)
b = torch.zeros(1, requires_grad=True)

lr = 0.03
num_epochs = 3
# net = linreg
# loss = squared_loss
net = nn.Sequential(nn.Linear(2, 1))
net[0].weight.data.normal_(0, 0.01)
net[0].bias.data.fill_(0)
loss = nn.MSELoss()
opt = torch.optim.SGD(net.parameters(), lr=0.03)

for epoch in range(num_epochs):
    for X, y in data_iter(batch_size, features, labels):
        # y_hat = net(X, w, b)
        # train_loss = loss(y_hat, y)
        # train_loss.sum().backward()
        # sgd([w, b], lr, batch_size)
        # with torch.no_grad():
        #     train_l = loss(net(features, w, b), labels)
        #     print(f'epoch {epoch + 1}, loss {float(train_l.mean())}')
        y_hat = net(X)
        train_loss = loss(y_hat, y)  # 计算loss
        opt.zero_grad()  # 梯度清零
        train_loss.backward()  # torch 已经求和，计算backward
        opt.step()  # 更新参数
    train_l = loss(net(features), labels)
    # print(f'epoch {epoch + 1}, loss {train_l:f}')
    print(f'epoch {epoch + 1}, loss {train_l}')

print("线性回归 done")