#include <iostream>
#include "string.hpp"
#include <cassert>

void test_empty_string()
{
	string empty_string;
	assert(empty_string.size() == 0 && "TEST test_empty_string: FAILED");
	assert(empty_string[0] == '\0' && "TEST test_empty_string: FAILED");
	std::cout << "TEST test_empty_string: PASSED" << std::endl;
}

void test_string_with_element_count()
{
	string string_with_element_count(5);
	assert(string_with_element_count.size() == 5 && "TEST test_string_with_element_count: FAILED");
	assert(string_with_element_count[0] == '\0' && "TEST test_string_with_element_count: FAILED");
	assert(string_with_element_count[1] == '\0' && "TEST test_string_with_element_count: FAILED");
	assert(string_with_element_count[2] == '\0' && "TEST test_string_with_element_count: FAILED");
	assert(string_with_element_count[3] == '\0' && "TEST test_string_with_element_count: FAILED");
	assert(string_with_element_count[4] == '\0' && "TEST test_string_with_element_count: FAILED");
	std::cout << "TEST test_string_with_element_count: PASSED" << std::endl;
}

void test_string_with_char_array()
{
	char str[] = "Hello world";
	string string_with_char_array(str);
	assert(string_with_char_array.size() == 11 && "TEST test_string_with_char_array: FAILED");
	assert(string_with_char_array[0] == 'H' && "TEST test_string_with_char_array: FAILED");
	assert(string_with_char_array[1] == 'e' && "TEST test_string_with_char_array: FAILED");
	assert(string_with_char_array[2] == 'l' && "TEST test_string_with_char_array: FAILED");
	assert(string_with_char_array[3] == 'l' && "TEST test_string_with_char_array: FAILED");
	assert(string_with_char_array[4] == 'o' && "TEST test_string_with_char_array: FAILED");
	assert(string_with_char_array[5] == ' ' && "TEST test_string_with_char_array: FAILED");
	std::cout << "TEST test_string_with_char_array: PASSED" << std::endl;
}

void test_string_initialisation()
{
	string str('a', 6);
	assert(str.size() == 6 && "TEST test_string_initialisation: FAILED");
	for (int i = 0; i < str.size(); i++) {
		assert(str[i] == 'a' && "TEST test_string_initialisation: FAILED");
	}
	std::cout << "TEST test_string_initialisation: PASSED" << std::endl;
}


void test_string_to_string_addition() 
{
	string a("Hello ");
	string b("world");
	string c = a + b;
	for (int i = 0; i < a.size(); ++i) {
		assert(c[i] == a[i] && "TEST test_string_to_string_addition: FAILED");
	}
	for (int j = 0; j < b.size(); ++j) {
		assert(c[a.size() + j] == b[j] && "TEST test_string_to_string_addition: FAILED");
	}
	std::cout << "TEST test_string_to_string_addition: PASSED" << std::endl;
}

void test_string_to_char_addition() 
{
	string a("Hello ");
	const char* b = "world";
	int b_size = -1;
	while('\0' != *(b + (++b_size))); 
	string c = a + b;
	for (int i = 0; i < a.size(); ++i) {
		assert(c[i] == a[i] && "TEST test_string_to_char_addition: FAILED");
	}
	for (int i = 0; i < b_size; ++i) {
		 assert(c[a.size() + i] == b[i] && "TEST test_string_to_char_addition: FAILED");
	}
	std::cout << "TEST test_string_to_char_addition: PASSED" << std::endl;
}

void test_string_assignment()
{
	string empty_string;
	string sample("Sample");
	assert(0 == empty_string.size() && "TEST test_string_assignment: FAILED");
	empty_string = sample;
	assert(empty_string.size() == sample.size() && "TEST test_string_assignment: FAILED");
	for (int i = 0; i < sample.size(); i++) {
		assert(empty_string[i] == sample[i] && "TEST test_string_assignment: FAILED");
	}
	std::cout << "TEST test_string_assignment: PASSED" << std::endl;
}

void test_string_to_string_add() 
{
	string a("Hello ");
	string b("world");
	string c = a + b;
	a += b;
	assert(a.size() == c.size() && "TEST test_string_to_string_add: FAILED");
	for (int i = 0; i < a.size(); ++i) {
		assert(a[i] == c[i] && "TEST test_string_to_string_add: FAILED");
	}
	std::cout << "TEST test_string_to_string_add: PASSED" << std::endl;
}

void test_string_to_char_add() 
{
	string a("Hello ");
	const char* b = "world";
	int b_size = -1;
	while('\0' != *(b + (++b_size))); 
	string c = a + b;
	a += b;
	assert(a.size() == c.size() && "TEST test_string_to_char_add: FAILED");
	for (int i = 0; i < a.size(); ++i) {
		assert(a[i] == c[i] && "TEST test_string_to_char_add: FAILED");
	}
	std::cout << "TEST test_string_to_char_add: PASSED" << std::endl;
}

void test_string_comparison() 
{
	string a("Hello ");
	string b("HelLo");
	string c("Hello");
	string d("Hello ");
	assert(a == d && "TEST test_string_comparison: FAILED");
	assert(!(a == b) && "TEST test_string_comparison: FAILED");
	assert(a != c && "TEST test_string_comparison: FAILED");
	assert(c > b && "TEST test_string_comparison: FAILED");
	assert(b < c && "TEST test_string_comparison: FAILED");
	assert(c >= b && "TEST test_string_comparison: FAILED");
	assert(b <= c && "TEST test_string_comparison: FAILED");
	assert(d <= a && "TEST test_string_comparison: FAILED");
	assert(d >= a && "TEST test_string_comparison: FAILED");
	std::cout << "TEST test_string_comparison: PASSED" << std::endl;
}

void test_string_swap()
{
	string a("Hello ");
	string b("world");
	a.swap(b);
	assert(a.size() == 5);
	assert(b.size() == 6);
}

int main () {
	test_empty_string();
	test_string_with_element_count();
	test_string_with_char_array();
	test_string_initialisation();
	test_string_to_string_addition();
	test_string_to_char_addition();
	test_string_assignment();
	test_string_to_string_add();
	test_string_to_char_add();
	test_string_comparison();
	test_string_swap();
	return 0;
}
