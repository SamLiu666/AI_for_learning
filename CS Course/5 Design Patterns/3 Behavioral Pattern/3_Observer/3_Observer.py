'''
Author: [lxp]
Date: 2022-01-20 16:39:23
LastEditors: [lxp]
LastEditTime: 2022-01-20 17:48:27
Description: 
 * 观察者模式(Observer Pattern)：定义对象间的一种一对多依赖关系，使得每当一个对象状态发生改变时，其相关依赖对象皆得到通知并被自动更新。观察者模式又叫做发布-订阅（Publish/Subscribe）模式、模型-视图（Model/View）模式、源-监听器（Source/Listener）模式或从属者（Dependents）模式。观察者模式是一种对象行为型模式。
'''
#
# Python Design Patterns: Observer
# Author: Jakub Vojvoda [github.com/JakubVojvoda]
# 2016
#
# Source code is licensed under MIT License
# (for more details see LICENSE)
# 

import sys
   
#
# Observer
# defines an updating interface for objects that should be notified
# of changes in a subject
#
class Observer:
  def getState(self):
    pass
    
  def update(self, subject):
    pass
  
#
# Concrete Observer
# stores state of interest to ConcreteObserver objects and
# sends a notification to its observers when its state changes
#
class ConcreteObserver(Observer):
  def __init__(self, state):
    Observer.__init__(self)
    self._state = state
  
  def getState(self):
    return self._state
  
  def update(self, subject):
    self._state = subject.getState()
    print("Observer state updated.")
  
#
# Subject
# knows its observers and provides an interface for attaching
# and detaching observers
#
class Subject:
  def __init__(self):
    self._observers = []

  def attach(self, observer):
    self._observers.append(observer)

  def detach(self, index):
    self._observers.remove(index)

  def notify(self):
    for observer in self._observers:
      observer.update(self)

  def getState(self):
    pass
    
  def setState(self, state):
    pass

#
# Concrete Subject
# stores state that should stay consistent with the subject's
#
class ConcreteSubject(Subject):
  def __init__(self):
    Subject.__init__(self)
    self._state = 0
  
  def getState(self):
    return self._state

  def setState(self, state):
    self._state = state


if __name__ == "__main__":  
  observer1 = ConcreteObserver(1)
  observer2 = ConcreteObserver(2)

  print("Observer 1 state: " + str(observer1.getState()))
  print("Observer 2 state: " + str(observer2.getState()))

  subject = ConcreteSubject()
  subject.attach(observer1)
  subject.attach(observer2)

  subject.setState(10)
  subject.notify()

  print("Observer 1 state: " + str(observer1.getState()))
  print("Observer 2 state: " + str(observer2.getState()))