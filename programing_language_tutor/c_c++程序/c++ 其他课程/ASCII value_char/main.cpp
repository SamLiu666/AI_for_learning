/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-02 10:58:54
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-02 11:19:59
 */
#include <iostream>
#include <string>
using namespace std;

int main(){
    char inputChar;
    int asciiInt;
    cout << "Please Input a character: ";
    cin >> inputChar;
    
    asciiInt =(int)inputChar;

    cout << "The ASCII value of " << inputChar << " is " << asciiInt << endl;
    
    // * character
    char ch;
    cout << '\n';
    cout << endl;

    char ch1, ch2;
    ch1 = 'a';
    ch2 = 'a' + 1;  // 98

    cout << " ch2:" << ch2 << " ch1:" << 'a' + 1 << endl;

    // TODO: 大写输入字母
    char lowChar, upperChar;
    int offset;
    cout << "Input lowchar: ";
    cin >> lowChar;
    offset = (int)(lowChar -'a');
    upperChar = (char)('A' + offset);
    cout << "lowchar : " << lowChar << "upperchar: " << upperChar << endl;

    // * string
    string s = "hello";
    s = s + " world! ";
    cout << "s: " << s << endl;
    return 0;
}