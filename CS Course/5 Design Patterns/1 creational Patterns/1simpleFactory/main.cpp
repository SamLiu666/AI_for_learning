/*
 * @Author: [lxp]
 * @Date: 2022-01-18 19:38:55
 * @LastEditors: [lxp]
 * @LastEditTime: 2022-01-18 20:14:58
 * @Description: 
 */
#include <string>
#include <iostream>
// #include "Factory.h"
using namespace std;

class Product
{

public:
	Product();
	virtual ~Product();
	virtual void Use() = 0;  // 纯虚函数：当想在基类中抽象出一个方法，且该基类只做能被继承，而不能被实例化； 这个方法必须在派生类(derived class)中被实现；

};

class ConcreteProductA : public Product
{

public:
	ConcreteProductA();
	virtual ~ConcreteProductA();
	
	virtual void Use() {
        cout << "use productA" << endl;	
    }

};

class ConcreteProductB : public Product
{

public:
	ConcreteProductB();
	virtual ~ConcreteProductB();
	
	virtual void Use() {
        cout << "use productB" << endl;	
    }

};

class Factory
{

public:
	Factory();
	virtual ~Factory();

	static Product * create_product(string proname) {
        if (proname == "A") {
            return new ConcreteProductA();
        } else if (proname == "B") {
            return new ConcreteProductB();
        }
    }

};


int main() {
	Product * prod = Factory::create_product("A");
		
	prod->Use();
	
	delete prod;
    return 0;
}