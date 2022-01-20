//#include "point.hpp"

class point
{
public:
	typedef double c_type;
	typedef double dist_type;
private:
	c_type m_x;
	c_type m_y;
	dist_type m_dist;

public:
	point();
	point(c_type n);
	point(c_type x, c_type y);
	~point();	
	const point& operator=(const point& p);
	dist_type dist() const;
	dist_type dist_from(const point& p) const;
	dist_type angle_x() const;
	dist_type angle_y() const;
	c_type get_x() const;
	c_type get_y() const;
	void set_x(const c_type& x);
	void set_y(const c_type& y);

};

