#include <iostream>
#include <cstring>
using namespace std;

class Vector {
private:
	float x, y, z;
	char* _chars;
public:
	Vector() {}
	Vector(float x, float y, float z,const char* chars) 
		:x{ x }, y{ y }, z{ z },_chars(new char[strlen(chars)+1]) 
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}
	Vector(Vector& v)
		:Vector(v.x, v.y, v.x, v._chars) 
	{
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		cout << "copy" << endl;
	}
	~Vector() {
		delete[]_chars;
	}
	Vector operator=(const Vector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;

		delete[]_chars;
		_chars = new char[strlen(v._chars) + 1];
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
	}
	
	friend ostream& operator<<(ostream& os, Vector& v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}
};

int main() {

	int a = 1;
	int b = a;//복사
	int c;
	c = a;//대입

	Vector v0{ 1,2,3,"abc"};
	Vector v1 = v0; //복사->얕은 복사->깊은복사->복사생성자
	Vector v2;
	v2 = v0;//대입 -> v2.operator=(v0)

	cout << v0 << endl;
	cout << v1 << endl;
	cout << v2 << endl;
}