'''
Author: [lxp]
Date: 2022-01-20 19:34:52
LastEditors: [lxp]
LastEditTime: 2022-01-20 19:42:53
Description: 
策略模式(Strategy Pattern)：定义一系列算法，将每一个算法封装起来，并让它们可以相互替换。策略模式让算法独立于使用它的客户而变化，也称为政策模式(Policy)。
'''

class Strategy(object):

    def algorithm(self):
        print("Strategy")

class ConcreteStrategyA(Strategy):

    def algorithm(self):
        print("ConcreteStrategyA")

class ConcreteStrategyB(Strategy):

    def algorithm(self):
        print("ConcreteStrategyB")

class Context(object):

    def __init__(self):
        self._strategy = Strategy()

    def setStrategy(self, strategy):
        self._strategy = strategy        

    def algorithm(self):
        self._strategy.algorithm()


if __name__ == "__main__":
    ca = ConcreteStrategyA()
    cb = ConcreteStrategyB()

    c = Context()
    c.algorithm()

    c.setStrategy(ca)
    c.algorithm()

    c.setStrategy(cb)
    c.algorithm()