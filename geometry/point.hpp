#ifndef POINT_HPP
#define POINT_HPP
class point
{
public:
	typedef float c_type;
	typedef float dist_type;
private:
	c_type m_x;
	c_type m_y;
	dist_type m_dist;

public:
	point();
	point(const c_type& n);
	point(const c_type& x, const c_type& y);
	const point& operator=(const point& p);
	const bool operator==(const point& p) const;
	dist_type dist() const;
	dist_type dist_from(const point& p) const;
	dist_type angle_x() const;
	dist_type angle_y() const;
	c_type get_x() const;
	c_type get_y() const;
	void set_x(const c_type& x);
	void set_y(const c_type& y);

};
#endif
