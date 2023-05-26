#include "doctor.h"


// Constructor
Doctor::Doctor(int id, const string& name, int age, const string& gender, const string& bloodType,
    const string& phoneNumber, const string& address, double salary, const string& profession,
    int experience, double rating, const string& dateJoined, double appointmentFee)
    : Person(id, name, age, gender, bloodType, phoneNumber, address),
      salary(salary), profession(profession), experience(experience),
      rating(rating), dateJoined(dateJoined), appointmentFee(appointmentFee) {}

// Getters
double Doctor::getSalary() const {
    return salary;
}

string Doctor::getProfession() const {
    return profession;
}

int Doctor::getExperience() const {
    return experience;
}

double Doctor::getRating() const {
    return rating;
}

string Doctor::getDateJoined() const {
    return dateJoined;
}

double Doctor::getAppointmentFee() const {
    return appointmentFee;
}

// Setters
void Doctor::setSalary(double salary) {
    this->salary = salary;
}

void Doctor::setProfession(const string& profession) {
    this->profession = profession;
}

void Doctor::setExperience(int experience) {
    this->experience = experience;
}

void Doctor::setRating(double rating) {
    this->rating = rating;
}

void Doctor::setDateJoined(const string& dateJoined) {
    this->dateJoined = dateJoined;
}

void Doctor::setAppointmentFee(double appointmentFee) {
    this->appointmentFee = appointmentFee;
}

