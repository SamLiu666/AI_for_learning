/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-24 14:51:53
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-24 15:54:23
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
 // 打开文件, 
 /* 
 *ios::out -- 输出到文件，删除原有内容
 *ios::app -- 输出到文件，保留原有内容，总是在尾部添加
 *ios::binary -- 以二进制文件格式打开文件
 */
class CStudent {
    public:
        char szName[20];
        int nScore;
};

int main() {
    // 写文件
    CStudent s;
    ofstream OutFile("student.dat", ios::out|ios::binary);
    while (cin >> s.szName >> s.nScore) {
        if (stricmp(s.szName, "exit") == 0) { break; }
        OutFile.write((char *) & s, sizeof(s) );
    }
    OutFile.close();

    // 读文件
    ifstream inFile("student.dat", ios::in|ios::binary);
    if (!inFile) { 
        cout << "error" << endl;
        return 0;
    }
    while (inFile.read( (char*) & s, sizeof(s) )) {
        int nReadedBytes = inFile.gcount(); // 读了多少字节
        cout << s.szName << " " << s.nScore << endl;
    }
    inFile.close();

    // 读写文件
    fstream iofile("student.dat", ios::in|ios::out|ios::binary);
    if (!iofile) {
        cout << "error" << endl;
        return 0;
    }

    iofile.seekp(2 * sizeof(s), ios::beg); // 定位到写指针的第三个记录
    iofile.write("Mike", strlen("Mike") + 1);
    iofile.seekg(0, ios::beg); // 定位读指针到开头
    while (iofile.read( (char *) & s, sizeof(s)) ) {
        cout << s.szName << " " << s.nScore << endl;
    }
    iofile.close();
    return 0;
}