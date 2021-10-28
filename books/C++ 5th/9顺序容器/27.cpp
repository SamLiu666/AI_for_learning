/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-28 11:35:49
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-28 13:34:53
 */
#include <iostream>
#include <forward_list>
#include <vector>

using std::forward_list;
using std::cout;
using std::endl;
using namespace std;

int main()
{
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto prev = flst.before_begin(), curr = flst.begin();
         curr != flst.end();)
        if (*curr & 0x1)
            curr = flst.erase_after(prev);
        else
            prev = curr++;

    for (auto i : flst) cout << i << " ";
    cout << endl;

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		cout << "capacity: " << v.capacity() << "  size: " << v.size() << endl;
		v.push_back(i);
	}
    v.reserve(1024);
	return 0;

}