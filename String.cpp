
#include <cstring>
#include <stdexcept>
#include "String.hpp"


using namespace std;
	
String::String(const char* chars)
	:length{strlen(chars) > 0 ? strlen(chars) : 0}, charPtr{new char[length + 1]}
{
	strcpy(charPtr, chars);	

}

/*
String::String(std::initializer_list<char> list):length{list.size()}, charPtr{new char[length + 1]}
{
	size_t index = 0;
	for (const auto& elem : list)
	{
		charPtr[index++] = elem;
	}
}
*/

String::~String(){
	delete[] charPtr;
}

/*
String::String(const long long val){
	size_t length = 0;
	unsigned int result = val / 10;
	
	while (result > 0){
		++length;
		result =/ 10;
	}
	
	++length;
	
	if (val < 0){
		++length;
	}
	
	this->length = length;
	this->charPtr = new char[this->length + 1];
	
	result = val / 10;
	unsigned int remainder = val % 10;
	
	for (size_t index = )
	
}

char& String::operator[] (size_t index)
{
	if (index < 0 || index >= length)
	{
		throw invalid_argument("Index out of bounds!");
	}
	
	return charPtr[index];
}

char String::operator[] (size_t index) const
{
	if (index < 0 || index >= length)
	{
		throw invalid_argument("Index out of bounds!");
	}
	
	return charPtr[index];
}

String::operator unsigned long() const
{
	if (0 == strtoul(charPtr, NULL, 10) || charPtr[0] == '-') {
		throw domain_error("String cannot be converted to unsgined long!");
	}
	
	if (strtoul(charPtr, NULL, 10) >= ULONG_MAX){
		throw overflow_error("To long number!");
	}
	
	return strtoul(charPtr, NULL, 10);
}

*/


ostream& operator<< (ostream& out, const String& str)
{
	out << str.charPtr;
	
	/*
	if (str.length > 0)
	{
		for (size_t index = 0; index < str.length; ++index){
		out << str.charPtr[index];
		}	
	}
	else
	{
		out << "empty";
	}
	*/
	
	return out;
}

