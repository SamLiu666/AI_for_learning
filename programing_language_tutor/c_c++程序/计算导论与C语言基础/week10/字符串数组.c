/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 15:20:08
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-05 15:23:18
 */
#include <iostream>
using namespace std;

int main() {
    char str1[] = "C++ language", str2[20];
    int i = 0;
    while (str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    return 0;
}