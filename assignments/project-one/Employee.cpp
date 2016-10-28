#include <iostream>
#include <stdlib.h>
#include "Employee.h"
#include "Startup.h"

using namespace std;

Employee::Employee() {

}

Employee::~Employee() {

}

void Employee::work(Startup * userStartupPointer) {
  Startup userStartup = *userStartupPointer;
  int randomNumber = rand() % 100;
  if (randomNumber > 90) {
    userStartup.getStartupIP().startupApp.generateRevenue(userStartupPointer);
  } else if (randomNumber > 85) {
    userStartup.getStartupIP().startupApp.crash(userStartupPointer);
  } else if (randomNumber > 75) {
    userStartup.getStartupIP().startupApp.pushUpdate(userStartupPointer);
  } else if (randomNumber > 25) {
    userStartup.getStartupIP().startupWebsite.generateAwareness(userStartupPointer);
  } else if (randomNumber > 15) {
    userStartup.getStartupIP().startupWebsite.causeDownload(userStartupPointer);
  } else {
    userStartup.getStartupIP().startupWebsite.pushUpdate(userStartupPointer);
  }
}

void Employee::complain(Startup * userStartupPointer) {
  Startup userStartup = *userStartupPointer;
  int randomNumber = rand() % 100;
  if (randomNumber > 90) {
    cout << "   - Overheard: 'Working here would be so much easier if we had a bigger kitchen.'" << endl;
  } else if (randomNumber > 70) {
    cout << "   - Overheard: 'WHO DELETED LITERALLY ALL MY WORK FROM THE PAST 2 HOURS'" << endl;
  } else if (randomNumber > 50) {
    cout << "   - Overheard: 'Does anyone know what they're doing? Or nah'" << endl;
  } else if (randomNumber > 30) {
    cout << "   - Overheard: 'GitHub's down, who wants donuts?'" << endl;
  } else if (randomNumber > 10) {
    cout << "   - Overheard: 'Do we have runway still or am I getting fired at some point?'" << endl;
  } else {
    cout << "   - Overheard: 'Where's the intern? We aren't not paying him for nothing...'" << endl;
  }
  userStartup.setValuation(userStartup.getValuation() - 105);
  *userStartupPointer = userStartup;
}