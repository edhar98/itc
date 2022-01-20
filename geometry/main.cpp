#include <iostream>
#include "point.h"
#include "point.hpp"
#include "line.cpp"

int main(){
	point A;
	point B(1);
	point C(3,2);
	std::cout << A.get_x() << ", " << A.get_y() << std::endl;
	A.set_x(10);
	A.set_y(15);
	std::cout << A.get_x() << ", " << A.get_y() << std::endl;
	std::cout << B.get_x() << ", " << B.get_y() << std::endl;
	std::cout << C.get_x() << ", " << C.get_y() << std::endl;
	std::cout << B.dist() << ", " << B.dist_from(C)<< ", "<< B.angle_x() << ", " << B.angle_y() << std::endl;
	std::cout << C.dist() << ", " << C.angle_x() << ", " <<C.angle_y() << std::endl;
	return 0;
}
