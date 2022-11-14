#include <iostream>
using namespace std;

class Vector {
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}

	Vector operator+()const
	{
		return Vector{ +x,+y,+z };
	}
	
	Vector operator+(const Vector& v)const
	{
		return Vector{ x + v.x,y + v.y,z + v.z };
	}
	
	Vector operator-() const
	{
		return Vector{ -x,-y,-z };
	}

	float operator*(const Vector& v)const 
	{
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return	dot;
	}
	Vector operator* (float n)const {
		return Vector(x * n, y * n, z * n);
	}

	Vector operator/ (float n)const {
		return Vector(x / n, y / n, z / n);
	}

	Vector operator-(const Vector& v)const
	{
		return Vector{ x - v.x,y - v.y,z - v.z };
	}

	Vector& operator++() 
	{
		++x;
		++y;
		++z;
		return *this;
	}
	Vector& operator++(int) 
	{
		Vector temp = *this;
		++x;
		++y;
		++z;
		return temp;	
	}

	void print() {
		cout << x << " " << y << " " << z << endl;
	}

};

int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	Vector v10 = +v1;//(1)단항연산자+
	v10.print();

	Vector v3 = -v1;//(2)단항연산자-
	v3.print();
	
	Vector v2 = v0 + v1;//(3)이항연산자+ 
	v2.print();

	Vector v9 = v1 - v0;//(4)이항연산자-
	v9.print();


	//(5)이항연산자*
	//벡터연산, 내적계산 -> (v0.x*v1.x)+(v0.y*v1.y)=float
	//벡터 * 실수값 -> 벡터
	float v4 = v0 * v1;//v0.operator*(v1)
	cout << v4 << endl;//0+2+6=8

	Vector v5 = v1 * 3.0f;//v1.operator*(3.0f)
	v5.print();

	Vector v11{ 3,6,9 };
	Vector v12 = v11 / 3.0f;//(6)이항연산자/
	v12.print();

	//++v1(7)전위연산자++
	//v1++(8)후위연산자++
	Vector v6 = ++v1;//v1.operator++()
	v6.print();

	Vector v7 = v1++;
	v7.print();
	v1.print();
}