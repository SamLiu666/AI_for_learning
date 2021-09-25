#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class MyString:public string
{
	public:
		MyString():string() {}	//string(); 
		MyString( const char * s ):string(s) {}	//string (const char* s);
		MyString( const MyString & ms ):string(ms) {}	//string (const string & str);
		~MyString() {}	//~string();
		MyString operator()( int pos, int len )	//string substr (size_t pos = 0, size_t len = npos); [string::npos - all chars till the end]
		{
			string str = this->substr(pos,len);
			return MyString( str.c_str() );			
		} 
	friend MyString operator+( const MyString & lhs, const MyString & rhs )	//string operator+(const string & lhs, const string & rhs);
	{
		string str1 = lhs, str2 = rhs;
		return MyString( (str1+str2).c_str() );		
	}
	friend MyString operator+( const MyString & lhs, const char * rhs )	//string operator+(const string & lhs, const char * rhs);
	{
		string str1 = lhs;
		return MyString( (str1+rhs).c_str() );		
	}
	friend MyString operator+( const char * lhs, const MyString & rhs )	//string operator+(const char * lhs, const string & rhs);
	{
		string str2 = rhs;
		return MyString( (lhs+str2).c_str() );
	}
};
 
 
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
        sort(SArray,SArray+4);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}