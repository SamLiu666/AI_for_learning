'''
Author: [lxp]
Date: 2022-01-19 19:09:26
LastEditors: [lxp]
LastEditTime: 2022-01-19 19:29:39
Description: 
造者模式(Builder Pattern)：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
建造者模式是一步一步创建一个复杂的对象，它允许用户只通过指定复杂对象的类型和内容就可以构建它们，用户不需要知道内部的具体构建细节。建造者模式属于对象创建型模式。根据中文翻译的不同，建造者模式又可以称为生成器模式

'''

class Product(object):
    def setA(self):
        print("Product -> A")
        
    def setB(self):
        print("Product -> B")

    def setC(self):
        print("Product -> C")

    def __str__(self):
        return "product has A and B and C"

class Builder(object):
    "Builder抽象类"

    def buildPartA(self):
        raise NotImplementedError

    def buildPartB(self):
        raise NotImplementedError

    def buildPartC(self):
        raise NotImplementedError

    def getResult(self):
        pass


class ConcreteBuilder(Builder):

    def buildPartA(self):
        raise NotImplementedError

    def buildPartB(self):
        raise NotImplementedError

    def buildPartC(self):
        raise NotImplementedError


def test():
    

if __name__ == '__main__':
    test()