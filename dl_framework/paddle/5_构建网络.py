'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-16 22:31:03
LastEditors: lxp
LastEditTime: 2021-07-16 22:31:40
'''
import paddle

# Sequential形式组网
mnist = paddle.nn.Sequential(paddle.nn.Flatten(), paddle.nn.Linear(784, 512),
                             paddle.nn.ReLU(), paddle.nn.Dropout(0.2),
                             paddle.nn.Linear(512, 10))


# Layer类继承方式组网
class Mnist(paddle.nn.Layer):
    def __init__(self):
        super(Mnist, self).__init__()

        self.flatten = paddle.nn.Flatten()
        self.linear_1 = paddle.nn.Linear(784, 512)
        self.linear_2 = paddle.nn.Linear(512, 10)
        self.relu = paddle.nn.ReLU()
        self.dropout = paddle.nn.Dropout(0.2)

    def forward(self, inputs):
        y = self.flatten(inputs)
        y = self.linear_1(y)
        y = self.relu(y)
        y = self.dropout(y)
        y = self.linear_2(y)

        return y


mnist = Mnist()
