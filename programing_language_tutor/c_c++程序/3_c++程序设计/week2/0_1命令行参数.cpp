/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-14 15:06:44
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-14 15:31:39
 */
#include <stdio.h>

int main(int argc, char * argv[]) {
    for (int i=0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    int a = 5, b = 7, c;
    c = a ^ b;
    printf("a = %d, b = %d, c = %d", c^b, c^a, c);
    int n = -3;
    n >>= 3;
    printf("\n%x",n);
    return 0;
}