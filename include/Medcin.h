#ifndef MEDCIN_H
#define MEDCIN_H
#include<iostream>
#include <string>
#include<iomanip>
using namespace std;
class Medcin {
private:

    int id;
    string name;
    string brand;
    int price;

public:
    Medcin();
    Medcin(int id, string name, string brand,int price);
    // Getters
    int getPrice()const;
    int getId() const;
    string getName() const;
    string getBrand() const;

    // Setters
    void setPrice(const int& price);
    void setId(int id);
    void setName(const string& name);
    void setBrand(const string& brand);
    friend ostream& operator<<(ostream&, Medcin& m);
    friend istream& operator>>(istream&, Medcin& m);
    // Another Functions
    void Edit();
    //void editQuntitiy();

};

#endif  // MEDCIN_H
