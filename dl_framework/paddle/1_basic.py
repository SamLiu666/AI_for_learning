'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-07-16 20:20:51
LastEditors: lxp
LastEditTime: 2021-07-16 20:48:13
'''
import numpy
import paddle

# 1 创建tensor
ndim_1_tensor = paddle.to_tensor([2.0, 3.0, 4.0], dtype='float64')
print("ndim_1_tensor: ", ndim_1_tensor)

ndim_2_tensor = paddle.to_tensor([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
print("ndim_2_tensor: ", ndim_2_tensor)

# 2 转为 numpy array
print("nd-arry: ", ndim_2_tensor.numpy())

ndim_2_tensor = paddle.to_tensor([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
print("ndim_2_tensor: ", ndim_2_tensor)

# 3 nd-array创建tensor -- 创建的 Tensor 与原 Numpy array 具有相同的 shape 与 dtype。
ndim_1_tensor = paddle.to_tensor(numpy.array([1.0, 2.0]))

ndim_2_tensor = paddle.to_tensor(numpy.array([[1.0, 2.0], [3.0, 4.0]]))

ndim_3_tensor = paddle.to_tensor(numpy.random.rand(3, 2))
ndim_4_tensor = paddle.ones([2, 3, 4, 5])

print("Data Type of every element:", ndim_4_tensor.dtype)
print("Number of dimensions:", ndim_4_tensor.ndim)
print("Shape of tensor:", ndim_4_tensor.shape)
print("Elements number along axis 0 of tensor:", ndim_4_tensor.shape[0])
print("Elements number along the last axis of tensor:",
      ndim_4_tensor.shape[-1])


#! 5、对shape进行操作
ndim_3_tensor = paddle.to_tensor([[[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]],
                                  [[11, 12, 13, 14, 15], [16, 17, 18, 19, 20]],
                                  [[21, 22, 23, 24, 25], [26, 27, 28, 29,
                                                          30]]])
print("the shape of ndim_3_tensor:", ndim_3_tensor.shape)
ndim_3_tensor = paddle.reshape(ndim_3_tensor, [2, 5, 3])
print("After reshape:", ndim_3_tensor.shape)

# ! 5、 cast接口来改变dtype
float32_tensor = paddle.to_tensor(1.0)

float64_tensor = paddle.cast(float32_tensor, dtype='float64')
print("Tensor after cast to float64:", float64_tensor.dtype)

int64_tensor = paddle.cast(float32_tensor, dtype='int64')
print("Tensor after cast to int64:", int64_tensor.dtype)

# ! 6、 Tensor的place
cpu_tensor = paddle.to_tensor(1, place=paddle.CPUPlace())
print(cpu_tensor)
pin_memory_tensor = paddle.to_tensor(1, place=paddle.CUDAPinnedPlace())
print(pin_memory_tensor)

gpu_tensor = paddle.to_tensor(1, place=paddle.CUDAPlace(0))
print(gpu_tensor)

#! 4、指定shape的Tensor
paddle.zeros([m, n])  # 创建数据全为0，shape为[m, n]的Tensor
paddle.ones([m, n])  # 创建数据全为1，shape为[m, n]的Tensor
paddle.full([m, n], 10)  # 创建数据全为10，shape为[m, n]的Tensor
paddle.arange(start, end, step)  # 创建从start到end，步长为step的Tensor
paddle.linspace(start, end, num)  # 创建从start到end，元素个数固定为num的Tensor

# ! 7 数学运算符
x.abs()  #逐元素取绝对值
x.ceil()  #逐元素向上取整
x.floor()  #逐元素向下取整
x.round()  #逐元素四舍五入
x.exp()  #逐元素计算自然常数为底的指数
x.log()  #逐元素计算x的自然对数
x.reciprocal()  #逐元素求倒数
x.square()  #逐元素计算平方
x.sqrt()  #逐元素计算平方根
x.sin()  #逐元素计算正弦
x.cos()  #逐元素计算余弦
x.add(y)  #逐元素相加
x.subtract(y)  #逐元素相减
x.multiply(y)  #逐元素相乘
x.divide(y)  #逐元素相除
x.mod(y)  #逐元素相除并取余
x.pow(y)  #逐元素幂运算
x.max()  #指定维度上元素最大值，默认为全部维度
x.min()  #指定维度上元素最小值，默认为全部维度
x.prod()  #指定维度上元素累乘，默认为全部维度
x.sum()  #指定维度上元素的和，默认为全部维度

# 线性代数相关
x.cholesky()  #矩阵的cholesky分解
x.t()  #矩阵转置
x.transpose([1, 0])  #交换axis 0 与axis 1的顺序
x.norm('fro')  #矩阵的Frobenius 范数
x.dist(y, p=2)  #矩阵（x-y）的2范数
x.matmul(y)  #矩阵乘法
