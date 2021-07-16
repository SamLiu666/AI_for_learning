'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-16 20:44:06
LastEditors: lxp
LastEditTime: 2021-07-16 22:08:41
'''
import paddle

x = paddle.to_tensor([1.0, 2.0, 3.0], stop_gradient=False)
# 将b设置为需要计算梯度的属性
y = paddle.to_tensor([4.0, 5.0, 6.0], stop_gradient=False)
z = x**2 + 4 * y
print(x.stop_gradient)
print(y.stop_gradient)
z.backward()
print("Tensor x's grad is: {}".format(x.grad))
print("Tensor y's grad is: {}".format(y.grad))

# 3、因为backward()会累积梯度，所以飞桨还提供了clear_grad()函数来清除当前Tensor的梯度。
