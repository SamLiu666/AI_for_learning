'''
Author: [lxp]
Date: 2022-01-20 16:04:16
LastEditors: [lxp]
LastEditTime: 2022-01-20 16:20:52
Description: 
命令模式(Command Pattern)：将一个请求封装为一个对象，从而使我们可用不同的请求对客户进行参数化；对请求排队或者记录请求日志，以及支持可撤销的操作。命令模式是一种对象行为型模式，其别名为动作(Action)模式或事务(Transaction)模式。
'''
class Receiver(object):

    def action(self):
        print("Receiver::action")


class Command(object):

    def execute(self):
        raise NotImplementedError


class ComcreteCommand(Command):

    def __init__(self, receiver):
        self._receiver = receiver
    
    def execute(self):
        print("Executing ComcreteCommand")
        self._receiver.action()


class Invoker(object):

    def __init__(self, cmd = None):
        self._cmd = cmd

    def call(self):
        print("Calling Invoker")
        if self._cmd is not None:
            self._cmd.execute()


if __name__ == '__main__':
    rcv = Receiver()
    cmd = ComcreteCommand(rcv)
    ivk = Invoker(cmd)
    ivk.call()