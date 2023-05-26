
#ifndef DOCTOR_H
#define DOCTOR_H

#include "person.h"
#include <string>


class Doctor : public Person {
private:
    double salary;
    string profession;
    int experience;
    int ratingSum;
    int appointmentCount;
    bool availableDays[8];
    bool availableHours[49];
    string dateJoined;
    double appointmentFee;

public:
    // Constructor
    Doctor();
    Doctor(int id, const string& name, int age, const string& gender, const string& bloodType,
        const string& phoneNumber, const string& address, double salary, const string& profession,
        int experience, int ratingSum,int appointmentCount, const string& dateJoined, double appointmentFee);

    // Getters
    double getSalary() const;
    string getProfession() const;
    int getExperience() const;
    int getRatingSum() const;
    int getAppointmentCount() const;
    const bool * getAvailableDays() const;
    const bool * getAvailableHours() const;
    string getDateJoined() const;
    double getAppointmentFee() const;

    // Setters
    void setSalary(double salary);
    void setProfession(const string& profession);
    void setExperience(int experience);
    void setRatingSum(int rating);
    void setAppointmentCount(int appointmentCount);
    void setAvailableDays();
    void setAvailableHours();
    void setDateJoined(const string& dateJoined);
    void setAppointmentFee(double appointmentFee);
};


#endif  // DOCTOR_H

