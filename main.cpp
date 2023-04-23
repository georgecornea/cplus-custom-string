#include <iostream>

#include "String.hpp"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	String s1{"Hi There!"};
	
	cout << "String s1 is: " << s1 << ". Length: " << s1.size() << endl;
	
	return 0;
}
