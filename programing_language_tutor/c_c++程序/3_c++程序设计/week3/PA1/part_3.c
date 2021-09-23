/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-15 18:00:56
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-23 14:30:04
 */
#include <iostream>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big  {
public:
    int v; Base b;
// 在此处补充你的代码
    Big(int n) : v(n), b(n) { }
    Big(const Big & big) : v(big.v), b(big.v) {}
};
int main()  {
    Big a1(5);    Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}