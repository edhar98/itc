#ifndef STRING
#define STRING
class string
{
private:
	char* m_string;
	int m_size;

public:
	string();
	string(int element_count);
	string(const char* str);
	string(char symbol, int count);
	~string();
	char operator[](const int pos) const;
	string operator+(const string& summand) const;
	string operator+(const char* summand) const;
	void operator+=(const string& summand);
	void operator+=(const char* summand);
	const string* operator=(const string& origin);
	bool operator==(const string& other) const;
	bool operator!=(const string& other) const;
	bool operator>(const string& other) const;
	bool operator<(const string& other) const;
	bool operator>=(const string& other) const;
	bool operator<=(const string& other) const;
	void swap(string& other_string);
//	char* get_string();
//	//char get_element(int position);
	const int& size() const;
//	int substring(string& substring);
//	bool is_substring(string& substring);
};
#endif
