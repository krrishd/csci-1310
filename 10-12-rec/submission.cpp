#include <iostream>

using namespace std;

class Animal {
  protected:
      bool endangered;
      int population;
  public:
      Animal(){};
      Animal(bool e, int p) {
        endangered = e;
        population = p;
      };
      void isEndangered() {
        if (endangered) {
          cout << "It's endangered." << endl; 
        }
      }
      void printPopulation() {
        cout << "Population: " << population << endl;
      }
};

class Dog: public Animal {
  private:
      string breed;
  public:
      Dog(){};
      Dog(bool e, int p, string b) {
        breed = b;
        endangered = e;
        population = p;
      };
      void printPopulation() {
        cout << "The population of the breed " << breed << " is: " << population << endl;
      }
      void printBreed() {
        cout << "Breed: " << breed << endl;
      }
};

class Cat: public Animal {
  private:
        string eyeColor;
  public:
        Cat(){};
        Cat(bool e, int p, string ec) {
          endangered = e;
          population = p;
          eyeColor = ec;
        };
        void printEyeColor() {
          cout << "Eye Color: " << eyeColor << endl;
        }
};

int main() {
  Cat tom = Cat(true, 1000, "blue");
  tom.printEyeColor();
  tom.printPopulation();
  Dog bowwow = Dog(true, 10000, "German Shepherd");
  bowwow.isEndangered();
  bowwow.printPopulation();
}
