
#include "prescription.h"
#include <iostream>

Prescription::Prescription() : medication("") , dosage("") , quantity(0)
{ }

Prescription::Prescription(const string& medication, const string& dosage, int quantity)
    : medication(medication), dosage(dosage), quantity(quantity) {
}

// Getter methods
string Prescription::getMedication() const {
    return medication;
}

string Prescription::getDosage() const {
    return dosage;
}

int Prescription::getQuantity() const {
    return quantity;
}

// Setter methods
void Prescription::setMedication(const string& medication) {
    this->medication = medication;
}

void Prescription::setDosage(const string& dosage) {
    this->dosage = dosage;
}

void Prescription::setQuantity(int quantity) {
    this->quantity = quantity;
}


istream& operator>>(istream& is, Prescription& prescription) {
    cout << "Enter medication: ";
    getline(is, prescription.medication);

    cout << "Enter dosage: ";
    getline(is, prescription.dosage);

    cout << "Enter quantity: ";
    is >> prescription.quantity;
    is.ignore();  // Ignore the newline character in the input buffer

    return is;
}

ostream& operator<<(ostream& os, const Prescription& prescription) {
    os << "Medication: " << prescription.medication << endl;
    os << "Dosage: " << prescription.dosage << endl;
    os << "Quantity: " << prescription.quantity << endl;

    return os;
}

