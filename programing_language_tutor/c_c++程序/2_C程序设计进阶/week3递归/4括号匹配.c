/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-10 10:17:08
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-10 11:48:40
 */
#include <iostream>
using namespace std;

int main() {
    char ch[101]; int index[101];
    char s[101];
    int top = 0, j = 0; // 栈顶
    while (cin.getline(s, 101)) {
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') {
                ch[i] = s[i]; 
                index[i] = i;
                top++;
            } else if (s[i] == ')') {
                if (top == 0) {
                    // 右括号入栈
                    ch[j] = s[i]; 
                    index[j] = i;
                    top++; j++;
                } else {
                    if (ch[j-1] == '(') {
                        //出栈
                        top--; j--;
                    } else {
                        // 右括号入栈
                        ch[j] = s[i]; 
                        index[j] = i;
                        top++; j++; 
                    }
                }
        }
    }
    
    for (int i = 0; i < top; i++) {
        if (ch[i] == '(') {
            s[index[i]] = '$';
        } else {
            s[index[i]] = '?';
        }
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '?' || s[i] != '$') {
            cout << ' ';
        } else {
            cout << s[i];
        }
    }
    cout << endl;
    }
    
    return 0;
}