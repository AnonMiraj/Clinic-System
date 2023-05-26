#include "doctor.h"


// Constructor
Doctor::Doctor()
 : Person(),
      salary(0), profession(""), experience(0),
      ratingSum(0),appointmentCount(0), dateJoined(""), appointmentFee(0) {}


Doctor::Doctor(int id, const string& name, int age, const string& gender, const string& bloodType,
    const string& phoneNumber, const string& address, double salary, const string& profession,
    int experience, int ratingSum,int appointmentCount, const string& dateJoined, double appointmentFee)
    : Person(id, name, age, gender, bloodType, phoneNumber, address),
      salary(salary), profession(profession), experience(experience),
      ratingSum(ratingSum),appointmentCount(appointmentCount)
      ,dateJoined(dateJoined), appointmentFee(appointmentFee) {}

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

int Doctor::getRatingSum() const {
    return ratingSum;
}
int Doctor::getAppointmentCount()const{
  return appointmentCount;
}
const bool* Doctor::getAvailableDays()const{
  return  availableDays;
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

void Doctor::setRatingSum(int ratingSum) {
    this->ratingSum = ratingSum;
}
void Doctor::setAppointmentCount(int appointmentCount){
    this->appointmentCount=appointmentCount;
}
void Doctor::setAvailableDays(){

}
void Doctor::setAvailableHours(){

}
void Doctor::setDateJoined(const string& dateJoined) {
    this->dateJoined = dateJoined;
}

void Doctor::setAppointmentFee(double appointmentFee) {
    this->appointmentFee = appointmentFee;
}

void Doctor::readInfo() {
    Person::readInfo();  // Call the base class readInfo() function

    cout << "Enter doctor's salary: ";
    cin >> salary;
    cin.ignore();  // Clear the input buffer

    cout << "Enter doctor's profession: ";
    getline(cin, profession);

    cout << "Enter doctor's experience: ";
    cin >> experience;

    cin.ignore();  // Clear the input buffer

    cout << "Enter doctor's date joined(YYYY-MM-DD): ";
    getline(cin, dateJoined);

    cout << "Enter doctor's appointment fee: ";
    cin >> appointmentFee;
    cin.ignore();  // Clear the input buffer
}

void Doctor::printInfo() const {
    Person::printInfo();  // Call the base class printInfo() function

    cout << "Salary: " << salary << endl;
    cout << "Profession: " << profession << endl;
    cout << "Experience: " << experience << " years" << endl;
    cout << "Rating: " << ratingSum/appointmentCount << "/5" << endl;
   //to do days worked and hour worked 
    cout << "Date Joined: " << dateJoined << endl;
    cout << "Appointment Fee: " << appointmentFee << endl;
}
