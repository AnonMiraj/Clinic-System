#include "Medcin.h"

// Default constructor
Medcin::Medcin() : id(0) 
{

}

// Parameterized constructor
//Medcin::Medcin();

int Medcin::getId() const {
    return id;
}

std::string Medcin::getName() const {
    return name;
}

std::string Medcin::getBrand() const {
    return brand;
}

std::string Medcin::getAvailability() const {
    return availability;
}

std::string Medcin::getWarnings() const {
    return warnings;
}

// Setters
void Medcin::setId(int id) {
    this->id = id;
}

void Medcin::setName(const std::string& name) {
    this->name = name;
}

void Medcin::setBrand(const std::string& brand) {
    this->brand = brand;
}

void Medcin::setAvailability(const std::string& availability) {
    this->availability = availability;
}

void Medcin::setWarnings(const std::string& warnings) {
    this->warnings = warnings;
}