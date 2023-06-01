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

    /// setter
    void setPeriod(const int &p);
    void setDate(int);
    void setDate(string);
    void setDoctor(Doctor &d);
    void setPatient(Patient &p);
    void setStatue(int s);
    void setPrescription(const Prescription& p);

    /// getter
    string getDate() const;
    string getPeriod() const;
    string getStatue() const;
    int getPeriod_int() const;
    int getDate_wday() const;
    int getID() const;

    ///another

    void addPrescription(string medic,string dose,int quantity);
    void saveInfo();
    Doctor* getDoctor() const;
    Patient* getPatient() const;
    Prescription* getPrescription() const;

    /// opertaor overloading ^_^

    friend istream &operator>>(istream &in, Appointment &a);
    friend ostream &operator<<(ostream &out, const Appointment &a);
    bool operator==(const Appointment &a);
    bool operator>(const Appointment &a);
};

#endif
