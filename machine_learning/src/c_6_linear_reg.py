'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-17 15:22:16
LastEditors: lxp
LastEditTime: 2021-07-17 19:41:38
'''
import paddle.nn as nn
import paddle


class LinearPaddleReg(nn.Layer):
    def __init__(self, input_features, output_features):
        super(LinearPaddleReg, self).__init__()
        self.fc1 = nn.Linear(input_features, output_features)

    def forward(self, x):
        x = self.fc1(x)
        return x


if __name__ == '__main__':
    from sklearn.datasets import make_regression
    data, labels = make_regression(100, 10, noise=0.1)
    linear_reg = LinearPaddleReg(10, 1)

    mse_loss = paddle.nn.loss.MSELoss()
    sgd = paddle.optimizer.SGD(learning_rate=0.001,
                               parameters=linear_reg.parameters())
    epochs = 20
    linear_reg.train()
    for epoch in range(epochs):
        batch_id = 0
        for batch_data, batch_label in zip(data, labels):
            batch_data = paddle.to_tensor(batch_data, dtype='float32')
            batch_label = paddle.to_tensor(batch_label, dtype='float32')

            predicts = linear_reg(batch_data)
            loss = mse_loss(predicts, batch_label)
            loss.backward()
            batch_id += 1
            if batch_id % 25 == 0:
                print("epoch: {}, batch_id: {}, loss is: {}".format(
                    epoch, batch_id, loss.numpy()))
            sgd.step()
            sgd.clear_grad()

    print("Done")