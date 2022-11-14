#include <iostream>
#include <cstring>//strcoy,strcmp
using namespace std;

class String {
private:
	char* _chars;
public:
	String(){}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] }
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	bool operator==(const String& str)const 
	{
		return strcmp(_chars, str._chars) == 0;
	}
	bool operator!=(const String& str)const
	{
		return strcmp(_chars, str._chars) != 0;
	}
	bool operator>(const String& str)const
	{
		return strcmp(_chars, str._chars) > 0;
	}
	bool operator<(const String& str)const
	{
		return strcmp(_chars, str._chars) < 0;
	}
	bool operator>=(const String& str)const
	{
		//>=의 반대 = <
		return !(*this < str);
	}
	bool operator<=(const String& str)const
	{
	//<=의 반대 = >
		return !(*this > str);
	}


};

int main() { 

	String str0{ "abc" };
	String str1{ "cde" };

	if (str0 == str1)//str0.operator==(str1) (1)==연산자 오버로딩
		cout << "equal" << endl;

	if (str0 != str1)//str0.operator!=(str1) (2)!=연산자 오버로딩
		cout << "not equal" << endl;

	if (str0 > str1)//str0.operator>(str1) (3)>연산자 오버로딩
		cout << "str0 > str1" << endl;
	
	if (str0 < str1)//str0.operator<(str1) (4)<연산자 오버로딩
		cout << "str0 < str1" << endl;

	if (str0 >= str1)//str0.operator>=(str1) (5)>=연산자 오버로딩
		cout << "str0 >= str1" << endl;

	if (str0 <= str1)//str0.operator<=(str1) (6)<=연산자 오버로딩
		cout << "str0 <= str1" << endl;






}