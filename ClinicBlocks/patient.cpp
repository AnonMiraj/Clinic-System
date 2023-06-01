#include "patient.h"


// Constructor
Patient::Patient()
  : Person(),
      password(""), insurance(0), emergencyContact("") {}


Patient::Patient(int id, const string& name, int age, const string& gender, const string& bloodType,
    const string& phoneNumber, const string& address, const string& password,
    const int& insurance, const string& emergencyContact)
    : Person(id, name, age, gender, bloodType, phoneNumber, address),
      password(password), insurance(insurance), emergencyContact(emergencyContact) {}

// Getters
string Patient::getPassword() const {
    return password;
}

int Patient::getInsurance() const {
    return insurance;
}

string Patient::getEmergencyContact() const {
    return emergencyContact;
}

// Setters

void Patient::setPassword(const string& password) {
    this->password = password;
}

void Patient::setInsurance(const int& insurance) {
    this->insurance = insurance;
}

void Patient::setEmergencyContact(const string& emergencyContact) {
    this->emergencyContact = emergencyContact;
}
void Patient::saveInfo(){
  ofstream  oupt;
  oupt.open("./data/inputPatient.txt",ios::app);
  if (oupt.is_open()) {
    oupt<<this->getId()<<endl;
    oupt<<this->getName()<<endl;
    oupt<<this->getAge()<<endl;
    oupt<<this->getGender()<<endl;
    oupt<<this->getBloodType()<<endl;
    oupt<<this->getPhoneNumber()<<endl;
    oupt<<this->getAddress()<<endl;
    oupt<<this->getEmergencyContact()<<endl;
    oupt<<this->getInsurance()<<endl;
  }
  oupt.close();
}


void Patient::editInfo() {

    cout << "Editing Patient's information:" << endl;
    Person::editInfo();  // Call the base class editInfo() function

    cout << "Emergency Contact: " << emergencyContact << endl;
    getline(cin, emergencyContact);
    cout << "Editing Medical Insurance information:\n";
    cout << "1. No Medical Insurance \n";
    cout << "2. Basic \n";
    cout << "3. Premium \n";
    cout << "4. Standard \n";
    cout << "Enter your choice (1-4): ";
    cin>>insurance;
    insurance--;
}


istream& operator>>(istream& is, Patient& patient) {
    is >> static_cast<Person&>(patient);  // Call the base class operator>>

    cout << "Enter patient's password: ";
    getline(is, patient.password);

    cout << "Enter patient's emergency contact: ";
    getline(is, patient.emergencyContact);

        // Display options
    cout << "Medical Insurance Options:\n";
    cout << "1. No Medical Insurance \n";
    cout << "2. Basic \n";
    cout << "3. Premium \n";
    cout << "4. Standard \n";
    cout << "Enter your choice (1-4): ";
    is>>patient.insurance;
    patient.insurance--;
    return is;
}

ostream& operator<<(ostream& os, const Patient& patient) {
    os << static_cast<const Person&>(patient);  // Call the base class operator<<

    os << "Insurance: ";
        switch (patient.insurance) {
        case 0:
            os << "No Medical Insurance" << endl;
            break;
        case 1:
            os << "Basic" << endl;
            break;
        case 2:
            os << "Premium" << endl;
            break;
        case 3:
            os << "Standard" << endl;
            break;
    }
    os << "Emergency Contact: " << patient.emergencyContact << endl;

    return os;
}

bool Patient::operator==(const Patient &p)
{
    return this->getId() == p.getId();
}
//bool Patient::operator==(const int id)
//{
//    return this->getId() == id;
//}
