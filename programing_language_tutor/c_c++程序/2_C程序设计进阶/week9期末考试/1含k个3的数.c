/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-12 15:50:29
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-12 16:47:59
 */
#include <iostream>
using namespace std;

int main() {
    int m, k, n = 0;
    cin >> m >> k;
    if (m % 19 != 0) {
        cout << "NO" << endl;
    } else {
        while (1) {
            if (m < 10) break;
            if (m % 10 == 3) n++;
            m = m / 10;     
        }
        if (n != k) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}