/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-07 09:46:06
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-08 09:41:02
 */
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    double arr[6] = {0.0}; // 1,2,3;A,B,C
    for (int i = 0; i < 3; i++) {
        int id, n;
        cin >> id >> n;
        // cout << "id: " << id << " " << n << endl;
        for (int j = 0; j < n; j++) {
            char f;  // 发票类型
            double c; // 发票数额
            cin >> f >> c;
            arr[id-1] += c;  // 编号总钱数
            // cout << "f: " << f << " " << c << endl;
            if (f == 'A') {
                arr[3] += c;
            } else if (f == 'B') {
                arr[4] += c;
            } else if (f == 'C') {
                arr[5] += c;
            }
        }
        
    }
    cout << 1 << " " << fixed << setprecision(2) << arr[0] << endl;
    cout << 2 << " " << fixed << setprecision(2) << arr[1] << endl;
    cout << 3 << " " << fixed << setprecision(2) << arr[2] << endl;
    cout << 'A' << " " << fixed << setprecision(2) << arr[3] << endl;
    cout << 'B' << " " << fixed << setprecision(2) << arr[4] << endl;
    cout << 'C' << " " << fixed << setprecision(2) << arr[5] << endl;
    return 0;
}