'''
Author: [lxp]
Date: 2022-01-19 20:38:19
LastEditors: [lxp]
LastEditTime: 2022-01-19 20:56:45
Description: 
装饰模式(Decorator Pattern) ：动态地给一个对象增加一些额外的职责(Responsibility)，就增加对象功能来说，装饰模式比生成子类实现更为灵活。其别名也可以称为包装器(Wrapper)，与适配器模式的别名相同，但它们适用于不同的场合。根据翻译的不同，装饰模式也有人称之为“油漆工模式”，它是一种对象结构型模式。
'''
from typing import Type

class Component(object):

    def operation(self):
        raise NotImplementedError

class ConcreteComponent(Component):

    def operation(self):
        print("Concrete Component operation")


class Decorator(Component):

    def __init__(self, c:Type[Component]):
        self.__component = c

    def operation(self):
        self.__component.operation()


class ConcreteDecoratorA(Decorator):

    def __init__(self, c:Type[Component]):
        self.__component = c
    
    def operation(self):
        self.__component.operation()
        print("Decorator A")
        self.addBehavior()
    
    def addBehavior(self):
        print("addBehavior A")

class ConcreteDecoratorB(Decorator):

    def __init__(self, c:Type[Component]):
        self.__component = c
    
    def operation(self):
        self.__component.operation()
        print("Decorator B")
        self.addBehavior()
    
    def addBehavior(self):
        print("addBehavior B")


if __name__ == "__main__":
    cc = ConcreteComponent()
    db = ConcreteDecoratorB(cc)
    da = ConcreteDecoratorA(db)

    da.operation()