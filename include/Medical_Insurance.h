#ifndef MEDICAL_INSURANCE_H
#define MEDICAL_INSURANCE_H
#include <iostream>
#include <string>

using namespace std;

class MedicalInsurance {
private:
    string type[3];
    double coverage[3];

public:
    // Default constructor
    MedicalInsurance();

    // Getters
    string getType(int index) const ;
    double getCoverage(int index) const;

    // Setters
    void setType(int index, const string& newType);
    void setCoverage(int index, double newCoverage) ;

    // Overload << operator for output
    friend ostream& operator<<(ostream& os, const MedicalInsurance& mi) ;
    friend istream& operator>>(istream& is, MedicalInsurance& mi) ;
};







#endif // MEDICAL_INSURANCE_H
