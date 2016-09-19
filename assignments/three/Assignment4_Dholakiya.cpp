/*
	Name: Krishna Dholakiya
	Recitation TA: Brennan McConnell
	Assignment Number: 3
 */

#include <iostream>
#include <map>

using namespace std;

// instantiated an array for our messageBoard with 
// 20x20 dimensions + it accepts strings
string messageBoard [20][20];

map<string, string> items;

// for use when trying to obtain the full string version 
// of the letter representation of the items
void initMap() {
	items["b"] = "bicycle";
	items["m"] = "microwave";
	items["d"] = "dresser";
	items["t"] = "truck";
	items["c"] = "chicken";
}

string validTypes [] = {"b", "m", "d", "t", "c"};

// checks if user input of type is valid
bool isValidInput(string input) {
	bool validInput = false;
	for (int i = 0; i < sizeof(validTypes); i++) {
		if (validTypes[i] == input) {
			validInput = true;
		}
	}

	if(!validInput) {
		cout << "Not a valid item type.\n";
	}
	
	return validInput;
}

// runs the main menu and returns a 
// string with the user's input
string menu() {
	string choice;

	cout << "1. Insert an item.\n";
	cout << "2. Search for an item\n";
	cout << "3. Print the message board.\n";
	cout << "4. Quit.\n";
	cin >> choice;

	return choice;
}

// asks for user input and inserts user input 
// as a new item in the messageBoard array
void insertItem() {
	string itemType;
	string itemCost;

	bool inserted = false;
	int i = 0;

	cout << "Enter the item type-b,m,d,t,c:";
	cin >> itemType;
	while (!isValidInput(itemType)) {
		cout << "Enter the item type-b,m,d,t,c:";
		cin >> itemType;
	}
	cin.ignore();
	cout << "Enter the item cost:";
	cin >> itemCost;
	cin.ignore();

	// iterates through messageBoard until it finds an 
	// empty space (where values are "0"), replaces 
	// empty space with new insert
	

	while (!inserted && i < (sizeof(messageBoard)/sizeof(messageBoard[0]))) {
		if (messageBoard[i][0] == "0") {
			messageBoard[i][0] = itemType;
			messageBoard[i][1] = itemCost;
			inserted = true;
		} else {
			i++;
		}
	}
}

// asks for user input and searches for 
// item in messageBoard that 
// matches criteria
void searchMessageBoard() {
	string itemType;
	int itemCost;

	cout << "Enter the item type-b,m,d,t,c:";
	cin >> itemType;
	while (!isValidInput(itemType)) {
		cout << "Enter the item type-b,m,d,t,c:";
		cin >> itemType;
	}
	cin.ignore();
	cout << "Enter the maximum item cost:";
	cin >> itemCost;
	cin.ignore();

	bool itemFound = false;
	int i = 0;

	// iterates through messageBoard, 
	// finds item that matches search criteria, 
	// and exits loop after printing the "sold" message 
	// and deleting the item from messageBoard
	while (!itemFound && i < (sizeof(messageBoard)/sizeof(messageBoard[0]))) {
		if (messageBoard[i][0] == itemType) {
			if (stoi(messageBoard[i][1]) <= itemCost) {
				cout << "Sold " + items[messageBoard[i][0]] + " for " + messageBoard[i][1] << endl;
				messageBoard[i][0] = "0";
				messageBoard[i][1] = "0";
				itemFound = true;
			} else {
				i++;
			}
		} else {
			i++;
		}
	}

	if (!itemFound) {
		cout << "Item not found\n";
	}

}


// displays the messageBoard array
void printMessageBoard() {

	for(int i = 0; i < (sizeof(messageBoard)/sizeof(messageBoard[0])); i++) {
		if (messageBoard[i][0] != "0") {
			cout << items[messageBoard[i][0]] + ": " + messageBoard[i][1] << endl;
		}
	}

}

int main() {
	bool exit = false;

	for (int i = 0; i < (sizeof(messageBoard)/sizeof(messageBoard[0])); i++) {
		messageBoard[i][0] = "0";
		messageBoard[i][1] = "0";
	}

	initMap();

	while(!exit) {
		string choice = menu();
		if (choice == "4") {
			exit = true;
			return 0;
		} else if (choice == "1") {
			insertItem();
		} else if (choice == "2") {
			searchMessageBoard();
		} else if (choice == "3") {
			printMessageBoard();
		} else if (choice == "4") {
			exit = true;
		} else {
			cout << "Try again! Your input doesn't seem valid.\n";
		}
	}

}