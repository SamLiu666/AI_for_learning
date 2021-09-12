/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-11 19:50:57
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-11 21:00:50
 */
#include <iostream>
#include <iomanip>
using namespace std;

struct Patient {
    char id[3];
    double sick;
};

int main() {
    int m; double low;
    cin >> m >> low; // 病人数目
    // cout << "m: " << m << " " << low << endl;
    Patient patient[m];
    for (int i = 0; i < m; i++) {
        cin >> patient[i].id >> patient[i].sick;
    }
    // 排序
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (patient[j].sick < patient[j + 1].sick) {
                Patient temp = patient[j];
                patient[j] = patient[j + 1];
                patient[j + 1] = temp;
            }
        }
    }
    cout << "###" << endl;
    bool flag = false;
    for (int i = 0; i < m; i++) {
        if (patient[i].sick >= low) {
            flag = true;
            cout << patient[i].id << " " << fixed<< setprecision(1) << patient[i].sick << endl;
        }
    }
    if (!flag) {
        cout << "none" << endl;
    }

    return 0;
}