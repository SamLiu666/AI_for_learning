/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-05 09:50:49
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-05 15:53:45
 */
#include <iostream>
#include <string.h>
using namespace std;

char upChar( char ch )
{
   return ( char )( ch - ( 'a' - 'A' ) );
};
 
char downChar( char ch )
{
    return ( char )( ch + ( 'a' - 'A' ) );
};

int main() {
    char s1[80], s2[80];
    gets(s1); gets(s2);
    int i = 0;
    char result;
    for (; i<80; i++){
        if (s1[i] == '\0' or s2[i] == '\0') {
            break;
        } else {
            // 都转为小写
            if (s1[i] >= 'A' && s1[i] <= 'Z'){
                s1[i] += 'a' - 'A';
            }
            if (s2[i] >= 'A' && s2[i] <= 'Z'){
                s2[i] += 'a' - 'A';
            }
            // cout << "i: " << i << endl;
            // cout << "downChar(s1[i]): " << s1[i] << " : " << s2[i] << endl;
            if (s1[i] != s2[i]){
                break;
            }
        }
    }
    if (s1[i] > s2[i]) {
        cout << ">" << endl;
    } else if (s1[i] < s2[i]) {
        cout << "<" << endl;
    } else{
        cout << "=" << endl;
    }
    return 0;
}