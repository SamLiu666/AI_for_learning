/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-09-24 16:05:20
 * @LastEditors: lxp
 * @LastEditTime: 2021-09-24 16:43:17
 */
template<Class T>
T MaxElement(T a[],int size)//size是数组元素个数
{
  T tmpMax = a[0];
  for(int i = 1;i < size;++i)
    if(tmpMax < a[i])
      tmpMax = a[i];
  return tmpMax;
}

template <class T>
  void Swap(T &x, T &y)
{
  T tmp = x;
  x = y;
  y = tmp;
}

int main()
{
  int n = 1,m = 2;
  Swap(n,m); //编译器自动生成void Swap(int &, int &)函数
  double f = 1.2, g = 2.3;
  Swap(f,g);//编译器自动生成void Swap(double &, double &)函数
  return 0;
}