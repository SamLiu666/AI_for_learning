/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-11-02 09:58:24
 * @LastEditors: lxp
 * @LastEditTime: 2021-11-02 09:58:37
 */
#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "3.h"

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
		Quote(b, p), min_qty(q), discount(disc)
	{}

	double net_price(std::size_t n) const override;

private:
	std::size_t min_qty = 0;
	double      discount = 0.0;
};

#endif // BULK_QUOTE_H