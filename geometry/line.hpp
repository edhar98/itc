#ifndef LINE_HPP
#define LINE_HPP

#include "point.hpp"

class line
{
public:
	typedef float c_type;
	typedef float dist_type;
private:
	point m_one, m_two, m_ox, m_oy;
	c_type m_slope,m_intercept;  // y = slope * x + intercept;
	dist_type m_dist; //= m_one.dist_from(m_two); 

public:
	line();
	line(const point& n);
	line(const point& one, const point& two);
	const line& operator=(const line& l);
	const bool operator==(const line& l) const;
	dist_type dist() const;
	dist_type angle_x() const;
	dist_type angle_y() const;
	const point& get_one() const;
	const point& get_two() const;
	const c_type slope() const;
	const c_type intercept() const;
	const point& ox() const;
	const point& oy() const;
};
#endif
