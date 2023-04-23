
#include <cstddef>
#include <iostream>
#include <initializer_list>

class String
{
	friend std::ostream& operator<< (std::ostream&, const String&);
	friend std::istream& operator>> (std::istream&, String&);
	
public:
	String(const char* = "");
	String(std::initializer_list<char>);
	
	//String(const long long);
	~String();
	
	
	//char& operator[] (size_t);
	//char operator[] (size_t) const;
	
	//operator unsigned long() const;
	
	size_t size() const {return length;}
	
private:
	size_t length;
	char* stringPtr;
	
public:
	const static size_t MAX_LENGTH = 200;
	
};
