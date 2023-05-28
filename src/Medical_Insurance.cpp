#include "Medical_Insurance.h"

    // Default constructor
    MedicalInsurance::MedicalInsurance() {
        type[0] = "Basic";
        type[1] = "Premium";
        type[2] = "Standard";

        coverage[0] = 0.0;
        coverage[1] = 0.0;
        coverage[2] = 0.0;
    }

    // Getters
    string MedicalInsurance::getType(int index) const {
        if (index >= 0 && index < 3)
            return type[index];
        else
            return "";
    }

    double MedicalInsurance::getCoverage(int index) const {
        if (index >= 0 && index < 3)
            return coverage[index];
        else
            return 0.0;
    }

    // Setters
    void MedicalInsurance::setType(int index, const string& newType) {
        if (index >= 0 && index < 3)
            type[index] = newType;
    }

    void MedicalInsurance::setCoverage(int index, double newCoverage) {
        if (index >= 0 && index < 3)
            coverage[index] = newCoverage;
    }


    // Overload << operator for output
    ostream& operator<<(ostream& os, const MedicalInsurance& mi) {
        for (int i = 0; i < 3; ++i) {
            os << "Type: " << mi.type[i] << ", Coverage: " << mi.coverage[i] << endl;
        }
        return os;
    }

    // Overload >> operator for input
    istream& operator>>(istream& is, MedicalInsurance& mi) {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter coverage for "<<mi.type[i]<< ": ";
            is >> mi.coverage[i];
        }
        return is;
    }
