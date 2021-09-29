/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-29 09:59:00
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-29 10:01:32
 */
#include<iostream>
using namespace std;
 
template <class T>
class CArray3D
{
	class A//二维数组
	{
		class B//一维数组
		{
			T *ppp;
		public:
			B() { ppp = NULL; }
			~B() { if (ppp) delete []ppp; }
			void creat(int k) { ppp = new T[k]; }
			T& operator[](int k) { return ppp[k]; }
			
		};
		B *pp;
	public:
		A() { pp = NULL; }
		~A() { if (pp) delete[]pp; }
		void creat(int j, int k) {
			pp = new B[j];
			for (int l = 0; l < j; l++)
				pp[l].creat(k);
		}
		B & operator[](int j) { return pp[j]; }
	};
	A *p;
public:
	CArray3D(int i, int j, int k)
	{ 
		p = new A[i]; 
		for (int l = 0; l < i; l++)
			p[l].creat(j, k);
	}
	~CArray3D()
	{
		if (p) delete[]p;
	}
	A & operator[](int i) { return p[i]; }
};
 
int main()
{
	CArray3D<int> a(3, 4, 5);
	int No = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				a[i][j][k] = No++;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				cout << a[i][j][k] << ",";
	return 0;
}