/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-10 10:17:08
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-11 14:47:35
 */
#include <iostream>
using namespace std;

int main() {
    char ch[101], s[101]; 
    int idx[101];
    int top = 0, j = 0; // 栈顶
    while (cin.getline(s, 101)) {
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') {
                // 左括号入栈
                ch[j] = s[i]; idx[j] = i;
                top++; j++;
            } else if (s[i] == ')') {
                if (top == 0) {
                    ch[j] = s[i]; idx[j] = i;
                    top++; j++;
                } else {
                    if (ch[j-1] == '(') {
                        top--; j--;
                    } else {
                        ch[j] = s[i]; idx[j] = i;
                        top++; j++;
                    }
                }
            }
            cout << j << " " << ch[j] << " " << idx[j] << " " <<endl;
        }
        ch[j] = '\0';
        for(int i = 0; ch[i] != '\0'; i++) {
            if (ch[i] == '(') {
                s[idx[i]] = '$';
            } else if (ch[i] == ')') {
                s[idx[i]] = '?';
            }
        }

        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '$' || s[i] == '$') {
                cout << s[i];
            } else {
                cout << ' ';
            }
        }
        
        cout << endl;
    }
    return 0;
}