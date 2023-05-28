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

void Person::editInfo(){
    cout << "Name: " << name << endl;
    cout << "Enter new Name (You Can Press Enter to skip): ";
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
istream& operator>>(istream& is, Person& person) {
   
    is.ignore();
    cout << "Enter person's name: ";
    getline(is, person.name);

    cout << "Enter person's age: ";
    is >> person.age;
    is.ignore();  // Clear the input buffer

    cout << "Enter person's gender: ";
    getline(is, person.gender);

    cout << "Enter person's blood type: ";
    getline(is, person.bloodType);

    cout << "Enter person's phone number: ";
    getline(is, person.phoneNumber);

    cout << "Enter person's address: ";
    getline(is, person.address);

    return is;
}

ostream& operator<<(ostream& os, const Person& person) {
    os << "ID: " << person.id << endl;
    os << "Name: " << person.name << endl;
    os << "Age: " << person.age << endl;
    os << "Gender: " << person.gender << endl;
    os << "Blood Type: " << person.bloodType << endl;
    os << "Phone Number: " << person.phoneNumber << endl;
    os << "Address: " << person.address << endl;

    return os;
}
