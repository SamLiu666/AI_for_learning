'''
Author: [lxp]
Date: 2022-01-18 20:19:04
LastEditors: [lxp]
LastEditTime: 2022-01-18 21:05:25
Description: 
工厂方法模式(Factory Method Pattern): 它属于类创建型模式。在工厂方法模式中，工厂父类负责定义创建产品对象的公共接口，而工厂子类则负责生成具体的产品对象，这样做的目的是将产品类的实例化操作延迟到工厂子类中完成，即通过工厂子类来确定究竟应该实例化哪一个具体产品类。

实例：某系统日志记录器要求支持多种日志记录方式，如文件记录、数据库记录等，且用户可以根据要求动态选择日志记录方式， 现使用工厂方法模式设计该系统。

优点：使用工厂方法模式的另一个优点是在系统中加入新产品时，无须修改抽象工厂和抽象产品提供的接口，无须修改客户端，也无须修改其他的具体工厂和具体产品，而只要添加一个具体工厂和具体产品就可以了。这样，系统的可扩展性也就变得非常好，完全符合“开闭原则”。

使用环境：
一个类不知道它所需要的对象的类：在工厂方法模式中，客户端不需要知道具体产品类的类名，只需要知道所对应的工厂即可，具体的产品对象由具体工厂类创建；客户端需要知道创建具体产品的工厂类。
一个类通过其子类来指定创建哪个对象：在工厂方法模式中，对于抽象工厂类只需要提供一个创建产品的接口，而由其子类来确定具体要创建的对象，利用面向对象的多态性和里氏代换原则，在程序运行时，子类对象将覆盖父类对象，从而使得系统更容易扩展。
将创建对象的任务委托给多个工厂子类中的某一个，客户端在使用时可以无须关心是哪一个工厂子类创建产品子类，需要时再动态指定，可将具体工厂类的类名存储在配置文件或数据库中。

'''
from typing import Type

class Log(object):

    def writeLog(self) -> None:
        raise NotImplementedError

class client(object):
    "客户选择日志"
    def test(self, logName:str = 'FileLogFactory') -> None:
        """编写测试案例，客户创建FileLogFactory还是DataBaseLogFactory
        logName: FileLogFactory还是DataBaseLogFactory"""

        print("I want to create", logName)
        if logName == 'FileLogFactory':
            fc = FileLogFactory()
        elif logName == 'DataBaseLogFactory':
            fc = DataBaseLogFactory()
        logType = fc.createLog()
        logType.writeLog()


class LogFactory(object):
    "抽象类--日志工厂"
    def createLog(self) -> Type[Log]:
        raise NotImplementedError


class FileLogFactory(LogFactory):
    "继承+实现--LogFactory，实现Log子类--FileLog"

    def createLog(self) -> Type[Log]:
        "实现创建Log日志对象"
        print("create FileLog")
        return FileLog()


class DataBaseLogFactory(LogFactory):
    "继承+实现--LogFactory，实现Log子类--DataBaseLog"

    def createLog(self) -> Type[Log]:
        "实现创建Log日志对象"
        print("create DataBaseLog")
        return DataBaseLog()

class FileLog(Log):

    def writeLog(self) -> None:
        print("FileLog to write")

class DataBaseLog(Log):

    def writeLog(self) -> None:
        print("DataBaseLog to write")

if __name__ == '__main__':
    c = client()
    c.test('DataBaseLogFactory')
    c.test()
