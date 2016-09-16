#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void convertSeconds(int secondsInput) {
	int hours = secondsInput / 3600;
	int remainder = secondsInput % 3600;
	int minutes;
	int seconds;
	if (remainder >= 60) {
		minutes = remainder / 60;
	       	seconds = remainder % 60;	
	} else {
		minutes = 0;
		seconds = remainder;
	}

	cout << "The time is " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds\n\n";
}

string promptForPlayGame() {
	cout << "   Choose from the following:\n";
	cout << "      a. Fight the dragon [enter A]\n";
	cout << "      b. Go home [enter B]\n";
	cout << "      c. Save the princess [enter C]\n";
	cout << "   Type the letter of your choice: ";
	string choice;
	cin >> choice;
	cin.ignore();
	return choice;
}

bool victoryForPlayGame() {
	int randomNumber = rand() % 11 + 1;
	bool victory;
	if (randomNumber >= 6) {
		victory = true;
	} else {
		victory = false;
	}
	
	if (victory) {
		cout << "\n  > You win!\n\n";
	} else {
		cout << "\n  > You lose!\n\n";
	}

	return victory;
}

void playGame() {
	bool gameOver = false;
	while (!gameOver) {
		string userChoice = promptForPlayGame();
		if (userChoice == "B") {
			cout << "\n  > Wimp.\n\n";
			gameOver = true;
		} else if (userChoice == "C") {
			cout << "\n  > You saved the princess\n\n";
		} else if (userChoice == "A") {
			bool victory = victoryForPlayGame();
			if (!victory) {
				gameOver = true;
			}
		}
	}
}

void solveMaze(int maze[4][4]) {
	int currentX = 0;
	int currentY = 3;
	const int appleX = 3;
	const int appleY = 0;

	while (maze[currentY][currentX] != 2) {
		if ((currentY != appleY) and (maze[(currentY - 1)][currentX] != 1)) {
			cout << "Moved up\n";
			currentY -= 1;
		} else if ((currentX != appleX) and (maze[currentY][(currentX + 1)] != 1)) {
			cout << "Moved right\n";
			currentX += 1;
		}
	}

	cout << "The horse has reached the apple!\n";
}


int main() {
	int input;
	cout << "Input the number of seconds: ";
	cin >> input;
	cin.ignore();

	convertSeconds(input);
	playGame();

	int maze[4][4] = {
		{1,1,0,2},
		{0,0,0,1},
		{0,1,0,1},
		{0,0,0,1}
	};

	solveMaze(maze);
}
