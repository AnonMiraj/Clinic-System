#include "Medical_Insurance.h"

// Default constructor
Medical_Insurance::Medical_Insurance()
{
    type[0] = "No Medical Insurance";
    type[1] = "Basic";
    type[2] = "Premium";
    type[3] = "Standard";

    coverage[0] = 0.0;
    coverage[1] = 0.10;
    coverage[2] = 0.25;
    coverage[3] = 0.50;

}

// Getters
string Medical_Insurance::getType(int index) const  {
    if (index >= 0 && index < 4)
        return type[index];
    else
        return "";
}

double Medical_Insurance::getCoverage(int index) const {
    if (index >= 0 && index < 4)
        return coverage[index];
    else
        return 0.0;
}

// Setters
void Medical_Insurance::setType(int index, const string& newType) {
    if (index >= 0 && index < 4)
        type[index] = newType;
}

void Medical_Insurance::setCoverage(int index, double newCoverage) {
    if (index >= 0 && index < 4)
        coverage[index] = newCoverage;
}


// Overload << operator for output
ostream& operator<<(ostream& os, const Medical_Insurance& mi) {
    for (int i = 0; i < 4; ++i) {
        os << "Type: " << mi.type[i] << ", Coverage: " << mi.coverage[i] << endl;
    }
    return os;
}

// Overload >> operator for input
istream& operator>>(istream& is, Medical_Insurance& mi) {
    for (int i = 1; i < 4; ++i) {
        cout << "Enter coverage for "<<mi.type[i]<< ": ";
        is >> mi.coverage[i];
    }
    return is;
}
