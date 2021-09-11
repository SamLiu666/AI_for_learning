/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-09 11:11:42
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-11 14:18:04
 */
#include <iostream>
using namespace std;
void inverseStr(char *, int start, int end);
int flip(char arr[], int i);

int main() {
    char s[501], word[501];
    cin.getline(s, 501);
    bool isInvert = true;
    int i = 0, j = 0;
    while (s[i] != '\0') {  // 语句未结束
        // cout << s[i] << " : " << i << endl;
        if (s[i] != ' ') {
            word[j++] = s[i++];
            isInvert = false;
        } else {
            if (!isInvert) {
                word[j] = '\0';
                j = flip(word, 0);  // word 从0开始
                isInvert = true;
            }
            cout << ' '; // 空格，并且已经翻转，输出空格
            i++;
        }
    }
    if (!isInvert) {
        word[j] = '\0';
        j = flip(word, 0);  // word 从0开始
        isInvert = true;
    }
    return 0;
}

int flip(char arr[], int i) {
    if (arr[i] != '\0') {
        flip(arr, i+1);
        cout << arr[i] << "";
    }
    return 0;
}

void inverseStr(char * arr,  int start, int end) {
    // cout << " " << start << " " << end << " " << arr;
    if (start < end) {
        char temp = arr[end]; arr[end] = arr[start]; arr[start] = temp;
        inverseStr(arr, ++start, --end);
    }
}