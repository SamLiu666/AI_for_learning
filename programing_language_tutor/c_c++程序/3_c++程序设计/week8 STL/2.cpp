/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-29 14:02:39
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-29 14:02:40
 */
#include<iostream>
#include<list>
#include <iterator> 
#include<vector>
#include<string>
using namespace std;
 
int GetNum(string &s)//用来读取命令后面的数字的，包括id和num
{
	int pos=s.rfind(" ");
	string num = s.substr(pos + 1, s.length() - 1 - pos);
	s.erase(pos);
	return stoi(num);
}
 
 
int main()
{
	//以下两行是用来读取和输出测试数据的
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n; cin >> n;
	cin.get();
	vector<string> command(n);
	string tmp;
	for (int i = 0; i < n; i++)
	{
		getline(cin, tmp);
		command[i]=tmp;
	}
	vector<list<int>> lst(10000);
	for (int i = 0; i < n; i++)//判断是否是add命令
	{
		if (command[i].at(0)=='a')
		{
			int num = GetNum(command[i]);
			int id = GetNum(command[i]);
			lst[id-1].push_back(num);
		}
		else if (command[i].at(0) == 'm')//判断是否是merge命令
		{
			int id2 = GetNum(command[i]);
			int id1 = GetNum(command[i]);
			lst[id1 - 1].merge(lst[id2 - 1]);
		}
		else if (command[i].at(0) == 'u')//判断是否是unique命令
		{
			int id = GetNum(command[i]);
			lst[id - 1].sort();
			lst[id - 1].unique();
		}
		else if (command[i].at(0) == 'o')//判断是否是out命令
		{
			int id = GetNum(command[i]);
			lst[id - 1].sort();
			
			ostream_iterator<int> o(cout, " ");
			copy(lst[id - 1].begin(), lst[id - 1].end(), o);
			cout << endl;
		}
	}
	return 0;
}