'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-26 00:04:42
LastEditors: lxp
LastEditTime: 2021-07-26 20:06:30
'''
import torch
import torch.nn as nn


def init_params():
    w = torch.normal(0, 1, size=(num_inputs, 1), requires_grad=True)
    b = torch.zeros(1, requires_grad=True)
    return [w, b]


def relu(x):
    a = torch.zeros_like(x)
    return torch.max(x, a)


def l2_penalty(w):
    return torch.sum(w.pow(2)) // 2


def dropout_layer(x, droprate):
    assert 0 <= droprate <= 1
    if droprate == 1:
        return torch.zeros_like(x)
    if droprate == 0:
        return x
    mask = (torch.randn(x.shape) > droprate).float()
    return mask * x / (1.0 - droprate)


def get_k_fold_data(k, i, X, y):
    assert k > 1
    fold_size = X.shape[0] // k
    X_train, y_train = None, None
    for j in range(k):
        idx = slice(j * fold_size, (j + 1) * fold_size)
        X_part, y_part = X[idx, :], y[idx]
        if j == i:
            X_valid, y_valid = X_part, y_part
        elif X_train is None:
            X_train, y_train = X_part, y_part
        else:
            X_train = torch.cat([X_train, X_part], 0)
            y_train = torch.cat([y_train, y_part], 0)
    return X_train, y_train, X_valid, y_valid


def k_fold(k, X_train, y_train, num_epochs, learning_rate, weight_decay,
           batch_size):
    train_l_sum, valid_l_sum = 0, 0
    for i in range(k):
        data = get_k_fold_data(k, i, X_train, y_train)
        net = get_net()
        train_ls, valid_ls = train(net, *data, num_epochs, learning_rate,
                                   weight_decay, batch_size)
        train_l_sum += train_ls[-1]
        valid_l_sum += valid_ls[-1]
        if i == 0:
            d2l.plot(list(range(1, num_epochs + 1)), [train_ls, valid_ls],
                     xlabel='epoch',
                     ylabel='rmse',
                     xlim=[1, num_epochs],
                     legend=['train', 'valid'],
                     yscale='log')
        print(f'fold {i + 1}, train log rmse {float(train_ls[-1]):f}, '
              f'valid log rmse {float(valid_ls[-1]):f}')
    return train_l_sum / k, valid_l_sum / k


# trainer = torch.optim.SGD()

num_inputs, num_outputs, num_hiddens = 784, 10, 256
W1 = nn.Parameter(torch.rand(num_inputs, num_hiddens, requires_grad=True))
b1 = nn.Parameter(torch.zeros(num_hiddens, requires_grad=True))

net = nn.Sequential(nn.Flatten(), nn.Linear(784, 256), nn.ReLU(),
                    nn.Linear(256, 10))

x = torch.arange(16).reshape((2, 8))
print(x)
print(dropout_layer(x, 0.1))
print(dropout_layer(x, 0))
print(dropout_layer(x, 1))