/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-28 10:18:49
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-28 10:20:06
 */
#include <fstream>

#include "../ch07/ex7_26_sales_data.h"

int main(int argc, char** argv)
{
    std::ifstream input(argv[1]);                      // "../data/book.txt"
    std::ofstream output(argv[2], std::ofstream::app); // "../data/out.txt"

    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total) << std::endl;
                total = trans;
            }
        }
        print(output, total) << std::endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
    }
}
