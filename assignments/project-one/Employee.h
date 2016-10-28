#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Startup;

class Employee {
  public:
    Employee();
    ~Employee();
    void work(Startup * userStartup);
    void complain(Startup * userStartup);
  private:
  protected:
};

#endif // EMPLOYEE_H