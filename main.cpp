#include <iostream>
#include <stdexcept>

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
	
	return 0;
}
