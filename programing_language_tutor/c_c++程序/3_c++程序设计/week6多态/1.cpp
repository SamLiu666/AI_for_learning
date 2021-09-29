/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-29 09:36:18
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-29 09:39:37
 */
#include <iostream>
using namespace std;
class A {
    public:
       virtual ~A() { cout << "destructor A" << endl; }

};
class B:public A {
    public:
        ~B() { cout << "destructor B" << endl; }
};
int main() {
    A * pa;
    pa = new B;
    delete pa;
    return 0;
}