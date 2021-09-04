/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 09:50:59
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 09:56:36
 */
#include <iostream>
using namespace std;

int main() {
    int k, c1=0, c5=0, c10=0;
    cin >> k;
    for (int i=0; i<k; i++){
        int temp;
        cin >> temp;
        if (temp == 1){c1++;}
        else if (temp == 5){c5++;}
        else if (temp == 10) {c10++;}
    }
    cout << c1 << '\n' << c5 << '\n' << c10 << '\n';
}