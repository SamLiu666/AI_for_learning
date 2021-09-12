/*
 * @Description: 
ab&dcAab&c9defgb
 D+d:2
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-12 19:16:50
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-12 19:50:16
 */
#include <iostream>
using namespace std;
void toSmall(char s[]);
int findMaxIdx(int zimu[]);


int main() {
    char s[501];
    cin.getline(s, 501);
    toSmall(s);  // 先全部转为小写

    int zimu[27] = {0}; // 统计每一个字母表中次数
    cout << "#### count" << endl;
    for (int i = 0; s[i] != '\0'; i++) {
        cout << "s["<< i << "]: " << s[i] << endl;
        if (s[i] >= 'a' && s[i] <= 'z') {
            int temp = (int)s[i] - 'a';
            cout << "temp : " << temp << endl;
            zimu[temp]++;
        }
    }
    // 找出第一个最大的索引
    int maxIdx1 = findMaxIdx(zimu) - 1;
    zimu[maxIdx1] = 0;
    cout << "\n maxIdx1 : " << maxIdx1 << endl;

    int maxIdx2 = findMaxIdx(zimu);  //第二大
    cout << "\n maxIdx2 : " << maxIdx2 << endl;

    char c1 = 'a' + maxIdx2; 
    char c2 = c1 - 32;
    cout << c2 << '-' << c1 << ':' << zimu[maxIdx2] << endl;

    return 0;
}

void toSmall(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        cout << "s["<< i << "]: " << s[i] << endl;
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
        cout << "s["<< i << "]: " << s[i] << endl;
    }
}

int findMaxIdx(int zimu[]) {
    cout << "zimu max idx: ";
    int maxVal = 0, maxIdx = 0;
    for (int i = 0; i < 27; i++) {
        cout << zimu[i] << " ";
        if (zimu[i] >= maxVal) {
            maxVal = zimu[i]; maxIdx = i;
        }
    }
    char maxArr[27] = {'0'};
    for (int i = 0; i < 27; i++) {
        
    }
    return maxIdx;
}