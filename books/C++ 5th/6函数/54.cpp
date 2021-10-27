/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-25 12:13:54
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-25 12:14:57
 */
#include <iostream>
#include <vector>
using namespace std;
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    int func(int, int);
    vector<decltype(func)*> v;
    v.push_back(add);
    v.push_back(subtract);
    v.push_back(multiply);
    v.push_back(divide);

    std::vector<decltype(func) *> vec{ add, subtract, multiply, divide };
    for (auto f : vec)
          std::cout << f(2, 2) << std::endl;

    return 0;
}