/*
 * @Author: [lxp]
 * @Date: 2022-01-18 20:32:13
 * @LastEditors: [lxp]
 * @LastEditTime: 2022-01-18 20:33:17
 * @Description: 
 */
class Product
{

public:
	Product();
	virtual ~Product();

	virtual void use();

};

class ConcreteProduct : public Product
{

public:
	ConcreteProduct();
	virtual ~ConcreteProduct();

	virtual void use();

};

class Factory
{

public:
	Factory();
	virtual ~Factory();

	virtual Product* factoryMethod();

};

class ConcreteFactory : public Factory
{

public:
	ConcreteFactory();
	virtual ~ConcreteFactory();

	virtual Product* factoryMethod();

};

class Client
{

public:
	Client();
	virtual ~Client();

};
