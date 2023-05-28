#ifndef MEDICAL_SPECIALIZATION_H
#define MEDICAL_SPECIALIZATION_H


#include <iostream>
#include <string>
using namespace std;
class Medical_Specialization {
private:
    int id;
    string name;

public:
    // Default constructor
    Medical_Specialization() ;

    // Getters
    int getId() ;
    string getName() ;
    // Setter
    void setId(int _id) ;
    void setName(string _name) ;
    //other
    friend ostream& operator<<(ostream& out, const Medical_Specialization& specialization) ;
    friend istream& operator>>(istream& in, Medical_Specialization& specialization);
    bool operator==(const Medical_Specialization& other) ;
};
#endif // MEDICAL_SPECIALIZATION_H
