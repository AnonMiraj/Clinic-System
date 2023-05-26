#include "person.h"


// Constructor
Person::Person()
: id(0), name(""), age(0), gender(""), bloodType(""),
      phoneNumber(""), address("") {}

Person::Person(int id, const string& name, int age, const string& gender, const string& bloodType,
    const string& phoneNumber, const string& address)
    : id(id), name(name), age(age), gender(gender), bloodType(bloodType),
      phoneNumber(phoneNumber), address(address) {}

// Getters
int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

string Person::getGender() const {
    return gender;
}

string Person::getBloodType() const {
    return bloodType;
}

string Person::getPhoneNumber() const {
    return phoneNumber;
}

string Person::getAddress() const {
    return address;
}

// Setters
void Person::setId(int id) {
    this->id = id;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setGender(const string& gender) {
    this->gender = gender;
}

void Person::setBloodType(const string& bloodType) {
    this->bloodType = bloodType;
}

void Person::setPhoneNumber(const string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Person::setAddress(const string& address) {
    this->address = address;
}
void Person::readInfo() {
    cout << "Enter person's ID: ";
    cin >> id;
    cin.ignore();  // Clear the input buffer

    cout << "Enter person's name: ";
    getline(cin, name);

    cout << "Enter person's age: ";
    cin >> age;
    cin.ignore();  // Clear the input buffer

    cout << "Enter person's gender: ";
    getline(cin, gender);

    cout << "Enter person's blood type: ";
    getline(cin, bloodType);

    cout << "Enter person's phone number: ";
    getline(cin, phoneNumber);

    cout << "Enter person's address: ";
    getline(cin, address);
}
void Person::editInfo(){
  


    cout << "ID: " << id << endl;
    cout << "Enter new ID (Press Enter to skip): ";
    string newId;
    getline(cin, newId);
    if (!newId.empty()) {
        id = stoi(newId);
    }

    cout << "Name: " << name << endl;
    getline(cin, name);

    cout << "Age: " << age << endl;
    string newAge;
    getline(cin, newAge);
    if (!newAge.empty()) {
        age = stoi(newAge);
    }

    cout << "Gender: " << gender << endl;
    getline(cin, gender);

    cout << "Blood Type: " << bloodType << endl;
    getline(cin, bloodType);

    cout << "Phone Number: " << phoneNumber << endl;
    getline(cin, phoneNumber);

    cout << "Address: " << address << endl;
    getline(cin, address);
}

void Person::printInfo() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Blood Type: " << bloodType << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Address: " << address << endl;
}
