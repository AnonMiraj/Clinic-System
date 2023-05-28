#include "patient.h"


// Constructor
Patient::Patient()
  : Person(),
      password(""), insurance(""), emergencyContact("") {}


Patient::Patient(int id, const string& name, int age, const string& gender, const string& bloodType,
    const string& phoneNumber, const string& address,const string& notes, const string& password,
    const string& insurance, const string& emergencyContact)
    : Person(id, name, age, gender, bloodType, phoneNumber, address),notes(notes),
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
void Patient::saveInfo(){
  ofstream  oupt;
  oupt.open("inputPatient.txt",ios::app);
  if (oupt.is_open()) {
    oupt<<this->getId()<<endl;  
    oupt<<this->getName()<<endl;
    oupt<<this->getAge()<<endl;
    oupt<<this->getGender()<<endl;
    oupt<<this->getBloodType()<<endl;
    oupt<<this->getPhoneNumber()<<endl;
    oupt<<this->getAddress()<<endl;
    oupt<<this->getNotes()<<endl;
    oupt<<this->getEmergencyContact()<<endl;

  }
  oupt.close();
}


void Patient::editInfo() {

    cout << "Editing Patient's information:" << endl;
    Person::editInfo();  // Call the base class editInfo() function

    cout << "Notes: " << notes << endl;
    getline(cin, notes);


    // cout << "Insurance: " << insurance << endl;
    // getline(cin, insurance);

    cout << "Emergency Contact: " << emergencyContact << endl;
    getline(cin, emergencyContact);
}


istream& operator>>(istream& is, Patient& patient) {
    is >> static_cast<Person&>(patient);  // Call the base class operator>>

    cout << "Enter patient's password: ";
    getline(is, patient.password);

    cout << "Enter patient's emergency contact: ";
    getline(is, patient.emergencyContact);

    return is;
}

ostream& operator<<(ostream& os, const Patient& patient) {
    os << static_cast<const Person&>(patient);  // Call the base class operator<<

    if (!patient.notes.empty()) {
        os << "Notes: " << patient.notes << endl;
    }

    // TODO: Print insurance information
    // os << "Insurance: " << patient.insurance << endl;

    os << "Emergency Contact: " << patient.emergencyContact << endl;

    return os;
}