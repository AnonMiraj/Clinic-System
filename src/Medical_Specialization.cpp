#include "Medical_Specialization.h"

    // Default constructor
    Medical_Specialization::Medical_Specialization() {
        id = 0;
        name = "";
    }

    // Getters
    int Medical_Specialization::getId() {
        return id;
    }

    string Medical_Specialization::getName() {
        return name;
    }

    // Setters
    void Medical_Specialization::setId(int _id) {
        id = _id;
    }

    void Medical_Specialization::setName(string _name) {
        name = _name;
    }

    void Medical_Specialization::editInfo() {

    cout << "Current Name: " << name << endl;
    cout << "Editing Medical Specialization's Name (You Can Press Enter to skip):" << endl;
    getline(cin, name);
}
    // Overloading << operator
    ostream& operator<<(ostream& out, const Medical_Specialization& specialization) {
        out << "ID: " << specialization.id << ", Name: " << specialization.name;
        return out;
    }

    // Overloading >> operator
    istream& operator>>(istream& in, Medical_Specialization& specialization) {
        cout << "Enter Name: ";
        getline(in, specialization.name);
        return in;
    }

    // Overloading == operator
    bool Medical_Specialization::operator==(const Medical_Specialization& other) {
        return (id == other.id && name == other.name);
    }

