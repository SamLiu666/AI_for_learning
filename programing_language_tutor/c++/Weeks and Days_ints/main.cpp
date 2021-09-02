/*
 * @Description:根据天数打印星期
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-02 10:13:33
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-02 10:22:21
 */
#include <iostream>
using namespace std;

const int WEEK = 7;
int main(){
    int days;
    int weeks, remainDays;
    cout << "Days: ";
    cin >> days;
    weeks = days / WEEK;
    remainDays = days % WEEK;

    cout << days << " are " << weeks << " weeks and " \
        << remainDays << " remaindays" << endl;

    return 0;
}