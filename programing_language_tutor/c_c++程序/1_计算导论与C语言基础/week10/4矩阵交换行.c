/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 14:05:34
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-05 14:11:28
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int arr[5][5], n, m;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> n >> m;
    if (n < 0 || n > 4 || m < 0 || m > 4) {
        cout << "error" << endl;
    } else {
        int temp[5];
        for (int i = 0; i < 5; i++) {
            temp[i] = arr[n][i];
        }
        for (int i = 0; i < 5; i++) {
            arr[n][i] = arr[m][i];
        }
        for (int i = 0; i < 5; i++) {
            arr[m][i] = temp[i];
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << setw(4) << arr[i][j];
            }
            cout << endl;
        }
    }
}