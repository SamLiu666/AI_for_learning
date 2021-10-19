/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-02 14:29:30
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-19 17:44:48
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    int i, &ri = i;
    i = 5; ri = 10;
    std::cout << i << " " << ri << std::endl;
    int *p = &i;
    cout << "p: " << p << " *p " << *p << std::endl;
    return 0;
}