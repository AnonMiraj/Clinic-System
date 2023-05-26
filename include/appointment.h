#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "Doctor.h"
#include "Patient.h"
#include "Prescription.h"
using namespace std;

class Appointment 
{
private:
    int           id;
    int           period;
    time_t        date;
    Doctor*       doctor;
    Patient*      patient;
    Prescription* prescription;

public:

    Appointment(int i);

    // setter and getter for each variable
    int getID() const;

    void setPeriod(const int& p);
    string getPeriod() const;

    void setDate(const time_t& d);
    string getDate() const;

    void setDoctor(const Doctor& doctor);
    Doctor getDoctor() const;

    void setPatient(const Patient& patient);
    Patient getPatient() const;

    void setPrescription(const Prescription& prescription);
    Prescription getPrescription() const;


    //opertaor overloading
    friend istream& operator>> (istream& in, Appointment& a);
    friend ostream& operator<< (ostream& out, const Appointment& a);
    bool operator== (Appointment& a);
    bool operator>(Appointment& a);
};

#endif
