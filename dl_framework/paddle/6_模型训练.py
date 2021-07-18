'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-16 22:31:48
LastEditors: lxp
LastEditTime: 2021-07-17 19:32:38
'''
import paddle
from paddle.vision.transforms import ToTensor

train_dataset = paddle.vision.datasets.MNIST(mode='train',
                                             transform=ToTensor())
test_dataset = paddle.vision.datasets.MNIST(mode='test', transform=ToTensor())
lenet = paddle.vision.models.LeNet()

# Mnist继承paddle.nn.Layer属于Net，model包含了训练功能
model = paddle.Model(lenet)

# 设置训练模型所需的optimizer, loss, metric
model.prepare(
    paddle.optimizer.Adam(learning_rate=0.001, parameters=model.parameters()),
    paddle.nn.CrossEntropyLoss(), paddle.metric.Accuracy())

# 启动训练
model.fit(train_dataset, epochs=2, batch_size=64, log_freq=200)

# 启动评估
model.evaluate(test_dataset, log_freq=20, batch_size=64)

# ! 基础 API 训练
train_dataset = paddle.vision.datasets.MNIST(mode='train',
                                             transform=ToTensor())
test_dataset = paddle.vision.datasets.MNIST(mode='test', transform=ToTensor())
lenet = paddle.vision.models.LeNet()
loss_fn = paddle.nn.CrossEntropyLoss()

# 加载训练集 batch_size 设为 64
train_loader = paddle.io.DataLoader(train_dataset, batch_size=64, shuffle=True)
mnist.train()


# mnist.eval()
def train():
    epochs = 2
    adam = paddle.optimizer.Adam(learning_rate=0.001,
                                 parameters=lenet.parameters())
    
    # 用Adam作为优化函数
    for epoch in range(epochs):
        for batch_id, data in enumerate(train_loader()):
            x_data = data[0]
            y_data = data[1]
            predicts = lenet(x_data)
            acc = paddle.metric.accuracy(predicts, y_data)
            loss = loss_fn(predicts, y_data)
            loss.backward()
            if batch_id % 100 == 0:
                print(
                    "epoch: {}, batch_id: {}, loss is: {}, acc is: {}".format(
                        epoch, batch_id, loss.numpy(), acc.numpy()))

            adam.step()
            adam.clear_grad()


# 启动训练
train()