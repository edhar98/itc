void test_empty_point()
{
	point empty_point;
	assert(empty_point.dist() == 0 && "TEST empty point: FAILED");
	std::cout << "TEST empty point: PASSED" << std::endl;
}

void test_single_argument_point()
{
	point single_argument_point(10);
	assert(single_argument_point.dist() != 0 && "TEST single argument point: FAILED");
	assert(single_argument_point.get_x() == single_argument_point.get_y() && "TEST single argument point: FAILED");
	std::cout << "TEST single argument point: PASSED" << std::endl;
}

void test_double_argument_point()
{
	point double_argument_point(15.0,20.0);
	assert(double_argument_point.dist() == 25 && "TEST double argument point: FAILED");
	assert(double_argument_point.angle_x() != 0 && "TEST double argument point: FAILED");
	assert(double_argument_point.angle_y() != 0 && "TEST double argument point: FAILED");
	assert(double_argument_point.angle_x() !=  double_argument_point.angle_y() && "TEST double argument point: FAILED");
	std::cout << "TEST double argument point: PASSED" << std::endl;
}

void test_point_assignment()
{
	point A;
	point B(5,10);
	assert(A.get_x() == 0 && "TEST point assignment: FAILED");
	assert(A.get_y() == 0 && "TEST point assignment: FAILED");
	assert(B.get_x() == 5 && "TEST point assignment: FAILED");
	assert(B.get_y() == 10 && "TEST point assignment: FAILED");
	A = B;
	assert(A.get_x() == 5 && "TEST point assignment: FAILED");
	assert(A.get_y() == 10 && "TEST point assignment: FAILED");
	std::cout << "TEST double argument point: PASSED" << std::endl;
}

void test_point_distance()
{
	point sample(3,4);
	assert(sample.dist() == 5 && "TEST point distance: FAILED");
	std::cout << "TEST point distance: PASSED" << std::endl;
}

void test_point_distance_from_another_point()
{
	point first(1,1);
	point second(1,11);
	assert(first.dist_from(second) == 10 && "TEST point distance from another point: FAILED");
	assert(second.dist_from(first) == 10 && "TEST point distance from another point: FAILED");
	std::cout << "TEST point distance from another point: PASSED" << std::endl;
}

void test_point_angle_with_x()
{
	point sample(sqrt(3),1);
	assert(sample.angle_x() == 30 && "TEST point angle with X: FAILED");
	std::cout << "TEST point angle with X: PASSED" << std::endl;
}

void test_point_angle_with_y()
{
	point sample(sqrt(3),1);
	assert(sample.angle_y() == 60 && "TEST point angle with Y: FAILED");
	std::cout << "TEST point angle with Y: PASSED" << std::endl;
}
