/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-08 09:43:06
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-08 09:48:40
 */
#include<iostream>
#include<stdio.h>
int isLeapYear(int year);
int main()
{
    int y,m,d;
    int year,month,day;
    int monthCarrySave=0;
    int yearCarrySave=0;
    scanf("%d-%d-%d",&y,&m,&d);
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        if(d==31){
            day=1;
            monthCarrySave=1;
        }
        else day=d+1;
    }
    else {
        if(m==2){
            if(d==28){
                if(isLeapYear(y)){
                    day=1;
                    monthCarrySave=1;
                }
                else{
                    day=d+1;
                }
            }
            else if(d==29){
                day=1;
                monthCarrySave=1;
            }
            else{
                day=d+1;
            }
        }
        else{
            if(d==30){
                day=1;
                monthCarrySave=1;
            }
            else {
                day=d+1;
            }
        }
    }
    month=m+monthCarrySave;
    if(month>12){
        month=1;
        yearCarrySave=1;
    }
    year=y+yearCarrySave;
    printf("%d-%02d-%02d\n",year,month,day);
    return 0;
}
int isLeapYear(int year)
{
    if(year%4==0&&year%100!=0||year%400==0)
        return 1;
    else return 0;
}