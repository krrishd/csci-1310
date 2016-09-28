#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	ifstream words;
	words.open("textToEnglish.csv");
	if (words.fail()) {
		cout << "Something went wrong." << endl;
	} else {
		string word;
		while (getline(words, word, '\r')) {
			// cout << word << endl;
			// get individual strings out of each column
			// stringstream creates a stream out of a string
			stringstream ss;
			ss << word;
			while (getline(ss, word, ',')) {
				cout << word << endl;	
			}
		}
	}
}
