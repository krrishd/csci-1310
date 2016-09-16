#include <iostream>

using namespace std;

double calculateCO2(int mpg, int miles) {
	double gallons = miles / mpg;
	double poundsOfCO2 = gallons * 19.4;
	return poundsOfCO2;
}

int main() {
	cout << "How many miles do you drive in a year?\n";
	int miles;
	cout << "Answer (hit enter when answered): ";
	cin >> miles;
	cout << "How many miles per gallon does your car do?\n";
	int mpg;
	cout << "Answer (hit enter when answered): ";
	cin >> mpg;
	cout << "The pounds of CO2 produced are " << calculateCO2(mpg, miles) << " lbs.";
	return 0;
}
