/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-31 11:07:38
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-31 11:07:39
 */
#include <iostream>
#include "2.h"

int main()
{
	StrBlob sb{ "hello", "world" };
	const StrBlob csb{ "const", "hello", "world", "aaa" };

	std::cout << "sb : " << sb.front() << " " << sb.back() << std::endl;
	std::cout << "csb : " << csb.front() << " " << csb.back() << std::endl;
	
	return 0;
}