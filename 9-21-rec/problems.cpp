#include <iostream>

using namespace std;

int reverseInt(int normal) {
	string normalString = std::to_string(normal);
	string reverseString = normalString;
	for(int i = 0; i < normalString.length(); i++) {
		reverseString[normalString.length() - 1 - i] = normalString[i];
	}
	return (stoi(reverseString));
}

int main() {
	cout << reverseInt(123) << endl;
}
