
#include <cstring>
#include <stdexcept>
#include "String.hpp"

using namespace std;


String::String(const char* chars)
	:length{strlen(chars) > 0 ? strlen(chars) : 0}, stringPtr{new char[length + 1]}
{
	strcpy(stringPtr, chars);	

}

String::String(std::initializer_list<char> list):length{list.size()}, stringPtr{new char[length + 1]}
{
	size_t index = 0;
	for (const auto& elem : list)
	{
		stringPtr[index++] = elem;
	}
}

String::~String(){
	delete[] stringPtr;
}

// copy constructor
String::String(const String& rightString):length(rightString.length)
{
	stringPtr = new char[length + 1];
	strcpy(stringPtr, rightString.stringPtr);
 } 

char& String::operator[] (size_t index)
{
	if (index < 0 || index >= length)
	{
		throw invalid_argument("Index out of bounds!");
	}
	
	return stringPtr[index];
}

char String::operator[] (size_t index) const
{
	if (index < 0 || index >= length)
	{
		throw invalid_argument("Index out of bounds!");
	}
	
	return stringPtr[index];
}

ostream& operator<< (ostream& out, const String& s)
{
	out << s.stringPtr;
	return out;
}

istream& operator>> (istream& in, String& s)
{
	
	char buffer[s.MAX_LENGTH];
	cin.get(buffer, s.MAX_LENGTH);
	
	s.length = strlen(buffer);
	delete[] s.stringPtr;
	s.stringPtr = new char[s.length + 1];
	strcpy(s.stringPtr, buffer);
	
	return in;
}

