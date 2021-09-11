/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-11 14:57:10
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-11 15:07:45
 */
#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    while (k--) {
        int m, n; cin >> m >> n;
        int temp, result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >>temp;
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    result += temp;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}