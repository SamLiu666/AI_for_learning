/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-28 10:02:06
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-28 10:05:11
 */
#include <iostream>
#include <string>
using namespace std;

istream& func(istream& is) {
    string buf;
    while (is >> buf) {
        cout << buf << endl;
    }
    is.clear();
    return is;
}

int main() {
    istream& is = func(cin);
    cout << is.rdstate() << endl;
    return 0;
}