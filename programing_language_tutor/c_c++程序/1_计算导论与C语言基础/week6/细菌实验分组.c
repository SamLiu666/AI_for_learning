/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 10:53:05
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 11:50:49
 */
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int id[n];
    double rate[n];
    for (int i = 0; i < n; i++){
        double start, final;
        cin >> id[i] >> start >> final;
        rate[i] = (double)final / start;
    }
    // 升序--冒泡排序
    for (int i=0; i < n; i++){
        for (int j=0; j < n-i-1; j++){
            if (rate[j] > rate[j+1]){
                double temp = rate[j]; rate[j] = rate[j+1]; rate[j+1] = temp;
                int t2 = id[j]; id[j] = id[j+1]; id[j+1] = t2;
            }
        }
    }
    // cout << "rate: ";
    // for (int i = 0; i < n; i++){
    //     cout << rate[i] << " " << id[i]  << endl;
    // }
    // 找出最大位置索引
    double maxDiff = 0.0; int maxIdx = 0;
    for (int i=0; i<n-1; i++){
        if (rate[i+1] - rate[i] > maxDiff){
            maxDiff = rate[i+1] - rate[i];
            maxIdx = i;
        }
    }
    // cout << maxDiff << " a " << maxIdx << endl;

    // 打印 较大的
    cout << n - (maxIdx + 1) << endl;
    for (int i=maxIdx + 1; i<n; i++){
        cout << id[i] << endl;
    }

    // 较小的
    cout << maxIdx + 1 << endl;
    for (int i=0; i<maxIdx + 1; i++){
        cout << id[i] << endl;
    }
    return 0;
}