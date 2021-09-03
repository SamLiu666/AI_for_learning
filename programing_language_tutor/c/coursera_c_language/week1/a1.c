/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-03 10:14:59
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-03 11:25:19
 */
#include<stdio.h>
#include<math.h>
int main(void)
{   
    printf("hello world\n");
    int a = 6;
    printf("sizeof %lu \n", sizeof(a));
    printf("sizeof %lu \n", sizeof(int));

    double num;
    printf("Input num: ");
    scanf("%lf", &num);
    printf("sin(%lf) is %lf", num, sin(num));
    return 0;
}