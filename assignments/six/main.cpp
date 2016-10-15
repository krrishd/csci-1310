#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "WeatherForecaster.h"

using namespace std;

int main() {
    WeatherForecaster forecaster;
    ifstream forecastFile;
    forecastFile.open("boulderData.txt");
    string currentLine;
    while (getline(forecastFile, currentLine)) { // iterating through each line of the file
      stringstream ssline(currentLine);
      string column;
      ForecastDay currentForecast;
        int positionInRow = 0;  
      while (getline(ssline, column, ',')) { // iterating through each column (separated by ',')
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
      forecaster.addDayToData(currentForecast);
    }
    cout << "Forecast statistics:" << endl;
    forecaster.printLastDayItRained();
    cout << "Total rainfall: " << forecaster.calculateTotalPrecipitation() << endl;
    cout << "First date in data: " << forecaster.getFirstDayInData() << endl;
    cout << "Last date in data: " << forecaster.getLastDayInData() << endl;
    string enteredDate;
    cout << "Enter a date: ";
    getline(cin, enteredDate);
    if (forecaster.dayExists(enteredDate)) {
      forecaster.printForecastForDay(enteredDate);
      forecaster.printFourDayForecast(enteredDate);
    } else {
      //cout << "Date not found." << endl;
    }
}