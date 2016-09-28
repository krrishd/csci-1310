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

double maxPossProfit(double stocks[10]) {
	double min;
	double max;
	for(int i = 0; i < 10; i++) {
		if (stocks[i] > max) {
			max = stocks[i];
		} else if (stocks[i] < min) {
			min = stocks[i];
		}
	}
	return (max-min);
}

int main() {
	cout << reverseInt(123) << endl;
}
