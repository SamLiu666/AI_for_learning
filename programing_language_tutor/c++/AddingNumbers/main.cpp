/*
 * @Description:打印两数之和
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-02 09:19:09
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-02 10:08:50
 */
#include <iostream>
using namespace std;

int main(){
    int num1; // first number 
    int num2;
    int sum; 

    cout << "Input: " << endl;
    cin >> num1 >> num2;

    sum = num1 + num2;
    cout << num1 << " + " << num2 << " = " << sum << endl;
    cout << "Hello World!" << endl;
    return 0;
}