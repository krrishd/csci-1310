#ifndef WEATHERFORECASTER_H
#define WEATHERFORECASTER_H

#include <iostream>
 

struct ForecastDay{
    std::string day;
    std::string forecastDay;
    int highTemp;
    int lowTemp;
    int humidity;
    int avgWind;
    std::string avgWindDir;
    int maxWind;
    std::string maxWindDir;
    double precip;

};

class WeatherForecaster
{
    public:
        WeatherForecaster();
        ~WeatherForecaster();
        bool dayExists(std::string);
        void addDayToData(ForecastDay);
        void printDaysInData(); //prints the unique dates in the data
        void printForecast(std::string, std::string);
        void printForecastForDay(std::string);
        void printFourDayForecast(std::string);
        double calculateTotalPrecipitation();
        void printLastDayItRained();
        void printLastDayAboveTemperature(int); //argument is the temperature
        void printTemperatureForecastDifference(std::string);
        void printPredictedVsActualRainfall(int); //argument is days out, such as 1 = 1 day out, 2 = 2 days out, 3 = 3 days out
        std::string getFirstDayInData();
        std::string getLastDayInData();

    protected:
    private:
        int arrayLength;
        int index;
        ForecastDay yearData[984]; //data for each day
};

#endif // WEATHERFORECASTER_H
