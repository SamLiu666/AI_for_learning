/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-25 11:39:53
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-25 11:41:57
 */
#include <iostream>
#include <vector>
using std::vector; using std::cout;
using Iter = vector<int>::const_iterator;

void print(Iter first, Iter last)
{
    if (first != last)
    {
        cout << *first << " ";
        print(++first, last);
    }
}

int main()
{
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print(vec.cbegin(), vec.cend());
    cout << "endl" << std::endl;
    print(vec.begin(), vec.end());
    return 0;
}
