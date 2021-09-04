/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 12:10:43
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 12:12:51
 */
#include <iostream>
using namespace std;

int main(){
    int n, temp, score=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> temp;
        if (temp > score) {
            score = temp;
        }
    }
    cout << score << endl;
    return 0;
}