#include "string.hpp"

#include <cassert>

bool string::operator==(const string& other) const
{
	if( m_size == other.size() ) {
		int i = 0;
		while(i < m_size) {
			if(m_string[i] == other[i]) {
				i++;
			} else {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool string::operator!=(const string& other) const
{
	return !(*this==other);
}

bool string::operator>(const string& other) const
{
	if( m_size < other.size() ) {
		return false;
	} else if (m_size > other.size()) {
		return true;
	}	
	int i = 0;
	while(i < m_size) {
		if(m_string[i] == other[i]) {
			i++;
		} else if (m_string[i] > other[i]) {
			return true;
		}
	}
	return false;
}

bool string::operator>=(const string& other) const
{
	if( m_size < other.size() ) {
		return false;
	} else if (m_size > other.size()) {
		return true;
	}	
	int i = 0;
	while(i < m_size) {
		if(m_string[i] == other[i]) {
			i++;
		} else if (m_string[i] > other[i]) {
			return true;
		}
	}
	return true;
}

bool string::operator<(const string& other) const
{
	return other > (*this);
}

bool string::operator<=(const string& other) const
{
	return other >= (*this);
}
//bool string::is_substring(string& substring)
//{
//	int i_str = 0;
//	int j_substr = 0;
//	while(i_str < m_size) {
//		if ( substring[j_substr] == m_string[i_str] ) {
//			if( ++j_substr == substring.size() ) {
//				return true;
//			} else {
//				i_str++;
//			}
//		} else {
//			j_substr = 0;
//			i_str++;
//		}
//	}
//	return false;
//}
//
//int string::substring(string& substring)
//{
//	int i_str = 0;
//	int j_substr = 0;
//	while(i_str < m_size) {
//		if ( substring[j_substr] == m_string[i_str] ) {
//			if( ++j_substr == substring.size() ) {
//				return i_str;
//			} else {
//				i_str++;
//			}
//		} else {
//			j_substr = 0;
//			i_str++;
//		}
//	}
//	return -1;
//}
//
//
const int& string::size() const 
{
	return m_size;
}
//
//char* string::get_string()
//{
//	return m_string;
//}
//
////char string::get_element(int position)
////{
////	char c = this[position];
////	return c;
////}
//
void string::swap(string& other_string)
{
	string tmp = other_string;
	other_string.m_size = this->m_size;
	other_string.m_string = this->m_string;
	m_size = tmp.size();
	delete [] m_string;
	char* m_string = new char [tmp.size() + 1];
	int i = 0;
	while (i < m_size) {
		m_string[i] = tmp[i];
		i++;
	}
	m_string[i] = '\0';	
}

const string* string::operator=(const string& origin)
{
	delete [] this->m_string;
	this->m_string = new char [origin.size() + 1];
	for (int i = 0; i < origin.size(); i++) {
		m_string[i] = origin[i];
	}
	m_string[origin.size()] = '\0';
	m_size = origin.size();
	return this;
}

void string::operator+=(const string& summand)
{
	char* new_string = new char [m_size + summand.size() + 1];
	int i = 0;
	while (i < m_size) {
		new_string[i] = m_string[i];
		i++;
	}
	while (i < m_size + summand.size()) {
		new_string[i] = summand[i - m_size];
		i++;
	}
	new_string[i] = '\0';
	m_size = i;
	delete [] m_string;
	m_string = new_string;
}

void string::operator+=(const char* summand)
{
	int summand_size = -1;
	while ('\0' != *(summand + (++summand_size)));
	char* new_string = new char [m_size + summand_size + 1];
	int i = 0;
	while (i < m_size) {
		new_string[i] = m_string[i];
		i++;
	}
	while (i < m_size + summand_size) {
		new_string[i] = summand[i - m_size];
		i++;
	}
	new_string[i] = '\0';
	m_size = i;
	delete [] m_string;
	m_string = new_string;
}


string string::operator+(const char* summand) const
{
	int summand_size = -1;
	while ('\0' != *(summand + (++summand_size)));
	char* new_string = new char[m_size + summand_size + 1];
	int i = 0;
	while (i < m_size) {
		new_string[i] = m_string[i];
		i++;
	}
	while (i < m_size + summand_size) {
		new_string[i] = summand[i - m_size];
		i++;
	}
	new_string[i] = '\0';
	string result(new_string);
	delete [] new_string;
	return result;
}
	

string string::operator+(const string& summand) const
{
	char* new_string = new char[m_size + summand.size() + 1];
	int i = 0;
	while (i < m_size) {
		new_string[i] = m_string[i];
		i++;
	}
	while (i < m_size + summand.size()) {
		new_string[i] = summand[i - m_size];
		i++;
	}
	new_string[i] = '\0'; 
	string result(new_string);
	delete [] new_string;
	return result;
}

char string::operator[](const int pos) const
{
	if ( pos < m_size && pos > -1) {
		return *(m_string + pos);
	} else if (pos < 0 && -pos < m_size + 1 ) { 
		return *(m_string + m_size + pos);
	}
	return '\0'; //TODO
}

string::string()
	: m_size(0)
	, m_string(new char[1]{'\0'})
{

}
string::string(int element_count)
	: m_size(element_count)
	, m_string(new char [element_count + 1])
{
	for(int i = 0; i < element_count+1; ++i){
		m_string[i] = '\0';
	}
}

string::string(const char* str)
{
	int i = 0;
	while ('\0' != *(str + i)) {
	       i++;
	}
	m_size = i;	
	m_string = new char [m_size + 1];
	while ( 0 != i ) {
		m_string[m_size - i] = *(str + m_size - i);
		i--;
	}
	m_string[m_size] = '\0';
}

string::string(char symbol, int count)
	: m_size(count)
	, m_string(new char[count+1]{'\0'})
{
	int i = 0;
	while ( i < m_size) {
		m_string[i++] = symbol;
	}
	m_string[count] = '\0';
}

string::~string()
{
	delete [] m_string;
}
