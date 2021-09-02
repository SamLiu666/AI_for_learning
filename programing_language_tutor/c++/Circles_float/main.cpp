/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-02 10:39:28
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-02 10:47:29
 */
#include <iostream>
#include <cmath>
using namespace std;

// const float PI = 3.14;
int main(){
    double radius, area;
    cout << "Input radius: ";
    cin >> radius;

    area = M_PI * radius * radius;
    cout << "The area of a circle with radius of " << radius << " is " << area << endl;
    
    cout << "Convert double into int: " << (int)area << endl;

    return 0;

}