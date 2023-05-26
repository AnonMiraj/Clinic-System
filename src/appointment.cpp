#include "appointment.h"

Appointment::Appointment(int i)
{
    id = i;
}

int Appointment::getID() const
{
    return id;
}

void Appointment::setPeriod(const int& p)
{
    period = p;
}

string Appointment::getPeriod() const
{
    if (period % 2 == 1)
        return to_string(period / 2) + ":00 - " + to_string(period/2) + ":30";

    return to_string(period / 2 - 1) + ":30 - " + (period == 48 ? "0" : to_string(period / 2)) + ":00";

}


void Appointment::setDate(const time_t& d) 
{
    tm* t = localtime(&d);  

    t->tm_hour = (getPeriod()[1] != ':') ? stoi(getPeriod()[0] + getPeriod()[1]) : stoi(getPeriod()[0]);
    t->tm_min = (getPeriod()[1] != ':') ? stoi(getPeriod()[2] + getPeriod()[3]) : stoi(getPeriod()[3] + getPeriod()[4]);
    t->tm_sec = 0;

    date = mktime(t);
}

string Appointment::getDate() const 
{
    //return date;
}

void Appointment::setDoctor(const Doctor& doctor)
{
    this->doctor = doctor;
}

Doctor Appointment::getDoctor() const
{
    return doctor;
}

void Appointment::setPatient(const Patient& patient)
{
    this->patient = patient;
}

Patient Appointment::getPatient() const
{
    return patient;
}

void Appointment::setPrescription(const Prescription& prescription)
{
    this->prescription = prescription;
}

Prescription Appointment::getPrescription() const
{
    return prescription;
}



//operator overloading

istream& operator>> (istream& in, Appointment& a) // for files
{
    return in;
}

ostream& operator<< (ostream& out, const Appointment& a)
{
    out << setw(20) << a.patient->getName() << setw(20) << a.doctor->getName() <<setw(15) <<a.getDate() <<endl <<a.getPrescription()->getinfo();
    return out;
}


bool Appointment::operator== (Appointment& a)
{
    return this->id == a.id;
}

bool Appointment::operator>(Appointment& a)
{
    return this->date > a.date;
}
