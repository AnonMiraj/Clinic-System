
#ifndef DOCTOR_H
#define DOCTOR_H

#include "person.h"
#include <string>

namespace std {

class Doctor : public Person {
private:
    double salary;
    string profession;
    int experience;
    double rating;
    string dateJoined;
    double appointmentFee;

public:
    // Constructor
    Doctor(int id, const string& name, int age, const string& gender, const string& bloodType,
        const string& phoneNumber, const string& address, double salary, const string& profession,
        int experience, double rating, const string& dateJoined, double appointmentFee);

    // Getters
    double getSalary() const;
    string getProfession() const;
    int getExperience() const;
    double getRating() const;
    string getDateJoined() const;
    double getAppointmentFee() const;

    // Setters
    void setSalary(double salary);
    void setProfession(const string& profession);
    void setExperience(int experience);
    void setRating(double rating);
    void setDateJoined(const string& dateJoined);
    void setAppointmentFee(double appointmentFee);
};

}  // namespace std

#endif  // DOCTOR_H

