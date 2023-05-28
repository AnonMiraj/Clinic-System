#include "doctor.h"
#include <string>


// Constructor
Doctor::Doctor()
 : Person(),
      salary(0), profession(""), experience(0),
      ratingSum(0),appointmentCount(0), dateJoined(""), appointmentFee(0) {
  bool availableDays[8]={false};
  bool setAvailablePeroids[49]={false};
}


Doctor::Doctor(int id, const string& name, int age, const string& gender, const string& bloodType,
    const string& phoneNumber, const string& address, int salary, const string& profession,
    int experience, int ratingSum,int appointmentCount, const string& dateJoined, int appointmentFee)
    : Person(id, name, age, gender, bloodType, phoneNumber, address),
      salary(salary), profession(profession), experience(experience),
      ratingSum(ratingSum),appointmentCount(appointmentCount)
      ,dateJoined(dateJoined), appointmentFee(appointmentFee) {
  bool availableDays[8]={false};
  bool setAvailablePeroids[49]={false};

}

// Getters
int Doctor::getSalary() const {
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
bool* Doctor::getAvailableDays(){
  return  availableDays;
}
bool* Doctor::getAvailablePeroids(){
  return availablePeroids;
}

string Doctor::getDateJoined() const {
    return dateJoined;
}

int Doctor::getAppointmentFee() const {
    return appointmentFee;
}

// Setters
void Doctor::setSalary(int salary) {
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
void Doctor::setAvailablePeroids(){

}
void Doctor::setDateJoined(const string& dateJoined) {
    this->dateJoined = dateJoined;
}

void Doctor::setAppointmentFee(int appointmentFee) {
    this->appointmentFee = appointmentFee;
}

void Doctor::readDays(){
    cout << "The weak here start with Saturday so 1 means Saturday\n";
    cout << "Enter the working days (\"1 2 3\", \"1-3\", \"1-2 5 6\" ): "<<endl;
    setIndexesToTrue(availableDays, 8);
}
void Doctor::readPeroids(){

    cout << "The day consist of 48 peroids ( 30 min ) the first one starts with 1 and equal 00:00 the next is 00:30 ,etc\n";
    cout << "Enter the working Peroids (\"1 2 3\", \"1-3\", \"1-2 5 6\" ): "<<endl;
    setIndexesToTrue(availablePeroids, 49);
}
void Doctor::saveInfo(){
  ofstream  oupt;
  oupt.open("inputDoctors.txt",ios::app);
  if (oupt.is_open()) {
    oupt<<this->getId()<<endl;  
    oupt<<this->getName()<<endl;
    oupt<<this->getAge()<<endl;
    oupt<<this->getGender()<<endl;
    oupt<<this->getBloodType()<<endl;
    oupt<<this->getPhoneNumber()<<endl;
    oupt<<this->getAddress()<<endl;
    oupt<<this->getSalary()<<endl;
    oupt<<this->getProfession()<<endl;
    for (int i = 1; i<8;i++)
    {
      if(availableDays[i])
        oupt<<i<<" ";
    }
    oupt<<endl;
    for (int i = 1; i<49;i++)
    {
      if(availablePeroids[i])
        oupt<<i<<" ";
    }
    oupt<<endl;
    oupt<<this->getDateJoined()<<endl;
    oupt<<this->getAppointmentFee()<<endl;

  }
  oupt.close();
}


void Doctor::editInfo() {

    cout << "Editing doctor's information:" << endl;
    Person::editInfo();  // Call the base class editInfo() function

    cout << "Salary: " << salary << endl;
    string newSalary;
    getline(cin, newSalary);
    if (!newSalary.empty()) {
        salary = stod(newSalary);
    }

    cout << "Profession: " << profession << endl;
    getline(cin, profession);

    cout << "Experience: " << experience << " years" << endl;
    string newExperience;
    getline(cin, newExperience);
    if (!newExperience.empty()) {
        experience = stoi(newExperience);
    }
    string yes; 
    cout << "Available Days:";
    printDayNames(availableDays, 8,cout);
    cout << "input y to edit otherwise press enter to skip" << endl;
    getline(cin,yes);
    if (yes == "y"||yes == "Y")
        readDays();  
    cout << "Available Hours: ";
    printPeriodTimes(availablePeroids,49,cout);
    cout << "input y to edit otherwise press enter to skip" << endl;
    getline(cin,yes);
    if (yes == "y"||yes == "Y")
        readPeroids();

    cout << "Date Joined: " << dateJoined << endl;
    getline(cin, dateJoined);

    cout << "Appointment Fee: " << appointmentFee << endl;
    string newAppointmentFee;
    getline(cin, newAppointmentFee);
    if (!newAppointmentFee.empty()) {
        appointmentFee = stod(newAppointmentFee);
    }
}

istream& operator>>(istream& is, Doctor& doctor) {
    is >> static_cast<Person&>(doctor);  // Call the base class operator>>

    cout << "Enter doctor's salary: ";
    is >> doctor.salary;
    is.ignore();  // Clear the input buffer

    cout << "Enter doctor's profession: ";
    getline(is, doctor.profession);

    cout << "Enter doctor's experience: ";
    is >> doctor.experience;
    is.ignore();  // Clear the input buffer
    doctor.readDays();
    doctor.readPeroids();

    cout << "Enter doctor's date joined (YYYY-MM-DD): ";
    getline(is, doctor.dateJoined);

    cout << "Enter doctor's appointment fee: ";
    is >> doctor.appointmentFee;
    is.ignore();  // Clear the input buffer

    return is;
}

ostream& operator<<(ostream& os, const Doctor& doctor) {
    os << static_cast<const Person&>(doctor);  // Call the base class operator<<

    os << "Salary: " << doctor.salary << endl;
    os << "Profession: " << doctor.profession << endl;
    os << "Experience: " << doctor.experience << " years" << endl;
    // os << "Rating: " << doctor.ratingSum / doctor.appointmentCount << "/5" << endl;
    os << "Available Days: ";
    printDayNames(doctor.availableDays, 8, os);
    os << "Available Hours: ";
    printPeriodTimes(doctor.availablePeroids , 49, os);
    os << "Date Joined: " << doctor.dateJoined << endl;
    os << "Appointment Fee: " << doctor.appointmentFee << endl;

    return os;
}