/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 21:47:47
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 23:11:29
 */
#include <iostream>
using namespace std;

int main() {
    int n, k;
    double f = 200.0;
    while (cin >> n >> k) {
        int i = 0, c = 0;
        for ( i = 1; i <= 20; i++) {
            c += n;
            if (c >= f)
                break;
            else
                f *= (k / 100.0 + 1);
        }
        if (i > 20) 
            cout << "Impossible" << endl;
        else
            cout << i << endl;
            f = 200.0;
    }
    return 0;
}