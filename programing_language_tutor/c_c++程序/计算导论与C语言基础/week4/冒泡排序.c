/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 09:12:34
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 09:21:04
 */
#include <iostream>
using namespace std;

int main() {
    int n, a[1000];
    cout << "Input n:";
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    // 冒泡排序
    for (int i=0; i<n-1; i++){
        for (int j=1; j<n-i; j++){
            if (a[j-1] > a[j]){
                int temp = a[j-1]; a[j-1] = a[j]; a[j] = temp;
            }
        }
    }

    // 打印输出
    for (int i=0; i<n; i++){
        cout << a[i] << endl;
    }

    return 0;
}