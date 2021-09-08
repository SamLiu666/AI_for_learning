/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-06 09:33:49
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-06 09:39:07
 */
#include <iostream>
using namespace std;

int main() {
    int a, b;
    char c;
    while(cin >> a >> b >> c) {
        switch(c) {
            case '+': cout << a + b;
                    break;
            case '-': cout << a - b; 
                    break;
            case '*': cout << a * b;
                    break;
            case '/': if (b ==  0) {
                        cout << "Divided by zero!";
                        break;
                    }
                    else{
                        cout << a / b;
                        break;
                    }
            default:    cout << "Invalid operator!"; 
        } 
        cout << endl; 
    }
    return 0;
}