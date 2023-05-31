#ifndef MEDICAL_INSURANCE_H
#define MEDICAL_INSURANCE_H
#include <iostream>
#include <string>

using namespace std;

class Medical_Insurance {
private:
    string type[4];
    double coverage[4];

public:
    // Default constructor
    Medical_Insurance();

    // Getters
    string getType(int index) const ;
    double getCoverage(int index) const ;

    // Setters
    void setType(int index, const string& newType);
    void setCoverage(int index, double newCoverage) ;

    // Overload << operator for output
    friend ostream& operator<<(ostream& os, const Medical_Insurance& mi) ;
    friend istream& operator>>(istream& is, Medical_Insurance& mi) ;
};







#endif // MEDICAL_INSURANCE_H
