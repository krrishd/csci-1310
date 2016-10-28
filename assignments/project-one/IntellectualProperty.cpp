#include "Startup.h"
#include "IntellectualProperty.h"
#include <iostream>

using namespace std;

IntellectualProperty::IntellectualProperty() {

}

void IntellectualProperty::pushUpdate(Startup * userStartupPointer) {
  Startup userStartup = *userStartupPointer;
  userStartup.setValuation(userStartup.getValuation() + 500);
  cout << "   + An update was just pushed! It just bumped your valuation up by $500." << endl;
  *userStartupPointer = userStartup;
}

Website::Website() {

}

void Website::generateAwareness(Startup * userStartupPointer) {
  Startup userStartup = *userStartupPointer;
  userStartup.setValuation(userStartup.getValuation() + 10);
  cout << "   + More people know your startup exists thanks to your site! Your valuation went up by $10." << endl;
  *userStartupPointer = userStartup;
}

void Website::causeDownload(Startup * userStartupPointer) {
  Startup userStartup = *userStartupPointer;
  userStartup.setValuation(userStartup.getValuation() + 20);
  cout << "   + Someone actually downloaded your app through your website! Let's hope they open it at some point. Your valuation is up by $20." << endl;
  *userStartupPointer = userStartup;
}

void Website::pushUpdate(Startup * userStartupPointer) {
  Startup userStartup = *userStartupPointer;
  userStartup.setValuation(userStartup.getValuation() + 15);
  cout << "   + Your website was just updated! Maybe more people will understand what exactly you do with all this time and money, so your valuation went up by $15." << endl;
  *userStartupPointer = userStartup;
}

App::App() {

}

void App::generateRevenue(Startup * userStartupPointer) {
  Startup userStartup = *userStartupPointer;
  userStartup.setValuation(userStartup.getValuation() + 500);
  cout << "   + Hmmm it's weird but you're actually making money from your app, your valuation is up by $500." << endl;
  *userStartupPointer = userStartup;
}

void App::crash(Startup * userStartupPointer) {
  Startup userStartup = *userStartupPointer;
  userStartup.setValuation(userStartup.getValuation() - 200);
  cout << "   + Your app servers have crashed and your valuation dropped $200. Maybe you should've thought twice before spending our devops budget on t-shirts." << endl;
  *userStartupPointer = userStartup;
}