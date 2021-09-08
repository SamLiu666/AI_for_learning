/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 21:03:09
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 21:06:11
 */
#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
    c1 += num / 100;
    num %= 100;
    c2 += num / 50;
    num %= 50;
    c3 += num / 20;
    num %= 20;
    c4 += num / 10;
    num %= 10;
    c5 += num / 5;
    num %= 5;
    c6 += num / 1;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;
    cout << c5 << endl;
    cout << c6 << endl;
}