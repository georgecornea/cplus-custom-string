// String.hpp class interface
// Custom String class
// Name: George Cornea
// Date: May 2023

#pragma once

#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <cstring>
#include <vector>
#include <string>
#include <iterator>
#include "Iterator.hpp"

class String
{
	friend std::ostream& operator<< (std::ostream&, const String&); // stream extraction operator <<
	friend std::istream& operator>> (std::istream&, String&); // stream insertion operator
	
public:
	String(const char* = ""); // default c-tor. Create an empty String if no chars are ptovide
	String(std::initializer_list<char>); // initializer_list c-tor. Create a String from a list of chars
	~String(); // d-tor
	String(const std::string&); // conversion contructor. Create a String from a std::string
	
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
	
	char& operator[] (size_t); // operator [] - left value
	char operator[] (size_t) const; // operator [] - right value
	
	operator std::string () const; // conversion operator to std::string
	
	size_t size() const {return length;} // return string length
	
private:
	size_t length; // data member - string length
	char* stringPtr; // data member pointer
	
public:
	const static size_t MAX_LENGTH = 200; // string max length
	
	Iterator begin() { return &stringPtr[0];} // returns Iterator to the first char in String
	Iterator end() { return &stringPtr[length];} // returns Iterator to pointer past last char in String
	
}; // end String class
