#ifndef INTELLECTUALPROPERTY_H
#define INTELLECTUALPROPERTY_H

#include <iostream>

class Startup;

class IntellectualProperty {
  public:
    IntellectualProperty();
    void pushUpdate(Startup * userStartup);
  protected:
  private:
};

class Website: public IntellectualProperty {
  public:
    Website();
    void generateAwareness(Startup * userStartup);
    void causeDownload(Startup * userStartup);
    void pushUpdate(Startup * userStartup);
  protected:
  private: 
};

class App: public IntellectualProperty {
  public:
    App();
    void generateRevenue(Startup * userStartup);
    void crash(Startup * userStartup);
  protected:
  private:
};

#endif // INTELLECTUALPROPERTY_H