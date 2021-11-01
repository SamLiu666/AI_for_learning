/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-11-01 20:35:19
 * @LastEditors: lxp
 * @LastEditTime: 2021-11-01 20:35:20
 */
#include <3.h>

#include <iostream>
#include <string>
#include <map>
#include <functional>

double print_total(std::ostream& os, const Quote& item, size_t n);

int main()
{


	return 0;
}


double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}