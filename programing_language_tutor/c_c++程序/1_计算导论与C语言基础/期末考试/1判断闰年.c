/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-06 09:09:39
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-06 09:15:54
 */
#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;
    if (2 && year % 400 == 0 && year % 3200 != 0) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
}