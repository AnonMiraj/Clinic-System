#include "Medcin.h"

// Default constructor
Medcin::Medcin():id(0),price(0),name("Unkown"),brand("Unkown")
{

}

// Parameterized constructor
//Medcin::Medcin();

int Medcin::getPrice() const
{
    return price;
}

int Medcin::getId() const {
    return id;
}

std::string Medcin::getName() const {
    return name;
}

std::string Medcin::getBrand() const {
    return brand;
}

void Medcin::setPrice(const int& price)
{
    this->price = price;
}

// Setters
void Medcin::setId(int id) {
    this->id = id;
}

void Medcin::setName(const string& name) {
    this->name = name;
}

void Medcin::setBrand(const string& brand) {
    this->brand = brand;
}

void Medcin::Edit()
{
    cout << "Edit Medcin:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Brand" << endl;
    cout << "3. id" << endl;
    cout << "4. price" << endl;
    cout << "Enter your choice (1-4): ";

    int choice;
    cin >> choice;

    string newValue;


    switch (choice) {
    case 1:
        cout << "Enter new value: ";
        cin.ignore(); // Ignore the newline character from previous input
        getline(cin, newValue);
        setName(newValue);
        break;
    case 2:
        cout << "Enter new value: ";
        cin.ignore(); // Ignore the newline character from previous input
        getline(cin, newValue);
        setBrand(newValue);
        break;
    case 3:
        int i;
        cin >> i;
        setId(i);
        break;
    case 4:
        int p;
        cin >> p;
        setPrice(p);
        break;
    default:
        cout << "Invalid choice. No changes made." << endl;
        return;
    }

    cout << "Medcin updated successfully." << endl;
}

ostream& operator<<(ostream& os, Medcin& m) {
    os << "ID: " << m.id << endl;
    os << "Name: " << m.name << endl;
    os << "Brand: " << m.brand << endl;
    os << "Price: " << m.price << endl;
    return os;
}

// Overloaded extraction operator (>>) to input values into Medcin object
istream& operator>>(istream& is, Medcin& m) {
    cout << "Enter ID: ";
    is >> m.id;
    cout << "Enter Name: ";
    is >> m.name;
    cout << "Enter Brand: ";
    is >> m.brand;
    cout << "Enter Price: ";
    cin >> m.price;
    return is;
}