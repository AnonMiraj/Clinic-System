#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"
#include <string>

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
        const string& phoneNumber, const string& address, const string& password,
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


    virtual void readInfo();
    virtual void editInfo();
    virtual void printInfo() const;
};


#endif  // PATIENT_H
