/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-08 19:49:08
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-08 20:21:30
 */
#include <iostream>
using namespace std;
void printArr(char arr[], int n);

int main() {
    // TODO input
    int n; cin >> n;
    char arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    int m; cin >> m;
    while (m--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == '*') {
                    // 被感染
                    arr[i][j] = '@';  // 将已经标记的人感染
                }
            }
        }
        cout << "m after label: " << m << endl;
        printArr(arr, n);
        for (int i = 0; i < n; i++) {
             // 将会被感染的人标记
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == '@') {
                    if (i - 1 >= 0 && arr[i - 1][j] == '.') {
                        arr[i-1][j] = '*';
                    } else if (i + 1 < n && arr[i + 1][j] == '.') {
                        arr[i + 1][j] = '*';
                    } else if (j + 1 < n && arr[i][j + 1] == '.') {
                        arr[i][j + 1] = '*';
                    } else if (j - 1 >= 0 && arr[i][j - 1] == '.') {
                        arr[i][j - 1] = '*';
                    }
                }
            }
        }
        cout << "m ganran label: " << m << endl;
        printArr(arr, n);
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '@') {
                result++;
            }
        }
    }
    cout << result << endl;
    return 0; 
}

void printArr(char *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        cout << endl;
    }
}