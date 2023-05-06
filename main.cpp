#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>

#include "String.hpp"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
		
	// testing default c-tor and operators >>/<<
	cout << "Testing default c-tor: String s; and operators >> / <<";
	String s;
	cout << "\nString s is: " << s << ". Length: " << s.size();
	cout << "\nEnter a new string for s: ";
	cin >> s;
	cout << "String s is: " << s << ". Length: " << s.size() << endl;

	// testing c-tor with argumet
	cout << "\nTesting c-tor with argument: String s1{\"Hi There!\"}";
	String s1{"Hi There!"};	
	cout << "\nString s1 is: " << s1 << ". Length: " << s1.size() << endl;
	
	// testing initializer list c-tor
	cout << "\nTesting c-tor with initializer list String s2{'a','b','c'}";
	String s2{'a', 'b', 'c'};
	cout << "\nString s2 is: " << s2 << ". Length: " << s2.size() << endl;
	
	// testing operator[] as left and right values
	try
	{
		cout << "\nTesting operator[] with left/right values. s1[1] = 'I'"; 
		cout << "\nAnd invalid value for operator[] s1[100]";
		s1[1] = 'I';
		cout << "\nString s1 is: " << s1 << ". Length: " << s1.size();
		cout << "\nFirst char of s1 is: " << s1[0];
		cout << s1[100];
		
	}
	catch (const invalid_argument& exc)
	{
		cerr << "\nERROR: " << exc.what() << endl;
	}

	// Testing copy c-tor
	cout << "\nTesting copy c-tor. String s3(s1) and String s4 = s1";
	String s3 (s1);
	cout << "\nString s3 is: " << s3 << ". Length: " << s3.size();
	String s4 = s1;
	cout << "\nString s4 is: " << s4 << ". Length: " << s4.size() << endl;
	
	// Testing move c-tor
	cout << "\nTesting move c-tor: String s5 = std::move(s4)";
	String s5 = std::move(s4);
	cout << "\nString s5 is: " << s5 << ". Length: " << s5.size();
	cout << "\nString s4. Length: " << s4.size() << ". String is: " << s4 << endl;
	
	// Testing operators == and !=
	cout << "\nTesting operators == and != : s1 == s3, s1 != s3";
	cout << '\n' << s1 << " == " << s3 << "? : " << boolalpha << (s1 == s3);
	cout << '\n' << s1 << " != " << s3 << "? : " << boolalpha << (s1 != s3) << endl;
	
	// Testing assignment operator
	cout << "\nTesting assignment operator: s5 = s";
	s5 = s;
	cout << "\nString s5 is: " << s5 << ". Length: " << s5.size() << endl;
	
	// Testing move operator
	cout << "\nTesting move operator: s1 = std::move(s5)";
	s1 = std::move(s5);
	cout << "\nString s1 is: " << s1 << ". Length: " << s1.size();
	cout << "\nString s5 is: " << s5 << ". Length: " << s5.size() << endl;
	
	// Testing operators <, >, <=, >=
	cout << "\nTesting operators <, >, <=, >=";
	cout << '\n' << s1 << " < " << s3 << " ? : " << boolalpha << (s1 < s3);
	cout << '\n' << s3 << " < " << s1 << " ? : " << boolalpha << (s3 < s1);
	cout << '\n' << s1 << " > " << s3 << " ? : " << boolalpha << (s1 > s3);
	cout << '\n' << s3 << " > " << s1 << " ? : " << boolalpha << (s3 > s1);
	cout << '\n' << s1 << " <= " << s3 << " ? : " << boolalpha << (s1 <= s3);
	cout << '\n' << s3 << " <= " << s1 << " ? : " << boolalpha << (s3 <= s1);
	cout << '\n' << s1 << " >= " << s3 << " ? : " << boolalpha << (s1 >= s3);
	cout << '\n' << s3 << " >= " << s1 << " ? : " << boolalpha << (s3 >= s1) << endl;

	// Testing string concatenation
	cout << "\nTesting string concatenation: s += s3";
	s += s3;
	cout << "\nString s is: " << s << ". Length: " << s.size();
	cout << "\nString s3 is: " << s3 << ". Length: " << s3.size() << endl;

	// Testing operator() - Return a substring
	cout << "\nTesting operator() - Return a substring: String s6 = s(0,2)";
	String s6 = s(0,2);
	cout << "\nString s6 is: " << s6 << ". Length: " << s6.size();
	cout << "\nTesting operator() - invalid index: s6 = s(100,2)";
	try 
	{
		s6 = s(100,2);
	}
	catch (invalid_argument& ia)
	{
		cout << "\nError: " << ia.what();
	}
	cout << "\nTesting operator() - invalid length: s6 = s(0,100)";
	try 
	{
		s6 = s(0,100);
	}
	catch (length_error& le)
	{
		cout << "\nError: " << le.what() << endl;
	}
	
	// test split()
	cout << "\nTesting split(): vector<String> v = s.split(" ")";
	vector<String> v;
	v = s.split(" !?");
	cout << "\nElements in vector: ";
	for (const String& s : v)
	{
		cout << s << ' ';
	}
	cout << endl;
	
	// Testing stl string conversion constructor
	cout << "\nTesting stl string conversion constructor: s1 += std::<string>";
	string stlString = "Stl string!";
	s1 += stlString;
	cout << "\nString s1 is: " << s1 << ". Length: " << s1.size() << endl;
	
	// Testing conversion operator to std::string
	cout << "\nTesting conversion operator to std::string: stlString = static_cast<string>(s1)";
	stlString = static_cast<string>(s1); 
	cout << "\nSTL String is: " << stlString << ". Length: " << stlString.size() << endl;
	
	// Testing String iterator
	cout << "\nTesting iterator:";
	cout << "\nString s1 is: ";
	for (auto const c : s1)
	{
		cout << c << ' ';
	}
	
	return 0;
}
