#pragma once

#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <cstring>
#include <vector>
#include <string>

class String
{
	friend std::ostream& operator<< (std::ostream&, const String&);
	friend std::istream& operator>> (std::istream&, String&);
	
public:
	String(const char* = "");
	String(std::initializer_list<char>);
	~String();
	
	String(const std::string&); // conversion contructor 
	
	String(const String&); // copy constructor
	String (String&&) noexcept; // move constructor
	
	// operator ==
	bool operator== (const String& rightString) const 
	{
		return strcmp(this->stringPtr, rightString.stringPtr) == 0;
	}
	
	// operator !=
	bool operator!= (const String& rightString) const 
	{
		return !(*this == rightString);
	}
	
	const String& operator= (const String&); // assignment operator
	const String& operator= (String&&) noexcept; // move operator
	
	// operator <
	bool operator< (const String& rightString) const 
	{
		return strcmp(stringPtr, rightString.stringPtr) < 0;
	}
	
	// operator >
	bool operator> (const String& rightString) const 
	{
		return rightString < *this;
	}
	
	// operator >=
	bool operator>= (const String& rightString) const 
	{
		return !(*this < rightString);
	}
	
	// operator <=
	bool operator<= (const String& rightString) const 
	{
		return !(rightString < *this);
	}
	
	// operator ! (is string empty)
	bool operator! () const 
	{
		return this->length == 0;
	}
	
	// concatenation operator
	const String& operator+= (const String&);
	
	// operator() Return a substring
	String operator() (int, int = 0) const;
	
	// split() return a vector of char*
	std::vector<String> split(const char*) const;
	
	char& operator[] (size_t);
	char operator[] (size_t) const;
	
	operator std::string () const; // conversion operator to std::string
	
	size_t size() const {return length;}
	
private:
	size_t length;
	char* stringPtr;
	
public:
	const static size_t MAX_LENGTH = 200;
	
};
