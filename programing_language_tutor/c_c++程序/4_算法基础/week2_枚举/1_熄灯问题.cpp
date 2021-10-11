/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-11 17:20:48
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-11 17:40:00
 */
#include<iostream>
#include<stdlib.h>
using namespace std;
 
int puzzle[6][8];//初始值的按钮矩阵
int press[6][8];//设置的按钮矩阵
//验证由局部状态引起的变换是不是满足条件的
bool guess(){
	int r, c;
	for (r = 1; r < 5; ++r)
		for (c = 1; c < 7; ++c)
			press[r + 1][c] = (puzzle[r][c] + press[r][c] + press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;
	//确定了第一行之后，剩下的行数（不包括最后一行）的状态是由puzzle数组和press数组共同掌握的。
	//上一行的亮暗是由下一行决定的(相同的列)，但是上一行的状态又是由上、左、右以及自己的值、是否被按下所决定的。因此上一行最终若为0.则不改变，否则改变
	for (c = 1; c < 7; ++c)//判断第五行的灯能否被其余的press数组熄灭
		if ((press[5][c] + press[5][c + 1] + press[5][c - 1] + press[4][c]) % 2 != puzzle[5][c])
			//如果改变四个的状态所得的结果与初始状态一样，则表明已经熄灭了所有的灯；若为1时，改变奇数个状态，则表明为使得灯熄灭，此时不满足条件1！=1，返回true；
			//改变偶数个状态，则表明原来的灯不变，还是亮着的，返回false，继续下一个局部状态再进行验证；若为0则改变状况刚好相反！
			return false;
	return true;//在这个前面加了一个else导致出错！！
}
void enumerate(){
	int c;
	for (c = 1; c < 7; ++c)
		press[1][c] = 0;//赋值局部初始状态
	//当局部状态不满足时，进行第二次猜测，模拟二进制加法方式实现枚举，需要处理进位，此时从左往右加！只对第一行做改变
	while (guess() == false){
		press[1][1]++;
		c = 1;
		while (press[1][c]>1){
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}
	}
	return;
}
int main(){
	int r, c, cases, i;
	cout << "input cases : ";
	cin >> cases;
	for (r = 0; r < 6; ++r){
		press[r][0] = press[r][7] = 0;
		puzzle[r][0] = puzzle[r][7] = 0;
	}
 
	for (c = 1; c < 7; ++c){
		press[0][c] = 0;
		puzzle[0][c] = 0;
	}
 
	//输入数据
	for (i = 1; i <= cases; ++i){
		for (r = 1; r < 6; ++r){
			for (c = 1; c < 7; ++c)
				cin >> puzzle[r][c];
		}
		//}
		enumerate();
		//输出数据
		//for (i = 0; i < cases; ++i){
		cout << "puzzle #" << i << endl;
		for (r = 1; r < 6; ++r){
			for (c = 1; c < 7; ++c)
				cout << press[r][c];
			cout << endl;
		}
	}
	return 0;
}