'''
Author: [lxp]
Date: 2022-01-17 16:54:45
LastEditors: [lxp]
LastEditTime: 2022-01-17 17:14:28
Description: 

The idea is to abstract the creation of objects depending on business
logic, platform choice, etc.


When to use
a system should be independent of how its products are created, composed, and represented
a system should be configured with one of multiple families of products
a family of related product objects is designed to be used together
you want to provide a class library of products, and you want to reveal just their interfaces, not their implementations

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
