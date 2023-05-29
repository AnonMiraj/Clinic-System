
#ifndef DOCTOR_H
#define DOCTOR_H

#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>
#include "person.h"
#include "Medical_Specialization.h"


class Doctor : public Person {
private:
    Medical_Specialization * specialization;
    int salary;
    int experience;
    int ratingSum;
    int appointmentCount;
    bool archived;
    bool availableDays[8];
    bool availablePeroids[49];
    string dateJoined;
    int appointmentFee;

public:
    // Constructor
    Doctor();
    Doctor(int id, const string& name, int age, const string& gender, const string& bloodType,
        const string& phoneNumber, const string& address, int salary,
        int experience, int ratingSum,int appointmentCount,bool archived, const string& dateJoined, int appointmentFee);

    // Getters
    int getSalary() const;
    int getSpecializationId() const;
    int getExperience() const;
    int getRatingSum() const;
    int getAppointmentCount() const;
    bool * getAvailableDays() ;
    bool * getAvailablePeroids();
    bool getAracived() const;
    string getDateJoined() const;
    int getAppointmentFee() const;

    // Setters
    void setSalary(int salary);
    void setSpecialization( Medical_Specialization* specialization);
    void setExperience(int experience);
    void setRatingSum(int rating);
    void setAppointmentCount(int appointmentCount);
    void setAvailableDays();
    void setAvailablePeroids();
    void setAracived();
    void setDateJoined(const string& dateJoined);
    void setAppointmentFee(int appointmentFee);


    void readDays();
    void readPeroids();
    void saveInfo();
    virtual void editInfo();

    friend istream& operator>>(istream& is, Doctor& doctor);
    friend ostream& operator<<(ostream& os, const Doctor& doctor);
    bool operator==(const Doctor &d);

};


#endif  // DOCTOR_H

