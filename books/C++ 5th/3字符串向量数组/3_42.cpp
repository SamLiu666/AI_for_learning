/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-21 20:22:13
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-21 20:45:06
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr[10];
	for (auto i = 0; i != v.size(); ++i) 
		arr[i] = v[i];

	for (auto i : arr) cout << i << " ";
	cout << endl;
    cout << endl;
    const char ca[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }

    string a = "hello";
    string b = a;
    string* p = &a;
    string* q = &b;
    cout << " " << p << endl;
    cout << " " << q << endl;

    return 0;

}