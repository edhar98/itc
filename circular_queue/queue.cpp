#include <stdexcept>
#include "queue.hpp"

int CircularQueue::get_capacity() const noexcept
{
	return m_size;
}

void CircularQueue::resize() noexcept
{
	value_t* temp = new value_t[2 * m_size];
	int i = 0;
	int j = m_front;

	do {
		temp[i++] = m_variables[j];
		j = (j + 1) % m_size;
	} while (j != m_front);
	
	m_front = 0;
	m_rear = m_size - 1;
	m_size = 2 * m_size;
	delete [] m_variables;
	m_variables = temp;
}

void CircularQueue::reset() noexcept
{
	m_front = m_rear = -1;
}

bool CircularQueue::is_full() const noexcept
{
	return (m_rear + 1) % m_size == m_front;
}

bool CircularQueue::is_empty() const noexcept
{
	return m_front == -1;
}

CircularQueue::value_t CircularQueue::peek() const
{
	if(is_empty()) {
		throw "NoElements";
	}
	return m_variables[m_front];
}

CircularQueue::value_t CircularQueue::dequeue()
{
	if (is_empty()) {
		throw "NoElements";
	}
	CircularQueue::value_t temp = m_variables[m_front];
	if(m_front == m_rear) {
		m_front = m_rear = -1;
	} else {
		m_front = (m_front + 1) % m_size;
	}
	return temp;
}

void CircularQueue::enqueue(CircularQueue::value_t value) noexcept
{
	if(CircularQueue::is_full()) {
		CircularQueue::resize();
	} else if(CircularQueue::is_empty()) {
		m_front++;
	}
	m_rear = (m_rear + 1) % m_size;
	m_variables[m_rear] = value;
}

CircularQueue::CircularQueue(int initial_size) 
	: m_front(-1)
	, m_rear(-1)
	, m_variables(new value_t[initial_size])
	, m_size(initial_size)
{
}

CircularQueue::~CircularQueue()
{
	delete [] m_variables;
}
