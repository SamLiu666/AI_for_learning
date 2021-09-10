/*
 * @Description:
 * 搜索问题：
 * 1、枚举可能的动作
 * 2、尝试这个动作
 * 3、递归计算更简单的情况
 * 4、撤销这个动作
 * 返回值
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-10 17:50:02
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-10 18:22:06
 */
#include <iostream>
using namespace std;

int main() {
    int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int *p = a + 5,  *q = NULL;
    cout << "run; " << a << endl;
    *q = *(p + 1);
    cout << *p << " " << *q << a << endl;

    return 0;
}