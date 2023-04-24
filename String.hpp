
#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <cstring>

class String
{
	friend std::ostream& operator<< (std::ostream&, const String&);
	friend std::istream& operator>> (std::istream&, String&);
	
public:
	String(const char* = "");
	String(std::initializer_list<char>);
	~String();
	
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
	
	//const String& operator== (const String&); // assignment operator
	
	char& operator[] (size_t);
	char operator[] (size_t) const;
	
	size_t size() const {return length;}
	
private:
	size_t length;
	char* stringPtr;
	
public:
	const static size_t MAX_LENGTH = 200;
	
};
