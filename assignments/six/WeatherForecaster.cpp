#include "WeatherForecaster.h"
#include <iostream>

using namespace std;

WeatherForecaster::WeatherForecaster() {

}

WeatherForecaster::~WeatherForecaster() {

}

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

void WeatherForecaster::printFourDayForecast(string dayInput) {
  for (int i = 0; i < 984; i++) {
    if (yearData[i].day == dayInput) {
      printForecast(yearData[i].forecastDay, yearData[i].day);
    }
  }
}

double WeatherForecaster::calculateTotalPrecipitation() {
  double totalPrecipitation = 0;
  for (int i = 0; i < 984; i++) {
    if (yearData[i].day == yearData[i].forecastDay) {
      totalPrecipitation += yearData[i].precip;
    }
  }
  return totalPrecipitation;
}

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

void WeatherForecaster::printTemperatureForecastDifference(string dayInput) {
  for (int i = 0; i < 984; i++) {
    if (yearData[i].forecastDay == dayInput) {
      cout << "Forecast for " << yearData[i].forecastDay << " issued on " << yearData[i].day << endl;
      cout << "H: " << yearData[i].highTemp << endl;
      cout << "L: " << yearData[i].lowTemp << endl;
    }
  }
}

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

string WeatherForecaster::getLastDayInData() {
  string lastDay;
  for (int i = 0; i < 984; i++) {
    if (yearData[i].forecastDay == yearData[i].day) {
      lastDay = yearData[i].day;
    }
  }
  return lastDay;
}

