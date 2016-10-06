#include <iostream>

using namespace std;

struct myStruct {
	string name;
	int score;
	// this is the constructor
	myStruct(string n, int s) {
		name = n;
		score = s;
	}
	myStruct() {}
};

struct WeatherData {
	double temp;
	double humidity;
	double wind;
};

int main() {
	WeatherData wd;
	wd.humidity = 45;
	wd.temp = 34;
	wd.wind = 12;

	/*cout << wd.humidity << endl;
	cout << wd.temp << endl;
	cout << wd.wind << endl;*/

	// array of structs
	WeatherData wdArray[10]; // type, var name, array size
	for (int i = 0; i < 10; i++) {
		wdArray[i].humidity = i + 10;
		wdArray[i].temp = i * 10;
		wdArray[i].wind = 100.0/i;	
	}

	for (int i = 0; i < 10; i++) {
		cout << wdArray[i].humidity << ", " << wdArray[i].temp << ", " << wdArray[i].wind << endl;
	}

	struct Team {
		string name;
		int wins;
		int loses;
		Team(string n) {
			name = n;
		}
		Team(string n, int w, int l) {
			name = n;
			wins = w;
			loses = l;
		}
		Team(){};
	};

	Team teamArray[5];
	teamArray[0] = Team("LA Dodgers", 91, 68);
	teamArray[1] = Team("San Francisco", 84, 75);
	teamArray[2] = Team("Colorado", 74, 85);
	teamArray[3] = Team("San Diego", 68, 91);
	teamArray[4] = Team("Arizona", 66, 93);
}
