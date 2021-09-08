/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 21:25:12
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 21:29:07
 */
#include <iostream>
using namespace std;

int main() {
    int sum=0, temp, a;
    for (int i=0; i<6; i++){
        if (i == 0){
            cin >> a;
        } else {
            cin >> temp;
            if (temp < a) {
                sum += temp;
            }
        }
    }

    cout << sum << endl;
    return 0;
}