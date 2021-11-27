#ifndef _vector_Math_H_
#define _vector_Math_H_

#include <iostream>
#include <vector>

namespace std
{
	class Vector3D
	{
	private:
		double _x, _y, _z;

	public:
		Vector3D() : _x(0), _y(0), _z(0) {}
		Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}
		double getX() const { return _x; }
		double getY() const { return _y; }
		double getZ() const { return _z; }
		vector<double> getVector() const { return {_x, _y, _z}; }

		// operations
		Vector3D operator+(const Vector3D &_ref);
		Vector3D operator-(const Vector3D &_ref);
		friend double dot(const Vector3D &_A, const Vector3D &_B);
		friend Vector3D cross(const Vector3D &_A, const Vector3D &_B);

		Vector3D &operator+=(const Vector3D &_ref);
		Vector3D &operator-=(const Vector3D &_ref);
	};

	ostream &operator<<(ostream &_os, const Vector3D &_v) { _os << "(" << _v.getX() << ", " << _v.getY() << ", " << _v.getZ() << ")"; }

	Vector3D Vector3D::operator+(const Vector3D &_ref)
	{
		int x0 = this->_x + _ref.getX();
		int y0 = this->_y + _ref.getY();
		int z0 = this->_z + _ref.getZ();
		return Vector3D(x0, y0, z0);
	}

	Vector3D Vector3D::operator-(const Vector3D &_ref)
	{
		double x0 = this->_x - _ref.getX();
		double y0 = this->_y - _ref.getY();
		double z0 = this->_z - _ref.getZ();
		return Vector3D(x0, y0, z0);
	}

	double dot(const Vector3D &_A, const Vector3D &_B)
	{
		return _A.getX() * _B.getX() + _A.getY() * _B.getY() + _A.getZ() * _B.getZ();
	}

	Vector3D cross(const Vector3D &_A, const Vector3D &_B)
	{
		double x0 = _A.getY() * _B.getZ() - _B.getY() * _A.getZ();
		double y0 = _B.getX() * _A.getZ() - _A.getX() * _B.getZ();
		double z0 = _A.getX() * _B.getY() - _B.getX() * _A.getY();
		return Vector3D(x0, y0, z0);
	}

	Vector3D &Vector3D::operator+=(const Vector3D &_ref)
	{
		*this = *this + _ref;
		return *this;
	}

	Vector3D &Vector3D::operator-=(const Vector3D &_ref)
	{
		*this = *this - _ref;
		return *this;
	}
}

#endif // _vector_Math_H_
