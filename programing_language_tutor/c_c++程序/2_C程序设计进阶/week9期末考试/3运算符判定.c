/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-12 19:52:24
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-12 19:55:31
 */
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int temp;
    if (a / b == c) {
        cout << '/';
    } else if (a % b == c) {
        cout << '%';
    } else if (a + b == c) {
        cout << '+';
    }

    return 0;
}