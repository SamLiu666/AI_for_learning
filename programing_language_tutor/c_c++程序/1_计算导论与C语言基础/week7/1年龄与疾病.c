/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 20:38:19
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 20:52:43
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    double c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    int n;
    cin >> n;  // 病人数目
    for (int i = 0; i < n; i++) {
        int age;
        cin >> age;
        if (age <= 18){
            c1++;
        } else if (age >= 19 && age <= 35){
            c2++;
        } else if (age >= 36 && age <= 60){
            c3++;
        } else if (age > 60){
            c4++;
        }
    }
    c1 = (double)c1/n*100;
    c2 = (double)c2/n*100;
    c3 = (double)c3/n*100;
    c4 = (double)c4/n*100;
    // cout << "1-18: %4.2f%" << c1 <<  << endl;
    printf("1-18: %4.2f%\n", c1);
    printf("19-35: %4.2f%\n", c2);
    printf("36-60: %4.2f%\n", c3);
    printf("60-: %4.2f%\n", c4);

    //输出可以用 cout<<fixed<<setprecision(2) << f; 来保留f后面的两位小数。
    return 0;
}