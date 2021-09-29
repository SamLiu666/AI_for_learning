/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-29 10:04:52
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-29 10:11:38
 */
#include <iostream>
#include <iomanip>
using namespace std;
 
int main()
{
	double x;
	cin >> x;
	cout.setf(ios::fixed);//fixed固定小数点位数
	cout.precision(5);
	cout << x << endl;
 
	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);//科学技术
	cout.precision(8);
	cout << x << endl;

	cout << hex << x << endl;       // 16 进制
	cout << dec << setw(10) << x << endl;  // 以10个字符的宽度输出该整数
    
	return 0;
}