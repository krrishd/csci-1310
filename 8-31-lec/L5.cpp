#include <iostream>

using namespace std;

// functions
// strings and chars
// I/O
// compiling

int addNumbers(int a, int b){
	return (a+b);
}

double divNumbers(double a, double b) {
	return (a/b);
}

int main() {
	cout << "Hello, world." << endl;
	int n;
	cin >> n;
	cin.ignore();
	cout << "n = " << n << endl;

	string s;
	cout << "type a string: ";
	std::getline(cin, s);
	cout << "string: " << s << endl;	
	
	// strings vs chars
	// strings have cool methods that do stuff
	string strA = "this is a string";
	int x = strA.find('a');
	cout << x <<endl;
	cout << strA[x] << endl;

	// char
	char chrFoo[20]; //allocates space for 20 chars

	char chrWord[] = {'A', 'y', 'y', ' ', 'l', 'm', 'a', 'o', '\n'};
	
	//functions
	cout << addNumbers(1,2) << endl;	
	cout << divNumbers(3,2) << endl;
	return 0;
}
