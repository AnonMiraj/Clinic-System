#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <string>

using namespace std;

class Prescription {
private:
    string medication;
    string dosage;
    int quantity;

public:
    Prescription(const string& medication, const string& dosage, int quantity);

    // Getter methods
    string getMedication() const;
    string getDosage() const;
    int getQuantity() const;

    // Setter methods
    void setMedication(const string& medication);
    void setDosage(const string& dosage);
    void setQuantity(int quantity);

    // Read and print functions
    void readInfo();
    void printInfo() const;
};


#endif  // PRESCRIPTION_H

