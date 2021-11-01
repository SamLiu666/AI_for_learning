/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-31 11:13:21
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-31 11:19:02
 */
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

vector<int>* alloc_vector() {
    // return make_shared<vector<int>>;
    return new vector<int>();
}

void assign_vector(vector<int>* p) {
    int i;
    while(cin >> i) {
        p->push_back(i);
    }
}

void print_vector(vector<int>* p) {
    for (auto i : *p) {
        cout << i << endl;
    }
}

int main() {
    auto p = alloc_vector();
    assign_vector(p);
    print_vector(p);

    return 0;
}