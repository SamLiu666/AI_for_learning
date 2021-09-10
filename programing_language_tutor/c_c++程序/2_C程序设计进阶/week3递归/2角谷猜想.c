/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-09 12:02:29
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-09 12:10:24
 */
#include <iostream>
using namespace std;
// int getOne(int n);
void getOne(int n);

int main() {
    int n;
    cin >> n;
    getOne(n);
    return 0;
}

// int getOne(int n) {
void getOne(int n) {
    if (n == 1) {
        cout << "End" << endl;
        // return 0;
    } else {
        int result;
        if (n % 2 == 1) {
            // 奇数
            result = n*3 + 1;
            cout << n << "*3+1=" << result << endl;
        } else {
            // 偶数
            result = n / 2;
            cout << n << "/2=" << result << endl;
        }
        getOne(result);
        // return 0;
    }
}