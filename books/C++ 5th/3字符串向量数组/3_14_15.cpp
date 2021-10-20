/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-20 22:24:30
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-20 22:37:03
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> v;
    int n;
    while (cin >> n) {
        v.push_back(n);
    }
    for (auto x:v) {
        cout << "x: " << x << endl;
    }
    // vector<string> ss;
    // string temp;
    // while (cin >> temp) {
    //     ss.push_back(temp);
    // }
    
    return 0;
}