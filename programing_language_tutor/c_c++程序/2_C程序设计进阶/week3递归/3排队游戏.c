/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-09 12:10:12
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-10 10:11:05
 */
#include <iostream>
using namespace std;
void paidui(char kid[]);

int main() {
    char kid[101];
    cin.getline(kid, 101);
    paidui(kid);
    return 0;
}

void paidui(char s[]) {
    int num=0;
    int end=0;
    char boy = s[0];
    int a[105];
    a[0] = 0;
    for(int i=0;s[i]!='\0';i++){
        if(boy==s[i]){
            end++;
            num++;
            a[end] = num;
        }
        else{
            num++;
            cout<<a[end]-1<<" "<<num-1<<endl;
            end--;
        }
    }
    return ;
}