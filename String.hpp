#pragma once

#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <cstring>
#include <vector>
#include <string>
#include <iterator>

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
	
	struct Iterator
	{
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = char;
		using pointer = char*;
		using reference = char&;
		
		Iterator(pointer ptr):cPtr(ptr){}
		reference operator* () { return *cPtr;}
		pointer operator-> () { return cPtr;}
		Iterator& operator++ () 
		{
			++cPtr;
			return *this; 
		}
		Iterator operator++(int)
		{
			Iterator temp = *this;
			++cPtr;
			return temp;
		}
		
		friend bool operator== (const Iterator& it1, const Iterator& it2)
		{
			return strcmp(it1.cPtr, it2.cPtr) == 0;
		}
		
		friend bool operator!= (const Iterator& it1, const Iterator& it2) { return !(it1 == it2);}
		
	private:
		pointer cPtr;
	};
	
	Iterator begin() { return &stringPtr[0];}
	Iterator end() { return &stringPtr[length];}
	
	
};
