/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-03 09:44:30
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-03 10:03:18
 */
#include <stdio.h>

#define PI 3.141592653589793

int main(){
    double area=0.0, radius=0.0;
    printf("Input radius: ");
    scanf("%lf", &radius);
    area = PI * radius * radius;
    printf("radius of %lf meters; area is %lf sq. meters \n", radius, area);
    return 0; 
}