/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 10:27:17
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 10:32:48
 */
#include <iostream>
using namespace std;

int main() {
    int k, K;
    cin >> k;
    K = k;
    int a[k], c[k];
    for (int i=0; i<k; i++){
        int temp;
        cin >> temp;
        a[i] = temp;
    }

    for (int i=0; i<K; i++){
        c[i] = a[--k];
    }
    
    for (int i=0; i<K; i++){
        cout << c[i] << ' ';
    }
    return 0;

    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
        cin >> a[i];
    while (n--) { //常用的倒序计数循环，等价于while(n-->0)
        cout << a[n];
        if (n > 0) cout << " "; //如果不是最后一个数那么就要用空格分隔开
    }
    return 0;
}