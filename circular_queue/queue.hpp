#ifndef QUEUE
#define QUEUE

class CircularQueue 
{
public:
	typedef int value_t;
private:
	int m_front; 
	int m_rear;
	int m_size;
	value_t* m_variables;
public:
	CircularQueue(int initial_size);
	~CircularQueue();
	void enqueue(value_t value) noexcept;
	value_t dequeue();
	void reset() noexcept;
	value_t peek() const;
	bool is_empty() const noexcept;
	bool is_full() const noexcept;
	int get_capacity() const noexcept;
private:
	void resize() noexcept;
};

#endif

