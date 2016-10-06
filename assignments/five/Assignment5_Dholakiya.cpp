#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Forecast {
     string day;
     string forecastDay;
     int highTemp;
     int lowTemp;
     int humidity;
     int avgWind;
     string avgWindDir;
     int maxWind;
     string maxWindDir;
     double precip;
};

string lastDayItRained(Forecast forecastData[]) {
    string dayItLastRained;
    for (int i = 0; i < 247; i++) {
	    if (forecastData[i].precip != 0.0) {
            dayItLastRained = forecastData[i].day;
        }
    }
    return dayItLastRained;
}

double totalRainfall(Forecast forecastData[]) {
	double sumOfPrecipitation;
	for (int i = 0; i < 247; i++) {
		sumOfPrecipitation += forecastData[i].precip;
	}
	return sumOfPrecipitation;
}

int maxRainfall(Forecast forecastData[]) {
	int index;
	double maxPrecip = 0.0;
	for (int i = 0; i < 247; i++) {
		if (forecastData[i].precip > maxPrecip) {
			maxPrecip = forecastData[i].precip;
			index = i;
		}
	}
	return index;
}

int maxWindspeed(Forecast forecastData[]) {
	int index;
	int maxWind = 0;
	for (int i = 0; i < 247; i++) {
		if (forecastData[i].maxWind > maxWind) {
			maxWind = forecastData[i].maxWind;
			index = i;
		}
	}
	return index;
}

int maxTempDifference(Forecast forecastData[]) {
	int index;
	int maxDiff = 0;
	for (int i = 0; i < 247; i++) {
		int diff = forecastData[i].highTemp - forecastData[i].lowTemp;
		if (diff > maxDiff) {
			maxDiff = diff;
			index = i;
		}
	}
	return index;
}

Forecast forecastForDay(Forecast forecastData[], string day) {
	Forecast result;
	for (int i = 0; i < 247; i++) {
		if (forecastData[i].day == day) {
			result = forecastData[i];
			break;
		}
	}
	return result;
}

int main() {
    ifstream forecastFile;
    forecastFile.open("boulderData.txt");
    string currentLine;
    int positionInDataset = 0;
    int positionInResult = 0;
    Forecast arrayOfForecasts[247];
    while (getline(forecastFile, currentLine)) {
	    stringstream ssline(currentLine);
	    string column;
	    Forecast currentForecast;
        int positionInRow = 0;	
	    while (getline(ssline, column, ',')) {
	        if (positionInRow == 0) {
	            currentForecast.day = column;
	        } else if (positionInRow == 1) {
	            currentForecast.forecastDay = column;
	        } else if (positionInRow == 2) {
	            string highTempStr = column.substr(2,2);
	            currentForecast.highTemp = std::stoi(highTempStr);
	        } else if (positionInRow == 3) {
	            string lowTempStr = column.substr(2,2);
	            currentForecast.lowTemp = std::stoi(lowTempStr);
	        } else if (positionInRow == 4) {
	            currentForecast.humidity = std::stoi(column);
	        } else if (positionInRow == 5) {
	            currentForecast.avgWind = std::stoi(column);
	        } else if (positionInRow == 6) {
	            currentForecast.avgWindDir = column;
	        } else if (positionInRow == 7) {
	            currentForecast.maxWind = std::stoi(column);
	        } else if (positionInRow == 8) {
	            currentForecast.maxWindDir = column;
	        } else if (positionInRow == 9) {
	            currentForecast.precip = std::stod(column);
	        }
	        positionInRow++;
	    }
	    if (currentForecast.day == currentForecast.forecastDay) {
	        arrayOfForecasts[positionInResult] = currentForecast;
	        positionInResult++;
        }
	    positionInDataset++;
    }
    cout << "Forecast statistics:" << endl;
    cout << "Last day it rained: " << lastDayItRained(arrayOfForecasts) << endl;
    cout << "Total rainfall: " << totalRainfall(arrayOfForecasts) << endl;
    cout 
    	<< "Maximum wind speed: " 
    	<< arrayOfForecasts[maxWindspeed(arrayOfForecasts)].maxWind
    	<< " mph on " << arrayOfForecasts[maxWindspeed(arrayOfForecasts)].day
    	<< endl;
    cout 
    	<< "Maximum rainfall: " 
    	<< arrayOfForecasts[maxRainfall(arrayOfForecasts)].precip
    	<< " inches on " << arrayOfForecasts[maxRainfall(arrayOfForecasts)].day
    	<< endl;
    cout 
    	<< "Maximum temperature difference: " 
    	<< arrayOfForecasts[maxTempDifference(arrayOfForecasts)].highTemp - arrayOfForecasts[maxTempDifference(arrayOfForecasts)].lowTemp
    	<< " F on " << arrayOfForecasts[maxTempDifference(arrayOfForecasts)].day
    	<< endl;

    string date;
    cout << "Enter a date: ";
    getline(cin, date);
    Forecast dayForecast = forecastForDay(arrayOfForecasts, date);
    cout << "Forecast for " << dayForecast.day << ":" << endl;
    cout << "H: " << dayForecast.highTemp << endl;
    cout << "L: " << dayForecast.lowTemp << endl;
    cout << "Humidity: " << dayForecast.humidity << endl;
    cout << "Avg. wind: " << dayForecast.avgWind << " mph" << endl;
    cout << "Avg. wind direction: " << dayForecast.avgWindDir << endl;
    cout << "Max wind: " << dayForecast.maxWind << " mph" << endl;
    cout << "Max wind direction: " << dayForecast.maxWindDir << endl;
    cout << "Precipitation: " << dayForecast.precip << " inches" << endl;
}
