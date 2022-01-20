#include <cmath>
#define PI 3.14159265

point::point()
{
	std::cout << "DefConstructor" << std::endl;
	m_x = 0;
	m_y = 0;
	m_dist = 0;
}

point::point(c_type n)
{
	std::cout << "Const 1" << std::endl;
	m_x = n;
	m_y = n;
	m_dist = n * sqrt(2);
}

point::point(c_type x, c_type y)
{
	std::cout << "Const 2" << std::endl;
	m_x = x;
	m_y = y;
	m_dist = sqrt(x*x + y*y);
}

point::~point()
{
}

const point& point::operator=(const point& p)
{
	m_x = p.get_x();
	m_y = p.get_y();
	m_dist = p.dist();
	return *this;
}

point::dist_type point::dist() const
{
	return m_dist;
}

point::c_type point::get_x() const
{
	return m_x;
}

point::c_type point::get_y() const
{
	return m_y;
}

void point::set_x(const point::c_type& x)
{
	m_x = x;
}

void point::set_y(const point::c_type& y)
{
	m_y = y;
}

point::dist_type point::dist_from(const point& p) const
{
	return sqrt(pow(p.get_x()-m_x,2)+pow(p.get_y()-m_y,2));
}

point::dist_type point::angle_x() const
{
	if ( m_x != 0 ){
		return atan(m_y/m_x) * 180/PI;
	} 
	return PI/2;
}

point::dist_type point::angle_y() const
{
	if ( m_y != 0 ){
		return atan(m_x/m_y) * 180/PI;
	}
	return PI/2;
}
