/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-29 13:57:41
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-29 14:00:06
 */
#include <iostream> 
#include <iterator> 
#include <set> 
using namespace std;
int main() { 
    int a[] = {8,7,8,9,6,2,1}; 
// 在此处补充你的代码
    set<int> v(a, a+7);
    ostream_iterator<int> o(cout," ");
    copy( v.begin(),v.end(),o); 
    return 0;
}