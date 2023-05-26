#include "patient.h"


// Constructor
Patient::Patient()
  : Person(),
      password(""), insurance(""), emergencyContact("") {}


Patient::Patient(int id, const string& name, int age, const string& gender, const string& bloodType,
    const string& phoneNumber, const string& address, const string& password,
    const string& insurance, const string& emergencyContact)
    : Person(id, name, age, gender, bloodType, phoneNumber, address),
      password(password), insurance(insurance), emergencyContact(emergencyContact) {}

// Getters
string Patient::getNotes() const {
    return notes;
}

string Patient::getPassword() const {
    return password;
}

string Patient::getInsurance() const {
    return insurance;
}

string Patient::getEmergencyContact() const {
    return emergencyContact;
}

// Setters
void Patient::setNotes(const string& notes) {
    this->notes = notes;
}

void Patient::setPassword(const string& password) {
    this->password = password;
}

void Patient::setInsurance(const string& insurance) {
    this->insurance = insurance;
}

void Patient::setEmergencyContact(const string& emergencyContact) {
    this->emergencyContact = emergencyContact;
}

void Patient::readInfo() {
    Person::readInfo();  // Call the base class readInfo() function

    cout << "Enter patient's password: ";
    getline(cin, password);

    cout << "Enter patient's insurance: ";
// to do
    cout << "Enter patient's emergency contact: ";
    getline(cin, emergencyContact);
}

void Patient::printInfo() const {
    Person::printInfo();  // Call the base class printInfo() function

    if (notes!="")
      cout << "Notes: " << notes << endl;

    // TODO cout << "Insurance: " << insurance << endl;

    cout << "Emergency Contact: " << emergencyContact << endl;
}
