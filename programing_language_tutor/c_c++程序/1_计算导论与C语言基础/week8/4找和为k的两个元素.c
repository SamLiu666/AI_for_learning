/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 22:52:27
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 22:58:38
 */
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 查找和为k
    for (int i = 0; i < n - 1; i++) {
        for(int j = i+1; j < n; j++){
            if (arr[i] + arr[j] == k){
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}