/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 14:14:02
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-05 14:22:58
 */
#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // TODO 统计数目
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            // cout << " " << i << " " << j << " " << arr[i][j] << endl;
            if (arr[i - 1][j] - arr[i][j] < 50 || arr[i + 1][j] - arr[i][j] < 50 \
             || arr[i][j - 1] - arr[i][j] < 50 || arr[i][j + 1] - arr[i][j] < 50) {
                continue;
            } else {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}