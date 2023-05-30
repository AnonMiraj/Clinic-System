#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <cstring>
#include <ctime>
#include <chrono>
#include <iostream>
#include <iomanip>
#include "person.h"
#include "doctor.h"
#include "patient.h"
#include "prescription.h"
#include "other.h"
using namespace std;

class Appointment
{
private:
    int id;
    int period;
    time_t date;
    Doctor* doctor;
    Patient* patient;
    Prescription* prescription;
    int statue;

public:
    Appointment(int i);
    Appointment();

    // setter and getter for each variable
    int getID() const;

    void setPeriod(const int &p);
    string getPeriod() const;

    void setDate(int);
    time_t getDate() const;

    void setDoctor(Doctor &d);
    Doctor* getDoctor() const;

    void setPatient(Patient &p);
    Patient* getPatient() const;

    void setPrescription(const Prescription& p);
    Prescription* getPrescription() const;
    
    void setStatue(int s);
    string getStatue() const;

    // opertaor overloading
    friend istream &operator>>(istream &in, Appointment &a);
    friend ostream &operator<<(ostream &out, const Appointment &a);
    bool operator==(const Appointment &a);
    bool operator>(const Appointment &a);
};

#endif
