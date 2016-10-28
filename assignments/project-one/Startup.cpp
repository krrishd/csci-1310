#include "Startup.h"
#include "Employee.h"
#include "IntellectualProperty.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

Startup::Startup() {

}

Startup::Startup(string startupName) {
  name = startupName;
  valuation = 100000;
  numberOfEmployees = 0;
}

Startup::Startup(string startupName, int initialValuation, int employees) {
  name = startupName;
  valuation = initialValuation;
  for (int i = 0; i < employees; i++) {
    startupEmployees[i] = Employee();
  }
  numberOfEmployees = employees;
}

Startup::LegalStatus::LegalStatus() {
  classification = "LLC";
};

void printClassification(Startup::LegalStatus legalStatus) {
  cout << "Legal Status: " << legalStatus.classification << endl;
}

void Startup::printValuation() {
  cout << "\033[2J\033[1;1H";
  cout << name << "'s valuation: $" << valuation << endl;
}

int Startup::getValuation() {
  return valuation;
}

void Startup::setValuation(int newValuation) {
  valuation = newValuation;
}

void Startup::printNumberOfEmployees() {
  cout << "\033[2J\033[1;1H";
  cout << name << " employs " << numberOfEmployees << " people." << endl;
}

IntellectualPropertyStruct Startup::getStartupIP() {
  return startupIP;
}

void Startup::hireEmployee() {
  if (valuation < 1000) {
    cout << "\033[2J\033[1;1H";
    cout << "You're nearly broke and no one is dumb enough to work for 'exposure'. Sorry." << endl;
    return;
  }
  startupEmployees[numberOfEmployees - 1] = Employee();
  numberOfEmployees++;
  valuation -= 1000; // it costs money to secure that good, good, talent
  cout << "\033[2J\033[1;1H";
  cout << "New employee hired!" << endl;
}

void Startup::yellAtEmployees(Startup * userStartup) {
  cout << "\033[2J\033[1;1H";
  int beforeValuation = valuation;
  cout << "Office Productivity Log:" << endl;
  for (int i = 0; i < numberOfEmployees; i++) {
    int randomNumber = rand() % 100;
    if (randomNumber > 40) {
      startupEmployees[numberOfEmployees - 1].work(userStartup);
    } else {
      startupEmployees[numberOfEmployees - 1].complain(userStartup);
    }
  }
  int afterValuation = valuation;
  cout << "\n";
  cout << "Your valuation before yelling at your employees was $" << beforeValuation << endl;
  cout << "Your valuation after yelling at your employees is $" << afterValuation << endl;
  if ((afterValuation - beforeValuation) >= 0) {
    cout << "Good going! Gotta make sure that talent is worth every nickel." << endl;
  } else {
    cout << "If your employees don't dislike you, are you ever going to be Steve Jobs? Even Apple was broke once." << endl;
  }
}

void Startup::fireEmployees(int numberOfEmployeesToFire) {
  numberOfEmployees -= numberOfEmployeesToFire;
  Employee newStartupEmployees[100];
  for (int i = 0; i < numberOfEmployees; i++) {
    newStartupEmployees[i] = Employee();
  }
  for (int j = 0; j < (numberOfEmployees + numberOfEmployeesToFire); j++) {
    startupEmployees[j] = newStartupEmployees[j];
  }
  cout << "\033[2J\033[1;1H";
  cout << "Fired " << numberOfEmployeesToFire << " employees. Tough times, huh." << endl;
}

void Startup::createWebsite() {
  startupIP.startupWebsite = Website();
  cout << "\033[2J\033[1;1H";
  cout << "Your new website is up! Time to add it to your Twitter bio." << endl;
}

void Startup::createApp() {
  startupIP.startupApp = App();
  cout << "\033[2J\033[1;1H";
  cout << "You just launched the official " << name << " app! Your startup is kinda real now!" << endl;
}

void Startup::generateRecordOfStartup() {
  // file i/o
  ofstream f;
  f.open("LEGAL_RECORD_OF_" + name + ".txt");
  f 
    << "Here's a legally verified/notarized/whatever record that the startup "
    << name << " LLC existed at one point and had " << numberOfEmployees << 
    " employees, a valuation of $" << valuation << ", and a ping-pong table.\n\n" <<
    "- Law Offices of Ralphie & Ralphie\n";
  cout << "\033[2J\033[1;1H";
  cout 
    << "It's on paper that you existed. Isn't that reassuring?\n"
    << "Check it out at LEGAL_RECORD_OF_" << name << ".txt\n";
}