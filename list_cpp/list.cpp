
#include "list.hpp"

#include <cassert>

class list::node
{
public:
	value_type m_value;
	node* m_next = nullptr;
public:
	node(value_type v, node* n)
		: m_value(v)
		, m_next(n)
	{
	}

	~node()
	{
	}
	
};

std::ostream& operator<<(std::ostream& out, const list& l)
{
	list::node* current = l.m_head;
	while (current != nullptr) {
		out << current->m_value << " ";
		current = current->m_next;
	}
	return out;
}

list::size_type list::size() const
{
	node* current = m_head;
	size_type count = 0;
	while (current != nullptr) {
		current = current->m_next;
		++count;
	}
	return count;
}

bool list::empty() const
{
	return (m_head == nullptr);
}

void list::push_front(const value_type& value) // O(1)
{
	node* new_node = new node(value, m_head);
	m_head = new_node;
}

void list::push_back(const value_type& value) // O(n)
{
	node* new_node = new node(value, nullptr);
	if (m_head == nullptr) {
		m_head = new_node;
	} else {
		assert(size() >= 1);
		node* last = access_helper(size() - 1);
		assert(last != nullptr);
		assert(last->m_next == nullptr);
		last->m_next = new_node;
	}
}

void list::insert(const size_type& index, const value_type& value)
{
	assert(index >= 0);
	assert(index <= size());
	if (index == 0) {
		push_front(value);
	} else if (index == size()) {
		push_back(value);
	} else {
		assert(index >= 1);
		node* new_node = new node(value, nullptr);
		node* current = access_helper(index - 1);
		assert(current != nullptr);
		new_node->m_next = current->m_next;
		current->m_next = new_node;
	}
}

void list::pop_front()
{
	assert(m_head != nullptr);
	node* n = m_head; 
	m_head = m_head->m_next; 
	delete n;
}

void list::pop_back()
{
	assert(m_head != nullptr);
	if (m_head->m_next == nullptr) {
		pop_front();
		assert(m_head == nullptr);
	} else {
		assert(size() >= 2);
		node* previous = access_helper(size() - 2);
		assert(previous != nullptr);
		node* last = previous->m_next;
		assert(last != nullptr);
		assert(last->m_next == nullptr);
		previous->m_next = nullptr;
		delete last;
	}
}

list::node* list::access_helper(const size_type& index) const
{
	assert(index >= 0);
	assert(index < size());
	node* current = m_head;
	for (size_type i = 0; i < index; ++i) {
		assert(current != nullptr);
		current = current->m_next;
	}
	assert(current != nullptr);
	return current;
}

list::value_type list::access(const size_type& index) const
{
	node* n = access_helper(index);
	assert(n != nullptr);
	return n->m_value;
}

list::list()
	: m_head(nullptr)
{
}

list::list(size_type n, const value_type& default_value)
	: m_head(nullptr)
{
	node* current = nullptr;
	for (size_type i = 0; i < n; ++i) {
		node* new_node = new node(default_value, nullptr);
		if (current != nullptr) {
			current->m_next = new_node;
		} else {
			assert(m_head == nullptr);
			m_head = new_node;
		}
		current = new_node;
	}
}

list::list(const list& b)
	: m_head(nullptr)
{
	node* current = b.m_head;
	list::size_type n = b.size();
	for(size_type i = 0; i < n; ++i) {
		node* new_node = new node(current->m_value, current->m_next);
		if( m_head == nullptr){
		       m_head = new_node;
		}
		current = current->m_next;
	}
}

const list& list::operator=(const list& c)
{
//m_head = c.m_head;
	return *this;
}

list::~list()
{
	while (! empty()) {
		pop_front();
	}
}

/*
list::~list()
{
	while(m_head != nullptr){
		node* current = m_head;
		m_head = m_head->m_next;
		delete current;
	}
	delete m_head;
}*/
