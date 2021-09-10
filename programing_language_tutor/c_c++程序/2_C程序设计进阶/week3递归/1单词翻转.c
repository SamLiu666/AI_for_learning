/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-09 11:11:42
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-10 09:52:57
 */
#include <iostream>
using namespace std;
void inverseStr(char *, int start, int end);
void flip(char arr[], int i);

int main() {
    char s[501];
    cin.getline(s, 501);
    
    int i = 0, start = 0, end = 0;
    bool flipFlag = false, startFalg=true;
    char word[501] = {'\0'};
    while (s[i++] != '\0') {
        if (s[i] == ' '){
            startFalg = true;
            word[end] = '\0';
            if (!flipFlag) {
                cout << word;
                // inverseStr(word, start, end - 1);
                flip(char word,  int 0)
                cout << word;
            }
            flipFlag = true;
            cout << ' ';
        } else{
            if (startFalg) {
                end = 0;
                flipFlag = false; 
                startFalg = false;
            }
            word[end++] = s[i];
        }

        // 最后一个单词
    }
    // if (!flipFlag) {
    //     word[end] = '\0';
    //     inverseStr(word, 0, end - 1);
    //     flipFlag = true; cout << ' ';
    // }
    return 0;
}

void flip(char arr[], int i) {
    if (arr[i] != '\0') {
        flip(arr, i+1);
        cout << arr[i] << "";
    } else {
        return;
    }
}

void inverseStr(char * arr,  int start, int end) {
    // cout << " " << start << " " << end << " " << arr;
    if (start < end) {
        char temp = arr[end]; arr[end] = arr[start]; arr[start] = temp;
        inverseStr(arr, ++start, --end);
    }
}