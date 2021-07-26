'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-03 12:26:39
LastEditors: lxp
LastEditTime: 2021-07-26 21:08:57
'''
import random
import torch
from torch import nn


def setup_seed(seed):
    """设置随机种子"""
    torch.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)
    # np.random.seed(seed)
    random.seed(seed)
    torch.backends.cudnn.deterministic = True


def squared_loss(y_hat, y):
    """平方差误差实现"""
    return (y_hat - y.reshape(y_hat.shape))**2 / 2


def init_params():
    """初始化参数"""
    w = torch.normal(0, 1, size=(num_inputs, 1), requires_grad=True)
    b = torch.zeros(1, requires_grad=True)
    return [w, b]


def init_normal(m):
    """初始化参数 替换"""
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, mean=0, std=0.01)
        nn.init.zeros_(m.bias)


def xavier(m):
    if type(m) == nn.Linear:
        nn.init.xavier_uniform_(m.weight)


def init_42(m):
    if type(m) == nn.Linear:
        nn.init.constant_(m.weight, 42)


def relu(x):
    """relu激活函数"""
    a = torch.zeros_like(x)
    return torch.max(x, a)


def l2_penalty(w):
    """l2正则损失"""
    return torch.sum(w.pow(2)) // 2


def dropout_layer(x, droprate):
    """dropout实现"""
    assert 0 <= droprate <= 1
    if droprate == 1:
        return torch.zeros_like(x)
    if droprate == 0:
        return x
    mask = (torch.randn(x.shape) > droprate).float()
    return mask * x / (1.0 - droprate)


def get_k_fold_data(k, i, X, y):
    """k交叉验证"""
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
    """k交叉验证训练"""
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


if __name__ == '__main__':
    setup_seed(42)
