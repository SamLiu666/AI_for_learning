/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-29 15:25:30
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-29 15:27:44
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using std::string;

int main()
{   
	std::ifstream ifs("C:\\Users\\lxp\\Desktop\\AI_for_learning\\books\\C++ 5th\\10泛型算法\\book.txt");
	std::istream_iterator<string> in(ifs), eof;
	std::vector<string> vec;
	std::copy(in, eof, back_inserter(vec));

	std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<string>(std::cout, "\n"));
	
    for (auto v : vec) std::cout << v << " ";
    return 0;
}