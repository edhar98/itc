#include <cmath>
#include "line.hpp"

line::dist_type line::dist() const 
{
	return m_dist;
}

line::dist_type line::angle_x() const
{
	return atan(m_slope) * 180/M_PI;
}

line::dist_type line::angle_y() const
{
	return 90 - this->angle_x();
}

const point& line::get_one() const
{
	return m_one;
}


const point& line::get_two() const
{
	return m_two;
}

const line::c_type line::slope() const 
{
	return m_slope;
}

const line::c_type line::intercept() const 
{
	return m_intercept;
}


const point& line::ox() const 
{
	return m_ox;
}

const point& line::oy() const 
{
	return m_oy;
}
const line& line::operator=(const line& l)
{
	m_one = l.get_one();
	m_two = l.get_two();
	m_slope = l.slope();
	m_intercept = l.intercept();
	m_dist = l.dist();
	return *this;
}

const bool line::operator==(const line& l) const
{
	if ((m_one == l.get_one() && m_two == l.get_two()) || (m_one == l.get_two() && m_two == l.get_one())){
		return true;
	}
	return false;
}

line::line()
{
	m_slope = m_intercept = 0; // zero line
	m_dist = 0;
}

line::line(const point& n)
{
	m_two = n;
	m_intercept = 0;
	m_slope = n.get_y()/n.get_x(); 
	m_dist = n.dist();
}

line::line(const point& one, const point& two)
{
	m_one = one;
	m_two = two;
	m_slope = (two.get_y() - one.get_y()) / (two.get_x() - one.get_x());
	m_intercept = two.get_y() - m_slope * two.get_x();
	m_dist = one.dist_from(two);
	c_type k = -m_intercept/m_slope;
	point p(k,0);
	m_ox = p;
	point n(0,m_intercept);
	m_oy = n;
}
