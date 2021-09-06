/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 09:36:47
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-05 09:47:50
 */
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char s[80];
    gets(s); int n = strlen(s);
    // cin.getline(s, 80);  // 一行字符串输入到字符数组s
    int ch[5]={0};
    for (int i=0; i<n; i++){
        // cout << "s： " << s[i] << endl;
        if (s[i] == 'a') {
            ch[0]++;
        } else if (s[i] == 'e') {
            ch[1]++;
        } else if (s[i] == 'i') {
            ch[2]++;
        } else if (s[i] == 'o') {
            ch[3]++;
        } else if (s[i] == 'u') {
            ch[4]++;
        }
    }
    for (int i=0; i<5; i++){
        cout << ch[i] << " ";
    }
    cout << endl;
    return 0;
}