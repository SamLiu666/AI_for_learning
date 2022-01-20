'''
Author: [lxp]
Date: 2022-01-18 19:29:05
LastEditors: [lxp]
LastEditTime: 2022-01-18 20:17:56
Description: 
Simple Factory: 简单工厂模式(Simple Factory Pattern)：又称为静态工厂方法(Static Factory Method)模式，它属于类创建型模式。在简单工厂模式中，可以根据参数的不同返回不同类的实例。简单工厂模式专门定义一个类来负责创建其他类的实例，被创建的实例通常都具有共同的父类。

应用环境：
工厂类负责创建的对象比较少：由于创建的对象较少，不会造成工厂方法中的业务逻辑太过复杂。
客户端只知道传入工厂类的参数，对于如何创建对象不关心：客户端既不需要关心创建细节，甚至连类名都不需要记住，只需要知道类型所对应的参数。
'''
class Product(object):
    # @staticmethod
    def use(self):
        raise NotImplementedError


class CreateProductA(Product):

    def use(self):
        print("create product A")


class CreateProductB(Product):

    def use(self):
        print("create product B")


class FactorySimple(object):
    
    def createProduct(self, productName:str) -> None:
        if productName == 'A':
            return CreateProductA()
        
        elif productName == 'B':
            return CreateProductB()


if __name__ == '__main__':
    fac = FactorySimple().createProduct('A')
    fac.use()

