
#ifndef DOCTOR_H
#define DOCTOR_H

#include "person.h"
#include <sstream>
#include <string>
#include <iomanip>


class Doctor : public Person {
private:
    double salary;
    string profession;
    int experience;
    int ratingSum;
    int appointmentCount;
    bool availableDays[8];
    bool availablePeroids[49];
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
    const bool * getAvailablePeroids() const;
    string getDateJoined() const;
    double getAppointmentFee() const;

    // Setters
    void setSalary(double salary);
    void setProfession(const string& profession);
    void setExperience(int experience);
    void setRatingSum(int rating);
    void setAppointmentCount(int appointmentCount);
    void setAvailableDays();
    void setAvailablePeroids();
    void setDateJoined(const string& dateJoined);
    void setAppointmentFee(double appointmentFee);
  
    
    void setIndexesToTrue(bool *arr, int size);
    void readDays();
    void printDayNames(const bool *arr, int size, ostream& os)const;
    void readPeroids();
    void printPeriodTimes( const bool *arr, int size, ostream& os)const;
    virtual void editInfo();

    friend istream& operator>>(istream& is, Doctor& doctor);
    friend ostream& operator<<(ostream& os, const Doctor& doctor);
};


#endif  // DOCTOR_H

