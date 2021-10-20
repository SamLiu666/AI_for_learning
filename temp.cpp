/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-02 14:29:30
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-20 16:44:52
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    string word;
    vector<string> text; // empty vector
    while (cin >> word) {
        text.push_back(word); // append word to text
    }
    for (auto x:text) {
        cout << "x: " << x;
    }
	return 0;
}