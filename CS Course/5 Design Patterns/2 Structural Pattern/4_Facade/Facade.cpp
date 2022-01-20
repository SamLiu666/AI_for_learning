/*
 * @Author: [lxp]
 * @Date: 2022-01-19 20:59:55
 * @LastEditors: [lxp]
 * @LastEditTime: 2022-01-19 21:08:23
 * @Description: 
 */
#include <iostream>

class SystemA
{
public:
    void operationA() {
        std::cout << "SystemA" << std::endl;
    }
};

class SystemB
{
public:
    void operationB() {
        std::cout << "SystemB" << std::endl;
    }
};


class SystemC
{
public:
    void operationC() {
        std::cout << "SystemC" << std::endl;
    }
};


class Facade
{
public:
    Facade() : systemA(), systemB(), systemC() {}

    void wrapOperation() {
        systemA->operationA();
        systemB->operationB();
        systemC->operationC();

    }

private:
    SystemA *systemA;
    SystemB *systemB;
    SystemC *systemC;

};

int main() {
    Facade *facade = new Facade();
    facade->wrapOperation();

    delete facade;
    return 0;
}