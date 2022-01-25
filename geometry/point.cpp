#include "point.hpp"
#include <cmath>
#define delta 10000
#define PI 3.141592

const point& point::operator=(const point& p)
{
	m_x = p.get_x();
	m_y = p.get_y();
	m_dist = p.dist();
	return *this;
}

const bool point::operator==(const point& p) const
{
	if (m_x == p.get_x() &&	m_y == p.get_y()){
		return true;
	}
	return false;
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
	int d = (int) (sqrt(pow(p.get_x()-m_x,2)+pow(p.get_y()-m_y,2))*delta + .5);
	return (dist_type) d/delta;	
}

point::dist_type point::angle_x() const
{
	if ( m_x != 0 ){
		int res = (int) (atan(m_y/m_x) * 180/PI) * delta + .5;
		return (dist_type) res/delta;
	} 
	return PI/2;
}

point::dist_type point::angle_y() const
{
	if ( m_y != 0 ){
		int res = (int) (atan(m_x/m_y) * 180/PI) * delta + .5;
		return (dist_type) res/delta;
	}
	return PI/2;
}
point::point()
{
	m_x = 0;
	m_y = 0;
	m_dist = 0;
}

point::point(const c_type& n)
{
	m_x = n;
	m_y = n;
	int dist = (int) (n * sqrt(2) * delta + .5);
	m_dist = (dist_type) dist/delta;
}

point::point(const c_type& x, const c_type& y)
{
	m_x = x;
	m_y = y;
	int dist = (int) (sqrt(x*x + y*y) * delta + .5);
	m_dist = (dist_type) dist/delta;
}

