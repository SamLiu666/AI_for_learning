'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-16 22:13:24
LastEditors: lxp
LastEditTime: 2021-07-16 22:24:54
'''
import time
import paddle.nn as nn
import paddle


class SimpleNet(nn.Layer):
    def __init__(self, input_size, output_size):
        super(SimpleNet, self).__init__()
        self.linear1 = nn.Linear(input_size, output_size)
        self.relu1 = nn.ReLU()
        self.linear2 = nn.Linear(input_size, output_size)
        self.relu2 = nn.ReLU()
        self.linear3 = nn.Linear(input_size, output_size)

    def forward(self, x):

        x = self.linear1(x)
        x = self.relu1(x)
        x = self.linear2(x)
        x = self.relu2(x)
        x = self.linear3(x)

        return x


# 开始时间
start_time = None


def start_timer():
    # 获取开始时间
    global start_time
    start_time = time.time()


def end_timer_and_print(msg):
    # 打印信息并输出训练时间
    end_time = time.time()
    print("\n" + msg)
    print("共计耗时 = {:.3f} sec".format(end_time - start_time))


epochs = 5
input_size = 4096  # 设为较大的值
output_size = 4096  # 设为较大的值
batch_size = 512  # batch_size 为8的倍数
nums_batch = 50

train_data = [
    paddle.randn((batch_size, input_size)) for _ in range(nums_batch)
]
labels = [paddle.randn((batch_size, output_size)) for _ in range(nums_batch)]

mse = paddle.nn.MSELoss()

# train
model = SimpleNet(input_size, output_size)  # 定义模型

optimizer = paddle.optimizer.SGD(learning_rate=0.0001,
                                 parameters=model.parameters())  # 定义优化器

start_timer()  # 获取训练开始时间

for epoch in range(epochs):
    datas = zip(train_data, labels)
    for i, (data, label) in enumerate(datas):

        output = model(data)
        loss = mse(output, label)

        # 反向传播
        loss.backward()

        # 训练模型
        optimizer.step()
        optimizer.clear_grad()

print(loss)
end_timer_and_print("默认耗时:")  # 获取结束时间并打印相关信息
