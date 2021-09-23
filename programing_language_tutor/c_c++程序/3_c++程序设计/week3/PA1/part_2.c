/*
 * @Description:
 实际是考察复制构造函数的写法。
 只不过输出的内容是我们赋值时的两倍（5变成10），所以需要自行定义赋值构造函数
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-15 18:00:56
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-23 14:27:20
 */
#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
// 在此处补充你的代码 
    Sample(const Sample &s) {
        v = s.v * 2;
    }
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}