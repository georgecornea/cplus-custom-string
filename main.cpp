#include <iostream>
#include <stdexcept>

#include "String.hpp"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
		
	// testing default c-tor
	String s;
	cout << "String s is: " << s << ". Length: " << s.size() << endl;
	cout << "Enter a new string for s: ";
	cin >> s;
	cout << "String s is: " << s << ". Length: " << s.size() << endl;

	// testing c-tor with argumet
	String s1{"Hi There!"};	
	cout << "\nString s1 is: " << s1 << ". Length: " << s1.size() << endl;
	
	// testing initializer list c-tor
	String s2{'a', 'b', 'c'};
	cout << "\nString s2 is: " << s2 << ". Length: " << s2.size() << endl;
	
	// testing operator[] as left and right values
	try
	{
		s1[1] = 'I';
		cout << "\nString s1 is: " << s1 << ". Length: " << s1.size() << endl;
		cout << "\nFirst char of s1 is: " << s1[0] << endl;
		cout << s1[100] << endl;
		
	}
	catch (const invalid_argument& exc)
	{
		cerr << "\nERROR: " << exc.what() << endl;
	}

	
	return 0;
}
