#include <iostream>

using namespace std;

class Automobile {
     private:
          string make;
	  string model;
	  string condition;
	  int year;
     public:
	  Automobile(string ma, string mo, int y) {
               // make, model, year
	       make = ma;
	       model = mo;
	       year = y;
	       condition = "new";
	       //cout << "calling constructor" << endl;
	  }
	  string getCondition() {
	       return condition;
	  }
	  void setCondition(string newCondition) {
		condition = newCondition;
	  }
};

int main() {
     Automobile prius("Toyota", "Prius", 2010);
     cout << prius.getCondition() << endl;
     string newCondition;
     cout << "Set a new condition: ";
     cin >> newCondition;
     cin.ignore();
     prius.setCondition(newCondition);
     cout << prius.getCondition() << endl;
}
