/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-04 12:00:26
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-04 12:06:32
 */
#include <iostream>
// #define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
    int h, r, result;
    double water, m_Pi=3.14159;
    cin >> h >> r;
    water = (double)m_Pi * r * r * h / 1000;
    // result = (int)20 / water;
    cout << ceil(20.0 / water) << endl;
}