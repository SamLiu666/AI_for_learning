/*
 * @Author: [lxp]
 * @Date: 2022-01-18 20:32:13
 * @LastEditors: [lxp]
 * @LastEditTime: 2022-01-18 20:36:53
 * @Description: 
 */
#include "total.h"
#include<stdio.h> 

Client::Client(){

}

Client::~Client(){

}

ConcreteFactory::ConcreteFactory(){

}

ConcreteFactory::~ConcreteFactory(){

}

Product* ConcreteFactory::factoryMethod(){

	return  new ConcreteProduct();
}

Factory::Factory(){

}

Factory::~Factory(){

}

Product* Factory::factoryMethod(){
	return  NULL;
}

Product::Product(){

}

Product::~Product(){

}

void Product::use(){

}

Product::Product(){

}

Product::~Product(){

}


void Product::use(){

}