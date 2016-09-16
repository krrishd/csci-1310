#include <iostream>

using namespace std;

int addNum(int a, int b) {
	return (a+b);
}

void setAtPointer(int a, int b, int *location) {
	int loc = addNum(a,b);
	*location = loc;
}

int main() {
	int *location;
	int sum;
	location = &sum;
	setAtPointer(1,2, location);	
	cout << sum << endl;
}
