#ifndef MEDCIN_H
#define MEDCIN_H
#include<iostream>
#include <string>
using namespace std;
class Medcin {
private:
    int id;
    string name;
    string brand;
    string availability;
    string warnings;

public:
    Medcin();

    // Getters
    int getId() const;
    string getName() const;
    string getBrand() const;
    string getAvailability() const;
    string getWarnings() const;

    // Setters
    void setId(int id);
    void setName(const string& name);
    void setBrand(const string& brand);
    void setAvailability(const string& availability);
    void setWarnings(const string& warnings);
};

#endif  // MEDCIN_H
