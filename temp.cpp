/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-02 14:29:30
 * @LastEditors: lxp
 * @LastEditTime: 2021-11-09 22:44:12
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    int n = 0, i = 42;
    int *p = &n, *q = &i;
    cout << "n = " << n << " p = " << p << endl;
    cout << "i = " << i << " q = " << q << endl;
    p = q;
    cout << "n = " << n << " p = " << p << endl;
    cout << "i = " << i << " q = " << q << endl;

	return 0;
}