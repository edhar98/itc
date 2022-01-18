#include <iostream>
#include <cassert>

class array
{
public:
    typedef int element_type;
    typedef unsigned int size_type;

public:
    size_type size();
    bool empty();
    element_type access(size_type index);
    void insert(size_type index, element_type value);
    void modify(size_type index, element_type value);
    void remove(size_type index);

private:
	element_type* m_start;
	size_type m_size;

public:
    array();
    array(size_type n, element_type default_value);
    ~array();
};

array::size_type array::size()
{
	return m_size;
}

array::array()
{
    std::cout << "Default constructor" << std::endl;
	m_size = 0;
	m_start = nullptr;
}

array::array(size_type n, element_type default_value)
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


void array::modify(size_type index, element_type value)
{
	assert(index >= 0);
	assert(index < m_size);
	m_start[index] = value;	
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
	for (size_type i = index - 1; i < m_size; ++i) {
		tmp[i] = m_start[i + 1];
	}
	if (m_start != nullptr) {
		delete [] m_start;
	}
	m_start = tmp;
}

void array::insert(size_type index, element_type value)
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

bool array::empty()
{
    assert(m_size >= 0);
	return m_size == 0;
}

array::element_type array::access(array::size_type index)
{
	assert(index >= 0);
	assert(index < m_size);
    assert(m_start != nullptr);
	return m_start[index];
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

int main()
{
	test_create_empty();
	test_create();
	test_insert();
	test_modify();
	test_remove();
	return 0;
}
