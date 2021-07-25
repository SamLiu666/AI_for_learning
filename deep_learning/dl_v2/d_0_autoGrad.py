'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-25 10:47:01
LastEditors: lxp
LastEditTime: 2021-07-25 15:10:59
'''
import torch

# 存储梯度 requeires_grad

x = torch.arange(4.0, requires_grad=True)
y = 2 * torch.dot(x, x)

y.backward()
print("a: ", y, x.grad, x.grad == 4 * x)
