'''
Author: [lxp]
Date: 2022-01-17 16:54:45
LastEditors: [lxp]
LastEditTime: 2022-01-19 19:08:33
Description: 
抽象工厂模式(Abstract Factory Pattern)：提供一个创建一系列相关或相互依赖对象的接口，而无须指定它们具体的类。抽象工厂模式又称为Kit模式，属于对象创建型模式。

在以下情况下可以使用抽象工厂模式：

一个系统不应当依赖于产品类实例如何被创建、组合和表达的细节，这对于所有类型的工厂模式都是重要的。
系统中有多于一个的产品族，而每次只使用其中某一产品族。
属于同一个产品族的产品将在一起使用，这一约束必须在系统的设计中体现出来。
系统提供一个产品类的库，所有的产品以同样的接口出现，从而使客户端不依赖于具体实现。
'''
import random
from typing import Type


class Person(object):

    def __init__(self, name: str) -> None:
        self.name = name

    def action(self):
        raise NotImplementedError
    
    def __str__(self) -> str:
        raise NotImplementedError


class Teacher(Person):

    def __init__(self, name: str) -> None:
        Person.__init__(self, name)
        self.name = name
    
    def action(self) -> None:
        print(self.name, "is teaching.")
    
    def __str__(self) -> str:
        return self.name + " is a teacher."


class Student(Person):

    def __init__(self, name: str) -> None:
        Person.__init__(self, name)
        self.name = name
    
    def action(self) -> None:
        print(self.name, "is studying.")
    
    def __str__(self) -> str:
        return self.name + " is a student."


class PersonRole(object):

    def __init__(self, personRole: Type[Person]) -> None:
        self.personRole = personRole
    
    def action(self, name: str) -> None:
        "do something"
        role = self.personRole(name)  # 传入是谁
        role.action()
        print(role)

def testCase():
    "do the unit test"
    p = PersonRole(Teacher)
    p.action("Zoe")

    s = PersonRole(Student)
    s.action("Sam")

    print("#" * 16)
    for name in ["David", 'Bob', 'Peter']:
        t = PersonRole(random.choice([Student, Teacher]))
        t.action(name)
        print("#" * 16)


if __name__ == "__main__":
    testCase()
