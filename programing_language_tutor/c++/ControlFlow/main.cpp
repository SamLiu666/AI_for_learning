/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-02 22:14:24
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-03 09:21:36
 */
#include <iostream>
using namespace std;

int main() {
    int n, counter;
    cout << "Input a positive interger: ";
    cin >> n;  
    cout << "While loop: " << endl;
    counter = 1;
    while(counter <= n){
        cout << counter << endl;
        counter++;
    }
    cout << "For loop: " << endl;
    for(int i=1; i<=n; i++){
        cout << i << endl;
    }

    // 三数之和
    int sumDigits, num, countDigits, currentDigits, temp;
    cout << "Input three num: ";
    cin >> num;
    temp = num;
    sumDigits = 0; countDigits=0;
    while(num > 0){
        currentDigits = num % 10;
        countDigits++;
        sumDigits += currentDigits;
        num = num/10;
    }

    cout << temp << " has " << countDigits << " digits" << endl;
    cout << temp << " sum is " << sumDigits << endl;
    return 0;
}