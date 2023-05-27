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
        return (period/2<10 ? "0" :"" )+  to_string(period / 2) + ":00 - " + to_string(period/2) + ":30";

    return (period/2<10 ? "0" :"" )+ to_string(period / 2 - 1) + ":30 - " + (period == 48 ? "0" : to_string(period / 2)) + ":00";

}

void Appointment::setDate() 
{
    tm* t = localtime(&date);  
    char ch;

    cout << "Enter the date (dd/ mm/ yyyy) : ";
    cin >> t->tm_year >> ch >> t->tm_mon >> ch >> t->tm_mday;
    string period=getPeriod();

    t->tm_hour = stoi(period.substr(0,1));
    t->tm_min = stoi(period.substr(3,1));

    date = mktime(t);
}

time_t Appointment::getDate() const 
{
    return date;
}

void Appointment::setDoctor(const Doctor& d)
{
    *doctor = d;
}

Doctor* Appointment::getDoctor() const
{
    return doctor;
}

void Appointment::setPatient(const Patient& p)
{
    *patient = p;
}

Patient* Appointment::getPatient() const
{
    return patient;
}

/*void Appointment::setPrescription(const Prescription& p)
{
    *prescription = prescription;
}

Prescription* Appointment::getPrescription() const
{
    return prescription;
}*/



//operator overloading

istream& operator>> (istream& in, Appointment& a) // for files
{
    return in;
}

ostream& operator<< (ostream& out, const Appointment& a)
{
    out << setw(20) << a.patient->getName() << setw(20) << a.doctor->getName() <<setw(15) <<a.getDate() <<endl ;
out<<  a.getPrescription();
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
