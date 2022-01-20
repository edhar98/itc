#include <iostream>
#include <cassert>

class array
{
public:
	typedef int element_type;
	typedef unsigned int size_type;

public:
	size_type size() const;
	bool empty() const;
	element_type access(size_type index) const;
	void modify(size_type index, const element_type& value);
	void remove(size_type index);
	void insert(size_type index, const element_type& value);

private:
	element_type* m_start;
	size_type m_size;

public:
	array();
	array(size_type n, const element_type& default_value);
	array(const array& a);
	const array& operator=(const array& c);
	~array();
};

array::size_type array::size() const
{
	return m_size;
}

array::array()
{
	std::cout << "Default constructor" << std::endl;
	m_size = 0;
	m_start = nullptr;
}

array::array(const array& a)
{
	m_size = a.size();
	if (m_size == 0) {
		m_start = nullptr;
	} else {
		m_start = new element_type[m_size];
		for (size_type i = 0; i < m_size; i++){
			m_start[i] = a.access(i);
		}

	}
}
const array& array::operator=(const array& c)
{
	assert(c.size() >= 0);
	if (this == &c) {
	    return *this;
	}
	std::cout << "Assignment Operator" << std::endl;
	if (m_start != nullptr) {
	    delete [] m_start;
	    m_start = nullptr;
	}
	assert(m_start == nullptr);
	m_size = c.size();
	if (m_size > 0) {
	    m_start = new element_type[m_size];
	    for (size_type i = 0; i < m_size; ++i) {
	        m_start[i] = c.access(i);
	    }
	}
	return *this;
}
array::array(size_type n, const element_type& default_value)
{
	std::cout << "Constructor" << std::endl;
	m_size = 0;
	m_size = n;
	m_start = new element_type[n];
	for (size_type i = 0; i < m_size; ++i) {
		m_start[i] = default_value;
	}
}

array::~array()
{
	std::cout << "Destructor" << std::endl;
	if (m_start != nullptr) {
		delete [] m_start;
	}
}

void array::remove(size_type index)
{
	assert(index >= 0);
	assert(index < m_size);
	m_size = m_size - 1;
	element_type* tmp = new element_type[m_size];
	for (size_type i = 0; i < index; ++i) {
		tmp[i] = m_start[i];
	}
	for (size_type i = index; i < m_size; ++i) {
		tmp[i] = m_start[i + 1];
	}
	if (m_start != nullptr) {
		delete [] m_start;
	}
	m_start = tmp;
}

void array::insert(size_type index, const element_type& value)
{
	assert(index >= 0);
	assert(index <= m_size);
	m_size = m_size + 1;
	element_type* tmp = new element_type[m_size];
	for (size_type i = 0; i < index; ++i) {
		tmp[i] = m_start[i];
	}
	tmp[index] = value;
	for (size_type i = index + 1; i < m_size; ++i) {
		tmp[i] = m_start[i - 1];
	}
	if (m_start != nullptr) {
		delete [] m_start;
	}
	m_start = tmp;
}

bool array::empty() const
{
	assert(m_size >= 0);
	return m_size == 0;
}

array::element_type array::access(array::size_type index) const
{
	assert(index >= 0);
	assert(index < m_size);
	assert(m_start != nullptr);
	return m_start[index];
}

void array::modify(size_type index, const element_type& value)
{
	assert(index >= 0);
	assert(index < m_size);
	m_start[index] = value;
}

void test_create_empty()
{
	array sample;
	assert(sample.size() == 0 && "TEST test_create_empty: FAILED");
	assert(sample.empty() && "TEST test_create_empty: FAILED");
	std::cout << "TEST test_create_empty: PASSED" << std::endl;
}

void test_create()
{
	array sample(5,0);
	assert(sample.size() != 0 && "TEST test_create: FAILED");
	assert(!sample.empty() && "TEST test_create: FAILED");
	for (array::size_type i = 0; i < sample.size(); ++i)  {
       		assert( 0 == sample.access(i) && "TEST test_create: FAILED");
	}
	std::cout << "TEST test_create: PASSED" << std::endl;
}

