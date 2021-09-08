/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 09:58:52
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 10:01:01
 */
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int temp, count = 0;
        cin >> temp;
        while (temp){
            count += temp % 2;
            temp /= 2;
        }
        cout << count << endl;
    }
    return 0;
}