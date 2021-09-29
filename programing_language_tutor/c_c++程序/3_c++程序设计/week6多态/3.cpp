/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-29 09:49:25
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-29 09:53:53
 */
#include <iostream>
using namespace std;
class A {
    private:
        int nVal;
    public:
        void Fun()
        { cout << "A::Fun" << endl; }
        virtual void Do()
        { cout << "A::Do" << endl; }
};
class B:public A {
    public:
        virtual void Do()
        { cout << "B::Do" << endl; }
};
class C:public B {
    public:
        void Do( )
        { cout << "C::Do" << endl; }
        void Fun()
        { cout << "C::Fun" << endl; }
};
void Call(
// 在此处补充你的代码
    A * p
        ) {
    p->Fun(); p->Do();
}
int main() {
    Call( new A() );
    Call( new C() );
    Call( new B() );
    return 0;
}