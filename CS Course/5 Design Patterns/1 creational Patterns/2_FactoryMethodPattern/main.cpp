/*
 * @Author: [lxp]
 * @Date: 2022-01-18 20:31:23
 * @LastEditors: [lxp]
 * @LastEditTime: 2022-01-18 20:31:24
 * @Description: 
 */
#include "total.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	Factory * fc = new ConcreteFactory();
	Product * prod = fc->factoryMethod();
	prod->use();
	
	delete fc;
	delete prod;
	
	return 0;
}