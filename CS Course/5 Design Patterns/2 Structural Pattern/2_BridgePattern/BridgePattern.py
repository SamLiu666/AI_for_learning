'''
Author: [lxp]
Date: 2022-01-19 20:25:19
LastEditors: [lxp]
LastEditTime: 2022-01-19 20:36:02
Description: 
桥接模式(Bridge Pattern)：将抽象部分与它的实现部分分离，使它们都可以独立地变化。它是一种对象结构型模式，又称为柄体(Handle and Body)模式或接口(Interface)模式。
'''

class Implementor(object):

    def action(self):
        raise NotImplementedError


class ConcreteImplementorA(Implementor):

    def action(self):
        print("Concrete Implementor A")


class ConcreteImplementorB(Implementor):

    def action(self):
        print("Concrete Implementor B")


class Abstraction(object):

    def operation(self):
        raise NotImplementedError

class RedifinedAbstraction(object):

    def __init__(self, implementor):
        self.__implementor = implementor

    def operation(self):
        self.__implementor.action()


if __name__ == '__main__':
    ia, ib = ConcreteImplementorA(), ConcreteImplementorB()

    ra = RedifinedAbstraction(ia)
    ra.operation()

    rb = RedifinedAbstraction(ib)
    rb.operation()

