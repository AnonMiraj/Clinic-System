#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"
#include <string>
#include <fstream>

using namespace std; 

class Patient : public Person {
private:
    string notes;
    string password;
    string insurance;
    string emergencyContact;

public:
    // Constructor
    Patient();
    Patient(int id, const string& name, int age, const string& gender, const string& bloodType,
        const string& phoneNumber, const string& address,const string& notes, const string& password,
        const string& insurance, const string& emergencyContact);

    // Getters
    string getNotes() const;
    string getPassword() const;
    string getInsurance() const;
    string getEmergencyContact() const;

    // Setters
    void setNotes(const string& notes);
    void setPassword(const string& password);
    void setInsurance(const string& insurance);
    void setEmergencyContact(const string& emergencyContact);

    void saveInfo();
    virtual void editInfo();
    friend istream& operator>>(istream& is, Patient& patient);
    friend ostream& operator<<(ostream& os, const Patient& patient);
};


#endif  // PATIENT_H