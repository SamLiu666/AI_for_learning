/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 14:24:02
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-05 14:31:12
 */
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n+m]={0};
    for (int i=m; i<n; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<m; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}