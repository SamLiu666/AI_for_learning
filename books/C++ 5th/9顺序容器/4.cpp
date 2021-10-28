/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-28 10:28:29
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-28 10:31:35
 */
#include <vector>
using namespace std;

bool find(vector<int>::iterator begin, vector<int>::iterator end, int target) {
    for (auto i = begin; i != end; ++i) {
        if (*i == target) {
            return true;
        }
    }
    return false;
}

vector<int>::iterator findIter(vector<int>::iterator begin, vector<int>::iterator end, int target) {
    for (auto i = begin; i != end; ++i) {
        if (*i == target) {
            return i;
        }
    }
    return end;
}