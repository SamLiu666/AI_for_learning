/*
 * @Description:
 经过观察可知在程序运行时val需要被赋值为0，由此想到用于成员初始化的构建函数（Constructor）。
此外，a.GetObj() = 5;这一句很明显是用于修改变量val的。
所以根据提示，填空处用GetObj()这个“别名”指向了变量val，函数声明加&。
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-15 18:00:56
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-23 14:25:55
 */
#include <iostream>
using namespace std;
class A {
public:
    int val;
// 在此处补充你的代码
    A(int n = 0) { val = n; }
    int & GetObj() {
        return val;
    }
};
main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}