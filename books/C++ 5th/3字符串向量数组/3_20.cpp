/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-20 22:41:13
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-20 22:43:23
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> ivec;
	int i;
	while (cin >> i)
	{
		ivec.push_back(i);
	}

	for (int i = 0; i < ivec.size() - 1; ++i)
	{
		cout << ivec[i] + ivec[i + 1] << endl;
	}
	
	//---------------------------------
	cout << "---------------------------------" << endl;
	
	int m = 0;
	int n = ivec.size() - 1;
	while (m < n)
	{
		cout << ivec[m] + ivec[n] << endl;
		++m;
		--n;
	}
	return 0;
}