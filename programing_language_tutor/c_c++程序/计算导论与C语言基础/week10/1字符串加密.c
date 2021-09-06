/*
 * @Description: 、输入一个字符串，把每一个字符变成后续字符
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 15:47:51
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-05 15:51:03
 */
#include <iostream>
using namespace std;

int main() {
    char str[200];
    while (cin.getline(str, 200)) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == 'Z') {
                str[i] = 'A'; continue;
            }
            if (str[i] == 'z') {
                str[i] == 'a'; continue;
            }
            if (str[i] == ' ') {
                continue;
            }
            str[i]++;
        }
        cout << str << endl;
    }
    return 0;
}