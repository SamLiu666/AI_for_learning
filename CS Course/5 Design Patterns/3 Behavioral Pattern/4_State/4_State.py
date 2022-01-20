'''
Author: [lxp]
Date: 2022-01-20 17:54:48
LastEditors: [lxp]
LastEditTime: 2022-01-20 19:20:10
Description: 
* 状态模式(State Pattern) ：允许一个对象在其内部状态改变时改变它的行为，对象看起来似乎修改了它的类。其别名为状态对象(Objects for States)，状态模式是一种对象行为型模式。
'''

class State(object):

    def handle(self):
        raise NotImplementedError

class ConcreteStateA(State):

    def handle(self):
        print("ConcreteStateA handle")

class ConcreteStateB(State):

    def handle(self):
        print("ConcreteStateB handle")

class Context(object):
    def __init__(self):
        self.state = State()

    def setState(self, state):
        self.state = state 
    
    def request(self):
        self.state.handle()

if __name__ == '__main__':
    sa = ConcreteStateA()
    sb = ConcreteStateB()

    context = Context()

    context.setState(sa)
    context.request()

    context.setState(sb)
    context.request()