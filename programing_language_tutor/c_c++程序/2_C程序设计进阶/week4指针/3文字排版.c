/*
 * @Description: am
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-11 15:34:15
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-11 15:53:46
 */
#include <iostream>
using namespace std;

int main() {
    int n;  cin >> n;
    char word[1000][40] = {};
    int w_len[1000] = {};  // 存放对应单词长度
    for (int i = 0; i < n; i++) {
        cin >> word[i];
        int j = 0;
        while (word[i][j] != '\0') {
            j++;
        }
        w_len[i] = j;
        // cout << word[i] << " " << w_len[i] << endl;
    }

    // TODO: 输出短文
    int t_len = 0, start = 0, i = 0, j = 0;
    for (; i < n; i++) {
        t_len = t_len + w_len[i] + 1;  // 加上空格
        if (t_len > 81) {
            for (j = start; j < i - 1; j++) {
                cout << word[j] << ' ';
            }
            cout << word[j] << endl;
            // 初始化
            t_len = 0; start = i; i--; 
        }
    }
    for (; j < i -1; j++) {
        cout << word[j] << ' ';
    }
    cout << word[j] << endl;
    
    return 0;
}