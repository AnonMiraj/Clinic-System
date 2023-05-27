#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "person.h"
#include "doctor.h"
#include "patient.h"
// #include "prescription.h"
using namespace std;

class Appointment
{
private:
    int id;
    int period;
    time_t date;
    Doctor *doctor;
    Patient *patient;
    // Prescription* prescription;

public:
    Appointment(int i);

    // setter and getter for each variable
    int getID() const;

    void setPeriod(const int &p);
    string getPeriod() const;

    void setDate();
    time_t getDate() const;

    void setDoctor(const Doctor &d);
    Doctor* getDoctor() const;

    void setPatient(const Patient &p);
    Patient* getPatient() const;

    // void setPrescription(const Prescription& p);
    // Prescription* getPrescription() const;

    // opertaor overloading
    friend istream &operator>>(istream &in, Appointment &a);
    friend ostream &operator<<(ostream &out, const Appointment &a);
    bool operator==(Appointment &a);
    bool operator>(Appointment &a);
};

#endif
