#ifndef STARTUP_H
#define STARTUP_H

#include <iostream>
#include "IntellectualProperty.h"
#include "Employee.h"

struct IntellectualPropertyStruct {
  Website startupWebsite;
  App startupApp;
};

class Startup {
  public:
    Startup();
    Startup(std::string startupName);
    Startup(std::string startupName, int initialValuation, int employees);
    void printValuation();
    int getValuation();
    IntellectualPropertyStruct getStartupIP();
    void setValuation(int newValuation);
    void printNumberOfEmployees();
    void hireEmployee();
    void yellAtEmployees(Startup * userStartup);
    void fireEmployees(int numberOfEmployeesToFire);
    void createWebsite();
    void createApp();
    void generateRecordOfStartup();
    class LegalStatus {
      public:
        LegalStatus();
        friend void printClassification(LegalStatus legalStatus);
      private:
        std::string classification;
    };
  protected:
  private:
    std::string name;
    int valuation;
    int numberOfEmployees;
    Employee startupEmployees[100];
    IntellectualPropertyStruct startupIP;
};

#endif // STARTUP_H