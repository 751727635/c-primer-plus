#include <iostream>
#include<math.h>
#include"vect.h"
using namespace std;
namespace VECTOR 
{
	Vector::Vector()//默认是原点
	{
		x = 0, y = 0, mag = 0, ang = 0,mode=RECT;
	}
	void Vector::set_mag()//设置极坐标的r
	{
		mag = sqrt(x * x + y * y);

	}
	void Vector::set_ang()//设置极坐标的θ
	{
		ang = atan2(x, y);
	}
	void Vector::set_x()//设置x
	{
		x = mag * cos(ang);
	}
	void Vector::set_y()//设置y
	{
		y = mag * sin(ang);
	}
	Vector::Vector(double n1, double n2, Mode form )//初始化坐标,输入坐标和坐标类(极坐标和直角坐标)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1, y = n2;
			set_mag();
			set_ang();
		}
		else
		{
			mag = n1, ang = n2;
			set_x();
			set_y();
		}
	}
	void Vector::reset(double n1, double n2, Mode form)//重置
	{
		if (form == RECT)
		{
			x = n1, y = n2;
			set_mag();
			set_ang();
		}
		else
		{
			mag = n1, ang = n2;
			set_x();
			set_y();
		}
	}
	void Vector::polar_mode()//切换模式
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}
	Vector Vector::operator+(const Vector& b) const
	{
		Vector plus;
		plus.x = x + b.x;
		plus.y = y + b.y;
		plus.set_ang(), plus.set_mag();
		return plus;
	}
	Vector Vector::operator-(const Vector& b) const
	{
		Vector plus;
		plus.x = x - b.x;
		plus.y = y - b.y;
		plus.set_ang(), plus.set_mag();
		return plus;
	}
	Vector Vector::operator*(double n) const
	{
		Vector product;
		product.x = n * x;
		product.y = n * y;
		product.set_mag();
		product.set_ang();
		return product;
	}

	Vector operator*(double n, const Vector& a)
	{
		Vector product;
		product.x = n * a.x;
		return a * n;
	}
	ostream& operator<<(ostream& os, const Vector& v)
	{
		if (v.mode==Vector::RECT)
		{
			os << "x:" << v.x<<endl<<"y: "<<v.y<<endl;
		}
		else if(v.mode==Vector::POL)
		{
			os << "mag: " << v.mag << endl << "ang: " << v.ang << endl;
		}
		else
		{
			os << "Vector object is invalid.\n";
		}
		return os;
	}
}
