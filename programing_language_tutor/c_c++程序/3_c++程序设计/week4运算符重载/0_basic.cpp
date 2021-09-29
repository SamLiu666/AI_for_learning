/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-23 15:20:06
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-23 15:44:26
 */
#include <iostream>
using namespace std;

class CArray {
    int size; // 数组元素的个数
    int *ptr; // 指向动态分配的数组

public:
    CArray(int s = 0); // s 代表数组元素个数
    CArray(CArray & a);  // 复制构造函数
    ~CArray();              // 析构函数
    void push_back(int v); // 用于在数组尾部添加一个元素
    CArray & operator=(const CArray & a); // 用于数组对象间的赋值
    int length() { return size; } // 返回数组元素个数
    int & CArray::operator[](int i) { return ptr[i]; }
};

CArray::CArray(int s):size(s) {
    if (s == 0) {
        ptr = NULL;
    } else {
        ptr = new int[s];
    }
}

CArray::CArray(CArray & a) {
    if (!a.ptr) {
        ptr = NULL; size = 0; return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}

CArray::~CArray() {
    if (ptr) {
        delete [] ptr;
    }
}

CArray & CArray::operator=(const CArray & a) {
    // 深拷贝的效果
    // 赋值号作用是使"=“左边对象里存放的数组，大小和内容和右边对象都一样
    if (ptr == a.ptr) { return * this; } //  防止 a == a 这样的赋值导致出错
    if (a.ptr == NULL) { // 如果a里面数组使空的
        if (ptr) delete [] ptr;
        ptr = NULL;
        size = 0;
        return * this;
    }
    if (size < a.size) { // 原有空间足够大
        if (ptr) { delete [] ptr; }
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}

void CArray::push_back(int v) {
    if (ptr) {
        int * tmpPtr = new int[size+1]; // 重新分配空间
        memcpy(tmpPtr, ptr, sizeof(int)*size);  // 拷贝原数组内容
        delete []ptr;
        ptr = tmpPtr;
    } else {
        ptr = new int[1];
    }
    ptr[size++] = v; // 加入新的数组元素
}
