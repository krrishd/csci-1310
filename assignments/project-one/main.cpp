/*
*  Name: Krishna Dholakiya
*  TA: Brennan McConnell
*  Assignment: Project #1
 */

#include "Startup.h"
#include "Employee.h"
#include "IntellectualProperty.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// Main menu for user to choose from various options
int menu() {
  string userChoice;
  cout << "Hi there, CEO. Here's what you can do to feel like you have control of this thing:\n";
  cout << "    1. Check Valuation\n";
  cout << "    2. Hire Employee\n";
  cout << "    3. # of Employees\n";
  cout << "\n    4. ===> Yell At Employees (this keeps your startup moving) <===\n\n";
  cout << "    5. Fire Employee\n";
  cout << "    6. Create New Website\n";
  cout << "    7. Create New App\n";
  cout << "    8. Generate Record That This Thing Actually Existed At Some Point\n";
  cout << "    9. Quit\n";
  cout << "Choice (the number): ";
  getline(cin, userChoice);
  int userChoiceInt = stoi(userChoice);
  cout << "\n\n";
  return userChoiceInt;
}

string firstQuestion() {
  string result;
  cout << "Welcome to Startup Tycoon! To start off, name your startup: ";
  getline(cin, result);
  return result;
}

string secondQuestion() {
  string yesOrNo = "";
  cout 
    << 
    "Awesome! Do you want to specify the # of employees you're starting with (max 20, can't turn into a boring corporation)" 
    << endl 
    <<  "as well as your initial valuation? (Y/N): ";
  getline(cin, yesOrNo);
  return yesOrNo;
}

int main() {
  string startupName = firstQuestion();  
  
  string numberOfEmployees = "";
  string initialValuation = "";
  
  string yesOrNo = secondQuestion();

  if (yesOrNo == "Y") {
    cout << "# of employees: ";
    getline(cin, numberOfEmployees);
    cout << "Initial valuation: $";
    getline(cin, initialValuation);
  }

  Startup newStartup;

  if ((initialValuation.length() > 0) && (numberOfEmployees.length() > 0)) {
    newStartup = Startup(startupName, stoi(initialValuation), stoi(numberOfEmployees));
  } else {
    newStartup = Startup(startupName);
  }

  Startup * userStartup = &newStartup;

  bool exited = false;

  while (!exited) {
    cout << "\n";
    int userChoice = menu();
    if (userChoice == 1) {
      newStartup.printValuation();
    } else if (userChoice == 2) {
      newStartup.hireEmployee();
    } else if (userChoice == 3) {
      newStartup.printNumberOfEmployees();
    } else if (userChoice == 4) {
      newStartup.yellAtEmployees(userStartup);
    } else if (userChoice == 5) {
      newStartup.fireEmployees(1);
    } else if (userChoice == 6) {
      newStartup.createWebsite();
    } else if (userChoice == 7) {
      newStartup.createApp();
    } else if (userChoice == 8) {
      newStartup.generateRecordOfStartup();
    } else if (userChoice == 9) {
      exited = true;
    } else {
      cout << "Looks like you didn't pick anything!\n";
    }
  }
}