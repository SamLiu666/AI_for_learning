/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 11:52:09
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 12:14:33
 */
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, x, y, temp;
    cin >> n >> x >> y;
    temp = y / x;
    // if ( y % x == 0){
    //     cout << n - temp << endl;
    // } else {
    //     cout << n - temp - 1 << endl;
    // }
    cout << ceil((double)(n - y / x)) << endl;
    // temp = (double)y / x;
    // cout << temp << endl;
    // cout << (int)temp << endl;
    // cout << y / x << endl;
    return 0;
}