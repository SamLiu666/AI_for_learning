/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-23 20:43:55
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-23 20:55:08
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex() : r(0), i(0) {};  // 构造函数
    Complex & operator=(string s) {  // 复制构造函数
        int pos = s.find('+', 0);
        string tmpS = s.substr(0, pos);
        r = stoi(tmpS);
        tmpS = s.substr(pos + 1);
        i = stoi(tmpS);
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}