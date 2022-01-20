'''
Author: [lxp]
Date: 2022-01-19 20:59:59
LastEditors: [lxp]
LastEditTime: 2022-01-19 21:14:07
Description: 
外观模式(Facade Pattern)：外部与一个子系统的通信必须通过一个统一的外观对象进行，为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。外观模式又称为门面模式，它是一种对象结构型模式。
'''

class SystemA(object):

    def operationA(self):
        print("SystemA")

class SystemB(object):

    def operationB(self):
        print("SystemB")

class Facade(object):

    def __init__(self):
        self.__a = SystemA()
        self.__b = SystemB()

    def wrapOperation(self):
        self.__a.operationA()
        self.__b.operationB()


if __name__ == '__main__':
    f = Facade()
    f.wrapOperation()