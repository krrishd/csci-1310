#include <iostream>

using namespace std;

int del(int someArray[], int n, int valueToDelete)[] {
	bool valueFound = false;
	int searchIndex = 0;
	int valueIndex;

	while(!valueFound) {
		if (someArray[searchIndex] != valueToDelete && n > searchIndex) {
			searchIndex++;
		} else if (n <= searchIndex) {
			cout << "Value not found \n";
		} else {
			valueIndex = searchIndex;
			valueFound = true;
		}

	}

	int currentArraySize = n;

	for(int i = currentArraySize+1; i > valueIndex; i--) {
		someArray[i] = someArray[i - 1];
	}

	return someArray;
}

int main() {
	int iSearch[6] = {1,3,4,5};
	int iUsed = 4;
	for(int i = 0; i < iUsed; i++) {
		cout << iSearch[i] << endl;
	}

	// insert 2 at position 1	

	int index = 1;

	for(int x = iUsed; x > index; x--) {
		iSearch[x] = iSearch[x-1];
	}

	iSearch[1] = 2;

	iUsed++;

	for(int i = 0; i < iUsed; i++) {
		cout << iSearch[i] << endl;
	
	}

	int someArray[] = {1,2,3,4,5};
	int newArray[] = del(someArray, 5, 2);
	for(int b = 0; b < 5; b++) {
		cout << newArray[b] << endl;
	}

}


