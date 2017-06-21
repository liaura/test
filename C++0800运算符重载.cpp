//运算符重载集合
#include<iostream>
#include<iomanip>
using namespace std;

class M33
{
	private:
		int m_a[3][3];
	public:
		M33(void)
		{
			for(size_t i = 0; i < 3; i++)
			{
				for(size_t j = 0; j < 3; j++)
				{
					m_a[i][j] = 0;
				}
			}
		}
		M33(int a[][3])
		{
			for(size_t i = 0; i < 3; i++)
			{
				for(size_t j = 0; j < 3; j++)
				{
					m_a[i][j] = a[i][j];
				}
			}
		}
		friend ostream& operator<<(ostream& os, const M33& m)
		{
			for(size_t i = 0; i < 3; i++)
			{
				for(size_t j = 0; j < 3; j++)
				{
					os << setw(4) << m.m_a[i][j];
				}
				os << endl;
			}
			return os;
		}
		//+,返回值右值，操作数可以是左值或右值
		const M33 operator+(const M33& m) const 
		{
			int a[3][3];
			for(size_t i = 0; i < 3; i++)
			{
				for(size_t j = 0; j < 3; j++)
				{
					a[i][j] = m_a[i][j] + m.m_a[i][j];
				}
			}
			return M33(a);
		}
		//-,返回值右值，操作数可以是左值或右值
		const M33 operator-(const M33& m) const
		{
			int a[3][3];
			for(size_t i = 0; i < 3; i++)
			{
				for(size_t j = 0; j < 3; j++)
				{
					a[i][j] = m_a[i][j] - m.m_a[i][j];
				}
			}
			return M33(a);
		}
		//*,返回值右值，操作数可以是左值或右值
		const M33 operator*(const M33& m) const
		{
			int a[3][3] = {0};
			for(size_t i = 0; i < 3; i++)
			{
				for(size_t j = 0; j < 3; j++)
				{
					for(size_t k = 0; k < 3; k++)
					{
						a[i][j] += m_a[i][k] * m.m_a[k][j];
					}
				}
			}
			return M33(a);
		}

		//+= -= *= 返回左值，左操作数必须是左值，右操作数可以是左值，也可以是右值
		M33& operator+=(const M33& m)
		{
			*this = *this + m;
			return *this;
		}
		M33& operator-=(const M33& m)
		{
			*this = *this - m;
			return *this;
		}
		M33& operator*=(const M33& m)
		{
			*this = *this * m;
			return *this;
		}

		//取负-,返回右值，操作数可以是左值或右值
		const M33 operator-(void) const
		{
			return M33() - *this; 	//0 - *this
		}
		//前++，返回左值，操作数是左值

	

};
