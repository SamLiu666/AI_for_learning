/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 15:01:11
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-05 15:16:59
 */
#include <iostream>
using namespace std;

int main() {
    int length, m, count=0;
    cin >> length >> m;
    int arr[length+1]={0};
    while(m--) {
        // cout << "m: " << m << endl;
        int start, end;
        cin >> start >> end;
        for (int i=start; i<=end; i++){
            arr[i] = 1;
        }
    }

    for (int i=0; i<=length; i++){
        if (arr[i] == 0) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}