void test_insert()
{
	array sample(5,0);
	array::size_type old_size = sample.size();
	sample.insert(2,10);
	array::size_type new_size = sample.size();
	assert( new_size == old_size + 1 && "TEST test_insert: FAILED");
	assert( sample.access(2) == 10 && "TEST test_insert: FAILED");
	std::cout << "TEST test_insert: PASSED" << std::endl;
}

void test_modify()
{
	array sample(4,0);
	array::element_type old_value = sample.access(2);
	sample.modify(2,10);
	array::element_type new_value = sample.access(2);
	assert(new_value != old_value && "TEST test_modify: FAILED");
	assert(10 == new_value && "TEST test_modify: FAILED");
	std::cout << "TEST test_modify: PASSED" << std::endl;
}

void test_remove()
{
	array sample(10,1);
	for (array::size_type i = 0; i < sample.size(); ++i) sample.modify(i,2*i);
	array::element_type preremoved_value = sample.access(4);
	array::size_type preremoved_size = sample.size();
	sample.remove(4);
	array::size_type after_remove_size = sample.size();
	array::element_type after_remove_value = sample.access(4);
	assert( after_remove_size + 1 == preremoved_size && "TEST test_remove: FAILED" );
	assert( after_remove_value != preremoved_value && "TEST test_remove: FAILED" );
	std::cout << "TEST test_remove: PASSED" << std::endl;
}

void test_copy()
{
	array sample(5,0);
	for (array::size_type i = 0; i < sample.size(); i++){
		sample.modify(i,2*i);
	}
	array copied(sample);
	assert(copied.size() == sample.size() && "TEST test_copy: FAILED");
	for (array::size_type i = 0; i < sample.size(); i++){
		assert(copied.access(i) == sample.access(i) && "TEST test_copy: FAILED");
	}
	std::cout << "TEST test_copy: PASSED" << std::endl;
}

void test_assignment()
{
	array sample(2,0);
	for (array::size_type i = 0; i < sample.size(); i++){
		sample.modify(i,2*i);
	}
	array another();
	assert(another.size() == 0 && "TEST test_assignment: FAILED");
	another = sample;
	assert(another.size() == sample.size() && "TEST test_assignment: FAILED");
	for (array::size_type i = 0; i < sample.size(); i++){
		assert(another.access(i) == sample.access(i) && "TEST test_assignment: FAILED");
	}
	std::cout << "TEST test_assignment: PASSED" << std::endl;
}
	
void test_assignment_on_empty()
{
	array sample();
	assert(sample.size() == 0 && "TEST test_assignment_on_empty: FAILED");
	array another(4,0);
	assert(another.size() == 4 && "TEST test_assignment_on_empty: FAILED");
	another = sample;
	assert(another.size() == sample.size() && "TEST test_assignment_on_empty: FAILED");
	std::cout << "TEST test_assignment_on_empty: PASSED" << std::endl;
}

void test_multiple_assignment()
{
	array a(1,1);
	for (array::size_type i = 0; i < a.size(); i++){
		assert(a.access(i) == 1 && "TEST test_multiple_assignment: FAILED");
	}
	array b(2,2);
	for (array::size_type i = 0; i < b.size(); i++){
		assert(b.access(i) == 2 && "TEST test_multiple_assignment: FAILED");
	}
	array c(3,3);
	for (array::size_type i = 0; i < c.size(); i++){
		assert(c.access(i) == 3 && "TEST test_multiple_assignment: FAILED");
	}
	a = b = c;
	for (array::size_type i = 0; i < c.size(); i++){
		assert(a.access(i) == 3 && "TEST test_multiple_assignment: FAILED");
		assert(b.access(i) == 3 && "TEST test_multiple_assignment: FAILED");
		assert(c.access(i) == 3 && "TEST test_multiple_assignment: FAILED");
	}
	std::cout << "TEST test_multiple_assignment: PASSED" << std::endl;
}	

int main()
{
	test_create_empty();
	test_create();
	test_insert();
	test_modify();
	test_remove();
	test_copy();
	test_assignment();
	test_assignment_on_empty();
	test_multiple_assignment();
	return 0;
}
