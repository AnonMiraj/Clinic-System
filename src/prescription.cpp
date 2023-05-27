
#include "prescription.h"
#include <iostream>


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

// Read and print functions
void Prescription::readInfo() {
    cout << "Enter medication: ";
    getline(cin, medication);

    cout << "Enter dosage: ";
    getline(cin, dosage);

    cout << "Enter quantity: ";
    cin >> quantity;
    cin.ignore();  // Ignore the newline character in the input buffer
}

void Prescription::printInfo() const {
    cout << "Medication: " << medication << endl;
    cout << "Dosage: " << dosage << endl;
    cout << "Quantity: " << quantity << endl;
}

