/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 09:47:47
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 09:49:57
 */
#include <iostream>
using namespace std;

int main() {
    int m, n, result=0;
    cin >> m >> n;
    while (m <= n){
        if (m % 2 == 1){
            result += m;
        }
        m++;
    }
    cout << result << endl;
    return 0;
}