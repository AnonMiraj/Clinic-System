#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"
#include "other.h"
#include <string>
#include <fstream>

using namespace std;

class Patient : public Person {
private:
    string notes;
    string password;
    string emergencyContact;
    int insurance;

public:
    // Constructor
    Patient();
    Patient(int id, const string& name, int age, const string& gender, const string& bloodType,
        const string& phoneNumber, const string& address, const string& password,
        const int& insurance, const string& emergencyContact);

    // Getters
    string getPassword() const;
    string getEmergencyContact() const;
    int getInsurance() const;

    // Setters
    void setPassword(const string& password);
    void setEmergencyContact(const string& emergencyContact);
    void setInsurance(const int& insurance);

    void saveInfo();
    virtual void editInfo();
    friend istream& operator>>(istream& is, Patient& patient);
    friend ostream& operator<<(ostream& os, const Patient& patient);
    bool operator==(const Patient &p);
    bool operator==(const int id);
};


#endif  // PATIENT_H
