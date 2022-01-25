#include <iostream>
#include "point.hpp"
#include "line.hpp"
#include <cmath>
#include <cassert>
#include "test_point.h"
#include "test_line.h"


int main(){
	test_empty_point();
	test_single_argument_point();
	test_double_argument_point();
	test_point_assignment();
	test_point_distance();
	test_point_distance_from_another_point();
	test_point_angle_with_x();
	test_point_angle_with_y();
	
	test_zero_line();
	test_single_argument_line();
	test_double_argument_line();
	test_line_assignment();
	test_line_params();
	return 0;
}
