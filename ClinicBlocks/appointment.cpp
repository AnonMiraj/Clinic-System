#include "appointment.h"

Appointment::Appointment(int i)
{
    id = i;
}

Appointment::Appointment()
{
    id = 0;
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

void Appointment::setDate(int wday)
{
    using namespace std;
    using namespace chrono;

    wday = (wday > 1? wday-2 : 6);

    time_t date = system_clock::to_time_t(system_clock::now());
    tm* t = localtime(&date);
    char ch;
    string y, m, d;
    bool IsNotValid;
    do
    {
        IsNotValid = false;
        try
        {
            cout << "Enter the date (yyyy/mm/dd): ";
            cin >> y >> ch >> m >> ch >> d;

            if ((y.size() > 4) || (m.size() > 2) || (d.size() > 2))
                throw "This date is invalid. :(\n";

            if (!IsValid(y, '1') || !IsValid(m, '2') || !IsValid(d, '3'))
                throw "\n";

            t->tm_year = stoi(y) - 1900;
            t->tm_mon = stoi(m) - 1;
            t->tm_mday = stoi(d);

            date = system_clock::to_time_t(system_clock::from_time_t(mktime(t)));
            cout<<endl <<t->tm_wday <<endl;

            if (t->tm_wday != wday)
                throw "This day is not a valid day for the doctor. :(\n";

            break;
        }
        catch (const char* str)
        {
            IsNotValid = true;
            cout << str;
        }
    } while (IsNotValid);

    string period = getPeriod();
    t->tm_hour = stoi(period.substr(0, 1));
    t->tm_min = stoi(period.substr(3, 1));

    date = system_clock::to_time_t(system_clock::from_time_t(mktime(t)));
}



time_t Appointment::getDate() const
{
    return date;
}

void Appointment::setDoctor(Doctor& d)
{
    doctor = &d;
}

Doctor* Appointment::getDoctor() const
{
    return doctor;
}

void Appointment::setPatient(Patient& p)
{
    patient = &p;
}


Patient* Appointment::getPatient() const
{
    return patient;
}

void Appointment::setPrescription(const Prescription& p)
{
    *prescription = p;
}

Prescription* Appointment::getPrescription() const
{
    return prescription;
}

void  Appointment::setStatue(int s)
{
    statue = s;
}

string  Appointment::getStatue() const
{
    if (statue == 1)
        return "BOOKED";
        
    return "ATTEND";
}


//operator overloading

istream& operator>> (istream& in, Appointment& a) // for files
{
    return in;
}

ostream& operator<< (ostream& out, const Appointment& a)
{
    out <<"Appointment ID : " <<a.getID() <<"\nDate : " <<printDate(a.getDate()) <<"\nPeriod : " <<a.getPeriod() <<"\nPatient :" << a.patient->getName() <<"\nDoctor : " << a.doctor->getName();
    //out <<  a.getPrescription();
    return out;
}



bool Appointment::operator== (const Appointment& a)
{
    return this->id == a.id;
}

bool Appointment::operator>(const Appointment& a)
{
    return this->date > a.date;
}