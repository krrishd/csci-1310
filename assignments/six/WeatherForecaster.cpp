#include "WeatherForecaster.h"
#include <iostream>

using namespace std;

WeatherForecaster::WeatherForecaster() {

}

WeatherForecaster::~WeatherForecaster() {

}

// iterates through dates until a matching date is found
bool WeatherForecaster::dayExists(string day) {
  bool exists = false;
  for (int i = 0; i < 984; i++) {
    if (yearData[i].day == day && yearData[i].day == day) {
      exists = true;
      break;
    }
  }
  return exists;
}

void WeatherForecaster::addDayToData(ForecastDay day) {
  yearData[index] = day;
  index++;
}

// iterates through dates that have matching date & forecast date, prints
void WeatherForecaster::printDaysInData() {
  for (int i = 0; i < 984; i++) {
    if (yearData[i].day == yearData[i].forecastDay) {
      cout << yearData[i].day << endl;
    }
  }
}

void WeatherForecaster::printForecast(string dayInput, string dayForecastIsMade) {
  for (int i = 0; i < 984; i++) {
    if (yearData[i].forecastDay == dayInput && yearData[i].day == dayForecastIsMade) {
      cout << "Forecast for " << yearData[i].day << ":" << endl;
      cout << "H: " << yearData[i].highTemp << endl;
      cout << "L: " << yearData[i].lowTemp << endl;
      cout << "Humidity: " << yearData[i].humidity << endl;
      cout << "Avg. wind: " << yearData[i].avgWind << " mph" << endl;
      cout << "Avg. wind direction: " << yearData[i].avgWindDir << endl;
      cout << "Max wind: " << yearData[i].maxWind << " mph" << endl;
      cout << "Max wind direction: " << yearData[i].maxWindDir << endl;
      cout << "Precipitation: " << yearData[i].precip << " inches" << endl;
      break;
    }
  }
}

void WeatherForecaster::printForecastForDay(string dayInput) {
  printForecast(dayInput, dayInput);
}

// prints every day's forecast that forecasted the user input date
void WeatherForecaster::printFourDayForecast(string dayInput) {
  for (int i = 0; i < 984; i++) {
    if (yearData[i].day == dayInput) {
      printForecast(yearData[i].forecastDay, yearData[i].day);
    }
  }
}

// Iterates through forecast data and adds
// each precipitation value to a double which
// is then returned by the function at the end
double WeatherForecaster::calculateTotalPrecipitation() {
  double totalPrecipitation = 0;
  for (int i = 0; i < 984; i++) {
    if (yearData[i].day == yearData[i].forecastDay) {
      totalPrecipitation += yearData[i].precip;
    }
  }
  return totalPrecipitation;
}

// iterates thru the array until the last nonzero precip value
void WeatherForecaster::printLastDayItRained() {
  string lastDayItRained;
  for (int i = 0; i < 984; i++) {
    if (yearData[i].day == yearData[i].forecastDay) {
      if (yearData[i].precip > 0.0) {
        lastDayItRained = yearData[i].day;
      }
    }
  }
  cout << "It last rained on: " << lastDayItRained << endl;
}

// iterates thru the array until the last date at which the highTemp is
// higher than the user input
void WeatherForecaster::printLastDayAboveTemperature(int tempInput) {
  string lastDayAboveTemperature;
  for (int i = 0; i < 984; i++) {
    if (yearData[i].day == yearData[i].forecastDay) {
      if (yearData[i].highTemp > tempInput) {
        lastDayAboveTemperature = yearData[i].day;
      }
    }
  }
  if (lastDayAboveTemperature.length() < 2) {
    cout << "No days found that exceed that temperature." << endl;
  } else {
    cout << "It was above " << tempInput << " on " << lastDayAboveTemperature << endl;
  }
}

// prints forecast for every date for which the forecastDay matches the user input
void WeatherForecaster::printTemperatureForecastDifference(string dayInput) {
  for (int i = 0; i < 984; i++) {
    if (yearData[i].forecastDay == dayInput) {
      cout << "Forecast for " << yearData[i].forecastDay << " issued on " << yearData[i].day << endl;
      cout << "H: " << yearData[i].highTemp << endl;
      cout << "L: " << yearData[i].lowTemp << endl;
    }
  }
}

// iterates through forecasts, finds every one for which
// the forecastDay matches the day on which the forecast was made,
// goes back and finds the day <x> days before where the user inputted day
// was forecasted, takes the difference and adds it to a total which is printed
// in the end
void WeatherForecaster::printPredictedVsActualRainfall(int daysBefore) {
  double diff = 0;
  int daysGoneBack = 0;
  for (int i = 0; i < 984; i++) {
    if (yearData[i].forecastDay == yearData[i].day) {
      for (int j = i - 1; j >= 0; j--) {
        if (daysGoneBack == daysBefore) {
          if (yearData[j].forecastDay == yearData[i].forecastDay) {
            diff += yearData[i].precip - yearData[j].precip;
          }
          daysGoneBack = 0;
          break;
        }
        daysGoneBack++;
      }
    }
  }
  cout << "Predicted vs. actual rainfall: " << diff << endl;
}

// iterates through forecasts until a date is found where the forecast date is the same
string WeatherForecaster::getFirstDayInData() {
  string firstDay;
  bool dayFound = false;
  for (int i = 0; i < 984 && !dayFound; i++) {
    if (yearData[i].forecastDay == yearData[i].day) {
      firstDay = yearData[i].day;
      dayFound = true;
    }
  }
  return firstDay;
}

// iterates through forecasts and saves each date with the same forecast date to a
// single variable, the result of that variable being the last day that meets
// that criteria
string WeatherForecaster::getLastDayInData() {
  string lastDay;
  for (int i = 0; i < 984; i++) {
    if (yearData[i].forecastDay == yearData[i].day) {
      lastDay = yearData[i].day;
    }
  }
  return lastDay;
}

