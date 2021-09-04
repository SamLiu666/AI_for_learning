/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 21:30:21
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 21:36:41
 */
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }

    // TODO 计算时间
    for (int i = 0; i < n; i++){
        double t1 = 0.0, t2 = 0.0;  // t1 -- Bike ; t2 -- Walk
        t1 += 27 + 23 + (double)d[i] / 3.0;
        t2 = (double)d[i] / 1.2;
        if (t1 < t2) {
            cout << "Bike" << endl;
        } else if (t1 > t2){
             cout << "Walk" << endl;           
        } else {
            cout << "All" << endl;
        }
    }

    return 0;
}