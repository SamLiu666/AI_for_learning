/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-30 11:22:59
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-30 11:29:42
 */
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;


void ex8() {
    vector<string> exclude = {"aa", "bb", "cc", "dd", "ee", "ff"};
    for (string word; cout << "Enter piz: \n", cin >> word;) {
        auto is_exclude = binary_search(exclude.cbegin(), exclude.cend(), word);
        auto reply = is_exclude ? "exclude" : "not exclude";
        cout << reply << endl;
    }

}

int main()
{

    cout <<"ex8()" << endl;
    ex8();

	return 0;
}