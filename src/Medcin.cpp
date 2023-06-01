#include "Medcin.h"
#include <string>

// Default constructor
Medcin::Medcin():id(0),price(0),name("Unkown"),brand("Unkown")
{

}

Medcin::Medcin(int i, string n, string b,int p) :id(i),name(n),brand(b),price(p)
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


    string newValue;
    // Print the ID
    cout << "| ID: " << setw(30) << setfill(' ') << id << " |" << endl;
    cout << "ID: (you can press enter to skip)";
    getline(cin,newValue);
    if (newValue!=""){
    this->setId(stoi(newValue));
  }

    // Print the name
    cout << "| Name: " << setw(28) << setfill(' ') << name << " |" << endl;
    cout << "Name: ";
    getline(cin,newValue);
    if (newValue!=""){
    this->setName(newValue);
  }


    // Print the brand
    cout << "| Brand: " << setw(27) << setfill(' ') << brand << " |" << endl;
    cout << "Brand: "; 
    getline(cin,newValue);
    if (newValue!=""){
    this->setBrand(newValue);
  }


    // Print the price
    cout << "| Price: " << setw(27) << setfill(' ') << price << " |" << endl;
    cout << "Price: ";
    getline(cin,newValue);
    if (newValue!=""){
    this->setId(stoi(newValue));
  }




}



ostream& operator<<(ostream& os, Medcin& m) {

    // Print the ID
    os << "| ID: " << setw(30) << setfill(' ') << m.id << " |" << endl;

    // Print the name
    os << "| Name: " << setw(28) << setfill(' ') << m.name << " |" << endl;

    // Print the brand
    os << "| Brand: " << setw(27) << setfill(' ') << m.brand << " |" << endl;

    // Print the price
    os << "| Price: " << setw(27) << setfill(' ') << m.price << " |" << endl;

    return os;
}

// Overloaded extraction operator (>>) to input values into Medcin object
istream& operator>>(istream& is, Medcin& m) {


    cout << "Enter Name: ";
    getline(is, m.name);
    cout << "Enter Brand: ";
    getline(is, m.brand);
    cout << "Enter Price: ";
    cin >> m.price;

    return is;
}
