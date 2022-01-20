'''
Author: [lxp]
Date: 2022-01-19 19:36:39
LastEditors: [lxp]
LastEditTime: 2022-01-19 19:42:35
Description: 
单例模式(Singleton Pattern)：单例模式确保某一个类只有一个实例，而且自行实例化并向整个系统提供这个实例，这个类称为单例类，它提供全局访问的方法。
单例模式的要点有三个：一是某个类只能有一个实例；二是它必须自行创建这个实例；三是它必须自行向整个系统提供这个实例。单例模式是一种对象创建型模式。单例模式又名单件模式或单态模式。
'''
def singleton(cls):
    _instance = {}

    def inner():
        if cls not in _instance:
            _instance[cls] = cls()
        return _instance[cls]
    return inner

@singleton
class Singleton(object):

    def __init__(self):
        pass 


if __name__ == '__main__':
    cls1 = Singleton()
    cls2 = Singleton()
    print(id(cls1) == id(cls2))