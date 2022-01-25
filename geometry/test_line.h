void test_zero_line()
{
	line zero_line;
	assert(zero_line.intercept() == 0 && "TEST zero line: FAILED");
	assert(zero_line.slope() == 0 && "TEST zero line: FAILED");
	assert(zero_line.dist() == 0 && "TEST zero line: FAILED");
	assert((zero_line.get_one() == zero_line.get_two()) && "TEST zero line: FAILED");
	std::cout << "TEST zero line: PASSED" << std::endl;
}

void test_single_argument_line()
{
	point blank;
	point sample_point(5);
	line sample_line(sample_point);
	assert(sample_line.get_one() == blank && "TEST single argument line: FAILED");
	assert(sample_line.get_two() == sample_point && "TEST single argument line: FAILED");
	assert(sample_line.intercept() == 0 && "TEST single argument line: FAILED");
	assert(sample_line.slope() == sample_point.get_y()/sample_point.get_x() && "TEST single argument line: FAILED");
	assert(sample_line.dist() == sample_point.dist() && "TEST single argument line: FAILED");
	std::cout << "TEST single argument line: PASSED" << std::endl;
}

void test_double_argument_line()
{
	point one(2,3), two(5,6);
	line sample(one,two);
	assert(sample.get_one() == one && "TEST double argument line: FAILED");
	assert(sample.get_two() == two && "TEST double argument line: FAILED");
	assert(sample.slope() == 1 && "TEST double argument line: FAILED");
	assert(sample.intercept() == 1 && "TEST double argument line: FAILED");
	std::cout << "TEST double argument line: PASSED" << std::endl;
}

void test_line_assignment()
{
	point a_one(1), a_two(2,3), b_one, b_two(-3,-2);
	line a(a_one,a_two), b(b_one,b_two);
	assert(a.get_one() == a_one && "TEST line assignment: FAILED");
	assert(a.get_two() == a_two && "TEST line assignment: FAILED");
	assert(b.get_one() == b_one && "TEST line assignment: FAILED");
	assert(b.get_two() == b_two && "TEST line assignment: FAILED");
	line c = a;
	assert(c.get_one() == a_one && "TEST line assignment: FAILED");
	assert(c.get_two() == a_two && "TEST line assignment: FAILED");
	
	assert(a == c && "TEST line assignment: FAILED");
	
	a = b;
	assert(a.get_one() == b_one && "TEST line assignment: FAILED");
	assert(a.get_two() == b_two && "TEST line assignment: FAILED");
	std::cout << "TEST line assignment: PASSED" << std::endl;
}

void test_line_params()
{
	point a_one(1,3), a_two(6,15);
	point intersect_with_x(-0.25,0), intersect_with_y(0,0.6);
	line sample(a_one, a_two);
	assert(sample.get_one() == a_one && "TEST line parameters: FAILED");
	assert(sample.get_two() == a_two && "TEST line parameters: FAILED");
	assert(sample.dist() == 13 && "TEST line parameters: FAILED");
	assert(sample.ox() == intersect_with_x && "TEST line parameters: FAILED");
	assert(sample.oy() == intersect_with_y && "TEST line parameters: FAILED");
	std::cout << "TEST line parameters: PASSED" << std::endl;
}

