/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-08 09:48:57
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-08 10:37:27
 */
#include <iostream>
using namespace std;
void accSort(double rate[], int idx[], int n);
int getMaxIdx(double idx[], int n);
void printArr(int arr[], int left, int right);


int main() {
    int n;
    cin >> n;
    int idx[n];
    double rate[n];
    for (int i = 0; i < n; i++){
        int id, start, end;
        cin >> id >> start >> end;
        // cout << "id: " << id << " " << start << " " << end << endl;
        rate[id-1] = 1.0 * (end - start);
        idx[id-1] = id;
    }
    // printArr(rate, 0, n);
    accSort(rate, idx, n);  // 排序
    // printArr(rate, 0, n);

    int maxIdx = getMaxIdx(rate, n);
    cout << n - maxIdx - 1 << endl;
    printArr(idx, maxIdx+1, n);
    cout << maxIdx + 1 << endl;
    printArr(idx, 0, maxIdx+1);
    return 0;
}

void accSort(double rate[], int idx[], int n){
    // 升序冒泡sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (rate[j+1] < rate[j]) {
                int temp = rate[j]; rate[j] = rate[j+1]; rate[j+1] =temp;
                int id = idx[j]; idx[j] = idx[j+1]; idx[j+1] = id;
            }
        }
    }
}

int getMaxIdx(double rate[], int n){
    int maxDiff=0, maxIdx=0;
    for (int i=0; i<n-1; i++) {
        if (rate[i+1] - rate[i]> maxDiff) {
            maxDiff = rate[i+1] - rate[i];
            maxIdx = i;
        }
    }

    return maxIdx;
}
void printArr(int arr[], int left, int right){
    // cout << "arr: ";
    for (int i=left; i<right; i++){
        cout << arr[i] << endl;
    }
}
