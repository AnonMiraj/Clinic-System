#include "person.h"


// Constructor
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

