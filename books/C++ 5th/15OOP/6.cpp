/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-11-02 09:59:07
 * @LastEditors: lxp
 * @LastEditTime: 2021-11-02 09:59:08
 */
#include "3.h"
#include "5.h"

#include <iostream>
#include <string>

double print_total(std::ostream& os, const Quote& item, size_t n);

int main()
{
	// ex15.6
	Quote q("textbook", 10.60);
	Bulk_quote bq("textbook", 10.60, 10, 0.3);

	print_total(std::cout, q, 12);
	print_total(std::cout, bq, 12);

	return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);

	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}