/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 23:14:14
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 23:19:52
 */
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=10; i<=n; i++) {
        int a, b, temp;
        temp = i;
        a = temp % 10;
        temp /= 10;
        b = temp % 10;
        if (i % (a + b) == 0){
            cout << i << endl;
        }
    }

    return 0;
}