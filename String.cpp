// String.cpp class member functions implementation
// Name: George Cornea
// Date: May 2023

#include <cstring>
#include <stdexcept>
#include "String.hpp"

using namespace std;

// default c-tor. Create an empty String if no chars are ptovide
String::String(const char* chars)
	:length{strlen(chars) > 0 ? strlen(chars) : 0}, stringPtr{new char[length + 1]}
{
	strcpy(stringPtr, chars);	

}

// initializer_list c-tor. Create a String from a list of chars
String::String(std::initializer_list<char> list):length{list.size()}, stringPtr{new char[length + 1]}
{
	size_t index = 0;
	for (const auto& elem : list)
	{
		stringPtr[index++] = elem;
	}
}

// Destructor
String::~String(){
	delete[] stringPtr;
}

// conversion contructor. Create a String from a std::string
String::String(const std::string& stlString):length(stlString.size()), stringPtr{new char[length + 1]}
{
	for (size_t index = 0; index < stlString.size(); ++index)
	{
		stringPtr[index] = stlString[index];
	}
}

// copy constructor
String::String(const String& rightString):length(rightString.length)
{
	stringPtr = new char[length + 1];
	strcpy(stringPtr, rightString.stringPtr);
} 
 
// move constructor
String::String (String&& rightString) noexcept:length(rightString.length), stringPtr(rightString.stringPtr) 
{
	rightString.length = 0;
	rightString.stringPtr = NULL;
} 

 // assignment operator
const String& String::operator= (const String& rightString)
{
	if (*this != rightString)
	{
		if (this->length != rightString.length)
		{
			this->length = rightString.length;
			delete[] this->stringPtr;
			this->stringPtr = new char[this->length + 1];			
		}
		
		strcpy(this->stringPtr, rightString.stringPtr);
	}
	
	return *this;

} // end assigment operator =

// move operator
const String& String::operator= (String&& rightString) noexcept
{
	if (*this != rightString)
	{
		this->length = rightString.length;
		this->stringPtr = rightString.stringPtr;
		
		rightString.length = 0;
		rightString.stringPtr = NULL;
	}
	
	return *this;
    
 }  // end move operator
 
// concatenation operator
const String& String::operator+= (const String& rightString)
{
	char buffer1[length + 1]; 
	strcpy(buffer1, stringPtr);
	
	length = length + rightString.length;
	delete[] stringPtr;
	stringPtr = new char[length + 1];
	
	strcpy(stringPtr, buffer1);
	strcpy(stringPtr + strlen(buffer1), rightString.stringPtr);
	
	return *this;
	
} // end operator +=

// operator() Return a substring
String String::operator() (int index, int subStringLength) const
{
	if (index < 0 || index >= length)
	{
		throw invalid_argument("Index out of bounds!");
	}
	
	if (subStringLength < 0 || (subStringLength - index) > this->length)
	{
		throw length_error("Invalid substring length");
	}
	
	char* newString = new char[subStringLength + 1];
	strncpy(newString, this->stringPtr + index, subStringLength);
	
	String tempString {newString};
	
	delete[] newString;
	
	return tempString;
	
} // end operator()

// split() return a vector of char*
std::vector<String> String::split(const char* separators) const
{
	char buffer[length + 1];
	strcpy(buffer, stringPtr);
	
	vector<String> v;
	String temp;
	
	char* tokenPtr = strtok(buffer, separators);
	while (tokenPtr != NULL)
	{
		temp.length = strlen(tokenPtr);
		delete[] temp.stringPtr;
		temp.stringPtr = new char[temp.length + 1];
		strcpy(temp.stringPtr, tokenPtr);
		v.push_back(temp);
		tokenPtr = strtok(NULL, separators);
	}
	
	return v;
    
} // end split

// operator [] - left value
char& String::operator[] (size_t index)
{
	if (index < 0 || index >= length)
	{
		throw invalid_argument("Index out of bounds!");
	}
	
	return stringPtr[index];
}

// operator [] - right value
char String::operator[] (size_t index) const
{
	if (index < 0 || index >= length)
	{
		throw invalid_argument("Index out of bounds!");
	}
	
	return stringPtr[index];
}

 // conversion operator to std::string
String::operator std::string () const
{
	string newString;
	newString.resize(length);
	for (size_t index = 0; index < length; ++index)
	{
		newString[index] = stringPtr[index];
	}
	
	return newString;
}

// stream extraction operator <<
ostream& operator<< (ostream& out, const String& s)
{
	if (s.stringPtr != NULL)
	{
		out << s.stringPtr;	
	}
	return out;
}

// stream insertion operator
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

