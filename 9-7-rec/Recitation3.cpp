#include <iostream>

using namespace std;

int main() {
	int input;
	int Everest = 29029;
	int K2 = 28251;
	int Kang = 28169;

	cout << "Enter the height of a mountain (in ft): ";
	cin >> input;
	cin.ignore();

	if (input == Everest) {
		cout << Everest << " ft is the height of Mount Everest. It is the highest mountain.";
	} else if (input == K2) {
		cout << K2 << " ft is the height of K2. It is the second highest mountain.";
	} else if (input == Kang) {
		cout << Kang << " ft is the height of Kangchenjunga. It is the third highest mountain.";
	} else {
		cout << "Height does not match that of the three highest mountains. Please enter a correct height!!";
	}

	return 0;
}
