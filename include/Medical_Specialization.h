#ifndef MEDICAL_SPECIALIZATION_H
#define MEDICAL_SPECIALIZATION_H


#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Medical_Specialization {
private:
    int id;
    string name;
    int quantity;

public:
    // Default constructor
    Medical_Specialization() ;
    Medical_Specialization(int _id,string _name);

    // Getters
    int getId() const;
    string getName()const ;
    int getQuantity() const;
    // Setter
    void setId(int _id) ;
    void setName(string _name) ;
    void setQuantity(int _quantity) ;
    // operator overloading
    friend ostream& operator<<(ostream& out, const Medical_Specialization& specialization) ;
    friend istream& operator>>(istream& in, Medical_Specialization& specialization);
    Medical_Specialization& operator++() ;
    bool operator==(const Medical_Specialization& other) ;

    //other
    void editInfo();
    void saveInfo();
};
#endif // MEDICAL_SPECIALIZATION_H
