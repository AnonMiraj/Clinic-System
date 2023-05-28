
#ifndef DOCTOR_H
#define DOCTOR_H

#include "person.h"
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>


class Doctor : public Person {
private:
    int salary;
    string profession;
    int experience;
    int ratingSum;
    int appointmentCount;
    bool availableDays[8];
    bool availablePeroids[49];
    string dateJoined;
    int appointmentFee;

public:
    // Constructor
    Doctor();
    Doctor(int id, const string& name, int age, const string& gender, const string& bloodType,
        const string& phoneNumber, const string& address, int salary, const string& profession,
        int experience, int ratingSum,int appointmentCount, const string& dateJoined, int appointmentFee);

    // Getters
    int getSalary() const;
    string getProfession() const;
    int getExperience() const;
    int getRatingSum() const;
    int getAppointmentCount() const;
    bool * getAvailableDays() ;
    bool * getAvailablePeroids();
    string getDateJoined() const;
    int getAppointmentFee() const;

    // Setters
    void setSalary(int salary);
    void setProfession(const string& profession);
    void setExperience(int experience);
    void setRatingSum(int rating);
    void setAppointmentCount(int appointmentCount);
    void setAvailableDays();
    void setAvailablePeroids();
    void setDateJoined(const string& dateJoined);
    void setAppointmentFee(int appointmentFee);
  
    

    void readDays();
    void readPeroids();
    void saveInfo();
    virtual void editInfo();

    friend istream& operator>>(istream& is, Doctor& doctor);
    friend ostream& operator<<(ostream& os, const Doctor& doctor);
};


#endif  // DOCTOR_H

