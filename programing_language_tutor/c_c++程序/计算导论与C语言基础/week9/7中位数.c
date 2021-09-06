/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 14:32:31
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-05 15:00:08
 */
#include <iostream>
using namespace std;
int s[15000];
int main() {
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        else {
            for (int i = 0; i < n; i++)
                cin >> s[i];
        }
        // 冒泡排序
        for (int i = 0; i < n - 1; i++) {
            int temp = s[i];
            for (int j = 0; j < n - i - 1; j++) {
                if (s[j + 1] > s[j]) {
                    temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
            }
        }
        if (n % 2 == 1) 
            cout << s[n / 2] << endl;
        else
            cout << (s[n / 2] + s[n / 2 - 1]) / 2 << endl;
    }
    return 0;
}