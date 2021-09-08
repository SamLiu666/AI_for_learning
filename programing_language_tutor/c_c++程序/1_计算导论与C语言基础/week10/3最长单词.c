/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 10:20:59
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-06 09:36:07
 */
#include <iostream>
using namespace std;
char s[500];
int main() {
    cin.getline(s,500);
    int max = 0, n = 0, p = 0; 
    // max用来保存最大单词长度 ，n用来保存当前单词长度 
    // p 表示最大单词最后字母位置 
    for (int i = 0; s[i] !='\0'; i++) {
        if (s[i] == ' ') {
            n = 0;
        }
        else if ((s[i] >='A' && s[i] <='Z') || (s[i] >= 'a' && s[i] <='z')) {
            n++;
        }
        if (max < n) {
            max = n;
            p = i;
        }
    }
    for (int j = p - max + 1; j <= p; j++)
        cout << s[j];
        cout << endl;
    return 0;
}