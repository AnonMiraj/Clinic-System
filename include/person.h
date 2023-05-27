#ifndef PERSON_H
#define PERSON_H

#include "other.cpp"
#include <string>
#include <iostream>
using namespace std ;

class Person {
private:
    int id;
    string name;
    int age;
    string gender;
    string bloodType;
    string phoneNumber;
    string address;

public:
    // Constructor
    Person();
    Person(int id, const string& name, int age, const string& gender, const string& bloodType,
        const string& phoneNumber, const string& address);

    // Getters
    int getId() const;
    string getName() const;
    int getAge() const;
    string getGender() const;
    string getBloodType() const;
    string getPhoneNumber() const;
    string getAddress() const;

    // Setters
    void setId(int id);
    void setName(const string& name);
    void setAge(int age);
    void setGender(const string& gender);
    void setBloodType(const string& bloodType);
    void setPhoneNumber(const string& phoneNumber);
    void setAddress(const string& address);



    virtual void editInfo()=0;
  
    friend istream& operator>>(istream& is, Person& person);
    friend ostream& operator<<(ostream& os, const Person& person);
};


#endif  // PERSON_H

