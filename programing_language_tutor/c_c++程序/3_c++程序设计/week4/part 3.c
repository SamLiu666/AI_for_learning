#include <iostream>
#include <cstring>
using namespace std;
 
class Array2 {
// 在此处补充你的代码
private:
    int row, column;
    int **p;    //定义一个指针，指的是*int类型的东西
public:
    Array2(int row_, int column_):row(row_), column(column_) {
        p = new int*[row];  //左右两边都是int**
        for (int i = 0; i < column; ++i) {
            p[i] = new int[column];
        }
    }
    Array2(){}
    int* operator[](int a) {
        return p[a];    //只要重载第一个[]就可以，返回的是int*的数组指针
    }
    int operator()(int a, int b) {
        return p[a][b];
    }
    Array2(const Array2& a) {   //深拷贝
        row = a.row;
        column = a.column;
        p = new int*[row];
        for (int i = 0; i < column; ++i) {
            p[i] = new int[column];
        }
 
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                p[i][j] = a.p[i][j];
            }
        }
    }
    void operator=(const Array2 &a) {   //深拷贝
        row = a.row;
        column = a.column;
        p = new int*[row];
        for (int i = 0; i < column; ++i) {
            p[i] = new int[column];
        }
 
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                p[i][j] = a.p[i][j];
            }
        }
    }
};
 
int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}