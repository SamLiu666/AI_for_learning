/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 20:55:00
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 21:02:18
 */
#include <iostream>
using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    int a[N];
    for (int i=0; i<N; i++){
        cin >> a[i];
    }

    //TODO 找出k个数
    for (int i=0; i<N; i++){
        int count = 0;  // 统计比当前数大的个数
        for(int j=0; j<N; j++){
            if (i == j){
                continue;
            }
            else if (a[j] > a[i]) {
                count++;
            }
        }
        if (count == k - 1) {
            cout << a[i] << endl;
            break;
        }
    }

    return 0;
}