/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-06 09:40:32
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-06 10:23:42
 */
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[20], s2[4];
    while (cin >> s1 && cin >> s2) {
        cout << "s1: " << s1 << endl;
        cout << "s2: " << s2 << endl;
        int idx = 0, l1=0, ll1=strlen(s1);
        char temp = '0';
        for (int i=0; s1[i] != '\0'; i++) {
            l1++; // 字符串s1长度
            if (s1[i] > temp) {
                temp = s1[i]; idx = i;
            }
        }
        cout << "S1: " << s1 << endl;
        cout << "len s1: " << l1 << " " << ll1 << " idx : " << idx << endl;
        // TODO 拼接
        for (int i=l1; i > idx-1; i--) {
            cout << "i : " << i << " " << s1[i+3] << " " << s1[i] << endl;
            s1[i+3] = s1[i];  //后移三位
            cout << "i : " << i << " " << s1[i+3] << " " << s1[i] << endl;
            cout << "s1: " << s1 << endl; 
        }
        // s1[l1+4] = '\0';
        int count = 3, start=0;
        while (count--) {
            s1[++idx] = s2[start++];
        }
        cout << s1 << endl;
    }
    return 0;
}