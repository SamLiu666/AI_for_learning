/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-15 10:57:07
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-15 11:25:38
 */
#include <iostream>
using namespace std;

class CRectangel {
    public:
        int w, h;

    void Init(int w_, int h_) {
        w = w_; h = h_;
    }

    int Area() {
        return w * h;
    }

    int Perimeter() {
        return 2 * (w + h);
    }
};

void swap(int &a, int &b) {
    int c;
    c = a; a = b; b = c;
}

void PrintRectangle(CRectangel &r) {
    cout << r.Area() << endl << r.Perimeter() << endl;
}
int main() {
    int w, h;
    CRectangel r;
    cin >> w >> h;
    r.Init(w, h);
    PrintRectangle(r);

    int a = 1, b = 2;
    swap(a, b);
    cout << a << " " << b << endl;

    return 0;
}