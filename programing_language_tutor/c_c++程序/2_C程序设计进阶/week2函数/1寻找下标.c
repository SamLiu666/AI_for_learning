/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-06 10:34:41
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-07 09:32:01
 */
#include <iostream>
using namespace std;

int main() {
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "N" << endl;

    return 0;
}