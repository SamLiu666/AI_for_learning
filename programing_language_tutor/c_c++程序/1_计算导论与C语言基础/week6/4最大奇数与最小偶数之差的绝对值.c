/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 12:14:11
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 13:04:41
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int maxOdd=0, minEven=101;
    for (int i=0; i<6; i++){
        int temp;
        cin >> temp;
        if (temp % 2 == 0 && temp < minEven){
            // * 偶数
            minEven = temp;
        } else if (temp % 2 == 1 && temp > maxOdd){
            // * 奇数
            maxOdd = temp;
        }
    }
    cout << abs(maxOdd - minEven) << endl;
    return 0;
}