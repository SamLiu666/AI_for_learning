#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d, const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
	private:
		char *str;
	public:
		MyString():str(NULL) { }	//string(); [default]
		MyString( const char *s ) {	//string (const char* s); [c-string]
			str = new char[strlen(s)+1];
			strcpy(str,s);
		}
		MyString( const MyString & S ){	//string (const string & str); [copy]
			str = new char[strlen(S.str)+1];
			strcpy(str,S.str);
		}
		~MyString() {	//~string();
			if(str) delete [] str;
		}
		MyString & operator=( const MyString & S )	//string & operator=(const string & str); [string]
		{
			if(str) delete [] str;
			if(S.str){
				str = new char[strlen(S.str)+1];
				strcpy(str,S.str);		
			}
			else str = NULL;
			return *this;			
		}
		MyString & operator=( const char *s )	//string & operator=(const char* s); [c-string]
		{
			if(str) delete [] str;
			if(s){
				str = new char[strlen(s)+1];
				strcpy(str,s);		
			}
			else str = NULL;
			return *this;
		}
		MyString & operator=( char c )	//string & operator=(char c); [character]
		{
			if(str) delete [] str;
			if(c){
				str = new char[1+1];
				str[0] = c; str[1] = '\0';
			}
			else str = NULL;
			return *this;			
		}
		MyString & operator+=( const char *s )	//string & operator+=(const char* s);
		{
			if( str && s ){
				int len = strlen(str);
				char *t = new char[len+1];
				strcpy(t,str);
				delete [] str;
				str = new char[len+strlen(s)+1];
				strcpy(str,t);
				delete [] t;
				strcat(str,s);
			}
			if( !str && s ){
				str = new char[strlen(s)+1];
				strcpy(str,s);
			}
			return *this;
		}
		char & operator[]( int pos )	//char & operator[](size_t pos);
		{
			return str[pos];			
		}
		MyString operator()( int pos, int len )	//string substr (size_t pos = 0, size_t len = npos); [string::npos - all chars till the end]
		{
			MyString S;
			S.str = new char[len+1];
			for( int i = 0; i < len; i++ )
				S.str[i] = str[pos+i];
			S.str[len] = '\0';
			return S;			
		}
	friend bool operator==( const MyString & lhs, const MyString & rhs )
	{
		return strcmp(lhs.str,rhs.str) ? false : true;		
	}
	friend bool operator<( const MyString & lhs, const MyString & rhs )
	{
		return ( strcmp(lhs.str,rhs.str) < 0 ) ? true : false;		
	} 
	friend bool operator>( const MyString & lhs, const MyString & rhs )
	{
		return ( strcmp(lhs.str,rhs.str) > 0 ) ? true : false;		
	}	
	friend MyString operator+( const MyString & lhs, const MyString & rhs )	//string operator+(const string & lhs, const string & rhs);
	{
		char *s = new char[strlen(lhs.str)+strlen(rhs.str)+1];
		strcpy(s,lhs.str);
		strcat(s,rhs.str);
		return MyString(s);		
	}
	friend MyString operator+( const MyString & lhs, const char *rhs )	//string operator+(const string & lhs, const char * rhs);
	{
		char *s = new char[strlen(lhs.str)+strlen(rhs)+1];
		strcpy(s,lhs.str);
		strcat(s,rhs);
		return MyString(s);					
	}
	friend MyString operator+( const char *lhs, const MyString & rhs )	//string operator+(const char * lhs, const string & rhs);
	{
		char *s = new char[strlen(lhs)+strlen(rhs.str)+1];
		strcpy(s,lhs);
		strcat(s,rhs.str);
		return MyString(s);
	}
	friend ostream & operator<<( ostream & os, const MyString & S ) //ostream & operator<<(ostream & os, const string & str);
	{
		if(S.str)
			cout << S.str;
		return os;		
	}		
};
 
int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
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
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}