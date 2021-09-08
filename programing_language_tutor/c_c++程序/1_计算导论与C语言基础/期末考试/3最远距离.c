/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-06 09:26:03
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-06 09:31:39
 */
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double x[n], y[n], temp, max=0.0;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }

    // TODO 计算点之间距离
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            temp = sqrt(pow((x[j] - x[i]), 2) + pow((y[j] - y[i]), 2));
            if (temp > max) max = temp;
        }
    }
    cout << fixed << setprecision(4) << max << endl;
}