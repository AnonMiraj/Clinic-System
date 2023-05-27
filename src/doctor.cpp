#include "doctor.h"


// Constructor
Doctor::Doctor()
 : Person(),
      salary(0), profession(""), experience(0),
      ratingSum(0),appointmentCount(0), dateJoined(""), appointmentFee(0) {
  bool availableDays[8]={false};
  bool setAvailablePeroids[49]={false};
}


Doctor::Doctor(int id, const string& name, int age, const string& gender, const string& bloodType,
    const string& phoneNumber, const string& address, double salary, const string& profession,
    int experience, int ratingSum,int appointmentCount, const string& dateJoined, double appointmentFee)
    : Person(id, name, age, gender, bloodType, phoneNumber, address),
      salary(salary), profession(profession), experience(experience),
      ratingSum(ratingSum),appointmentCount(appointmentCount)
      ,dateJoined(dateJoined), appointmentFee(appointmentFee) {
  bool availableDays[8]={false};
  bool setAvailablePeroids[49]={false};

}

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
void Doctor::setAvailablePeroids(){

}
void Doctor::setDateJoined(const string& dateJoined) {
    this->dateJoined = dateJoined;
}

void Doctor::setAppointmentFee(double appointmentFee) {
    this->appointmentFee = appointmentFee;
}
void setIndexesToTrue(bool arr[], int size) {
    string input;
    getline(cin, input);

    istringstream iss(input);
    string token;
    while (iss >> token) {
        if (token.find('-') != string::npos) {
            // Range input detected, e.g., "1-3"
            istringstream rangeIss(token);
            string start, end;
            getline(rangeIss, start, '-');
            getline(rangeIss, end, '-');

            int startIndex = stoi(start);
            int endIndex = stoi(end);

            for (int i = startIndex; i <= endIndex; ++i) {
                if (i >= 0 && i < size) {
                    arr[i] = true;
                }
            }
        } else {
            // Single index input detected, e.g., "1"
            int index = stoi(token);
            if (index >= 0 && index < size) {
                arr[index] = true;
            }
        }
    }
}
void Doctor::readDays(){
    cout << "The weak here start with Saturday so 1 means Saturday\n";
    cout << "Enter the working days (\"1 2 3\", \"1-3\", \"1-2 5 6\" ): "<<endl;
    setIndexesToTrue(availableDays, 8);
}
void Doctor::printDayNames(bool arr[], int size)const {
    const string daysOfWeek[] = {
         "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"
    };

    for (int i = 1; i < size; ++i) {
        if (arr[i]) {
            cout << daysOfWeek[i-1] << " ";
        }
    }
    cout << endl;
}
void Doctor::readPeroids(){

    cout << "The day consist of 48 peroids ( 30 min ) the first one starts with 1 and equal 00:00 the next is 00:30 ,etc\n";
    cout << "Enter the working Peroids (\"1 2 3\", \"1-3\", \"1-2 5 6\" ): "<<endl;
    setIndexesToTrue(availablePeroids, 49);
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


    cout << "Date Joined: " << dateJoined << endl;
    getline(cin, dateJoined);

    cout << "Appointment Fee: " << appointmentFee << endl;
    string newAppointmentFee;
    getline(cin, newAppointmentFee);
    if (!newAppointmentFee.empty()) {
        appointmentFee = stod(newAppointmentFee);
    }
}
void Doctor::printInfo() const  {
    Person::printInfo();  // Call the base class printInfo() function

    cout << "Salary: " << salary << endl;
    cout << "Profession: " << profession << endl;
    cout << "Experience: " << experience << " years" << endl;
    cout << "Rating: " << ratingSum/appointmentCount << "/5" << endl;
    cout << "AvailableDays:";
    printDayNames(const availableDays, 8);
   //to do days worked and hour worked 
    cout << "Date Joined: " << dateJoined << endl;
    cout << "Appointment Fee: " << appointmentFee << endl;
}
