/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 09:25:11
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 09:40:59
 */
#include <iostream>
using namespace std;


int main() {
    int a[10];
    for (int i=0; i<10; i++){
        cin >> a[i];
    }

    // 排奇偶
    int left=0, right=9;
    while (left <= right){
        bool leftIsOdd = a[left] % 2 == 1;  //奇数
        bool rightIsEven = a[right] % 2 == 0; //偶数
        if (leftIsOdd){
            left++;
        } else if (rightIsEven){
            right--;
        } else if (!leftIsOdd && !rightIsEven){
            int temp = a[left]; a[left] = a[right]; a[right] = temp;
        }
    }

    // 对左右分别排序
    for (int i=0; i<left-1; i++){
        for (int j=1; j<left-i; j++){
            if (a[j-1] > a[j]){
                int temp = a[j-1]; a[j-1] = a[j]; a[j] = temp;
            }
        }
    }

    for (int i=left; i<10-1; i++){
        for (int j=left+1; j<left+10-i; j++){
            if (a[j-1] > a[j]){
                int temp = a[j-1]; a[j-1] = a[j]; a[j] = temp;
            }
        }
    }
      // 冒泡，不断比较相邻的两个数，如果顺序错了，那么就交换
      for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 10 - i; j++) {      
      // 与刚才的冒泡排序不同，我们不只是通过较数字的大小决定顺序
      // 如果左边的为偶数，右边的为奇数，那么顺序也需要颠倒
      bool leftIsEven = a[j - 1] % 2 == 0;
      bool rightIsEven = a[j] % 2 == 0;
      if ((leftIsEven && !rightIsEven) ||
          (leftIsEven == rightIsEven && a[j - 1] > a[j])) {        
        int temp = a[j];        
        a[j] = a[j - 1];
        a[j - 1] = temp;
      }
    }
  } 
    // 打印输出
    for (int i=0; i<10; i++){
        cout << a[i] << ' ';
    }
    return 0;
}