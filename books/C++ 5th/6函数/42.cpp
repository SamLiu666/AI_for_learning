/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-25 11:48:37
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-25 11:48:38
 */
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

string make_plural(size_t ctr, const string& word, const string& ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	cout << "single: " << make_plural(1, "success", "es") << " "
		<< make_plural(1, "failure") << endl;
	cout << "plural : " << make_plural(2, "success", "es") << " "
		<< make_plural(2, "failure") << endl;

	return 0;
}
