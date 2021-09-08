/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-06 09:16:06
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-06 09:24:45
 */
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int flag = 0;  // 标志能被整除
        if (n % 3 == 0) {
            cout << 3 << " ";
        } else {
            flag++;
        }
        if (n % 5 == 0) {
            cout << 5 << " ";
        } else {
            flag++;
        }
        if (n % 7 == 0) {
            cout << 7 << " ";
        } else {
            flag++;
        }
        if (flag == 3) {
            cout << 'n';
        }
        cout << endl;
    }
    return 0;
}