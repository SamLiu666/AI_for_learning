'''
Author: [lxp]
Date: 2022-01-20 16:23:51
LastEditors: [lxp]
LastEditTime: 2022-01-20 16:29:19
Description: 
中介者模式(Mediator Pattern)定义：用一个中介对象来封装一系列的对象交互，中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。中介者模式又称为调停者模式，它是一种对象行为型模式。
'''

#
# Python Design Patterns: Mediator
# Author: Jakub Vojvoda [github.com/JakubVojvoda]
# 2016
#
# Source code is licensed under MIT License
# (for more details see LICENSE)
# 

import sys

#
# Colleague classes
# each colleague communicates with its mediator whenever
# it would have otherwise communicated with another colleague
#
class Colleague:
  def __init__(self, mediator, identity):
    self._mediator = mediator
    self._id = identity
  
  def getID(self):
    return self._id

  def send(self, message):
    pass
    
  def receive(self, message):
    pass

class ConcreteColleague(Colleague):
  def __init__(self, mediator, identity):
    super().__init__(mediator, identity)

  def send(self, message):
    print("Message '" + message + "' sent by Colleague " + str(self._id))
    self._mediator.distribute(self, message)
    
  def receive(self, message):
    print("Message '" + message + "' received by Colleague " + str(self._id))

#
# Mediator
# defines an interface for communicating with Colleague objects
#
class Mediator:
  def add(self, colleague):
    pass
  
  def distribute(self, sender, message):
    pass

#
# Concrete Mediator
# implements cooperative behavior by coordinating Colleague objects
# and knows its colleagues
#
class ConcreteMediator(Mediator):
  def __init__(self):
    Mediator.__init__(self)
    self._colleagues = []
  
  def add(self, colleague):
    self._colleagues.append(colleague)

  def distribute(self, sender, message):
    for colleague in self._colleagues:
      if colleague.getID() != sender.getID():
        colleague.receive(message)


if __name__ == "__main__":
  mediator = ConcreteMediator()

  c1 = ConcreteColleague(mediator, 1)
  c2 = ConcreteColleague(mediator, 2)
  c3 = ConcreteColleague(mediator, 3)

  mediator.add(c1)
  mediator.add(c2)
  mediator.add(c3)

  c1.send("Hi!");
  c3.send("Hello!");