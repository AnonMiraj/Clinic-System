#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <cstring>
#include <string>
#include <string.h>
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
    string date;
    Doctor* doctor;
    Patient* patient;
    Prescription* prescription;
    int statue;
    int prescriptionCount;
    int prescriptionSize;


public:
    Appointment(int i);
    Appointment(int i,int period,string date,int statue);
    Appointment();

    // setter and getter for each variable
    int getID() const;

    void setPeriod(const int &p);
    string getPeriod() const;
    int getPeriod_int() const;

    void setDate(int);
    string getDate() const;
    int getDate_wday() const;

    void setDoctor(Doctor &d);
    Doctor* getDoctor() const;

    void setPatient(Patient &p);
    Patient* getPatient() const;

    void setPrescription(const Prescription& p);
    Prescription* getPrescription() const;

    void setStatue(int s);
    string getStatue() const;

    void addPrescription(string medic,string dose,int quantity);
    void saveInfo();

    // opertaor overloading
    friend istream &operator>>(istream &in, Appointment &a);
    friend ostream &operator<<(ostream &out, const Appointment &a);
    bool operator==(const Appointment &a);
    bool operator>(const Appointment &a);
};

#endif
