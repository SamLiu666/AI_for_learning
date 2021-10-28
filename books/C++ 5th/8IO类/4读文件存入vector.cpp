/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-28 10:07:57
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-28 10:14:10
 */
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void ReadFileToVec(const string& filename, vector<string> vec) {
    ifstream ifs(filename);
    if(ifs) {
        string buf;
        // *读取每一行
        while(getline(ifs, buf)) {
            vec.emplace_back(buf);
        }
        // * 读取每一个单词
        // while (ifs >> buf) {
        //     vec.emplace_back(buf);
        // }
    }
}

int main() {
    vector<string> vec;
    ReadFileToVec("books\\C++ 5th\\8IO类\\book.txt", vec);
    for (const auto& str : vec) 
        cout << str << endl;
    return 0;
    
}