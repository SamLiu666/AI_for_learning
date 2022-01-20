'''
Author: [lxp]
Date: 2022-01-19 19:52:01
LastEditors: [lxp]
LastEditTime: 2022-01-19 20:09:33
Description: 
适配器模式(Adapter Pattern) ：将一个接口转换成客户希望的另一个接口，适配器模式使接口不兼容的那些类可以一起工作，其别名为包装器(Wrapper)。适配器模式既可以作为类结构型模式，也可以作为对象结构型模式。
'''

class Cilent(object):
    
    def useTarget(self):
        pass

class Target(object):
    "抽象化"
    def request(self):
        raise NotImplementedError

class Adaptee(object):

    def specificRequest(self):
        print("specific request")

class Adapter(Target):
    
    def __init__(self):
        self.__adaptee = Adaptee()  # 私有成员变量
        self.adaptee = Adaptee()  # 私有成员变量

    def request(self):
        self.__adaptee.specificRequest()


if __name__ == '__main__':

    t = Adapter()
    t.request()
    print(t.adaptee)
