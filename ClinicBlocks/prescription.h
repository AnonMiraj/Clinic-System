#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <string>
#include <fstream>

using namespace std;

class Prescription {
private:
    string medication;
    string dosage;
    int quantity;

public:
    Prescription();
    Prescription(const string& medication, const string& dosage, int quantity);

    // Getter methods
    string getMedication() const;
    string getDosage() const;
    int getQuantity() const;

    // Setter methods
    void setMedication(const string& medication);
    void setDosage(const string& dosage);
    void setQuantity(int quantity);

    // other
    void saveInfo();
    // Read and print functions
    friend istream& operator>>(istream& is, Prescription& prescription);
    friend ostream& operator<<(ostream& os, const Prescription& prescription);

};


#endif  // PRESCRIPTION_H

