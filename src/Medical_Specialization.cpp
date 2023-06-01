#include "Medical_Specialization.h"

    // Default constructor
    Medical_Specialization::Medical_Specialization()
    : id(-1),name(""){
    quantity=0;
    }
    Medical_Specialization::Medical_Specialization(int _id,string _name)
    : id(_id),name(_name){
    quantity=0;
    }

    // Getters
    int Medical_Specialization::getId() const{
        return id;
    }

    string Medical_Specialization::getName() const {
        return name;
    }
    int Medical_Specialization::getQuantity() const{
        return quantity;
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
    cin.ignore();
    getline(cin, name);
}
    void Medical_Specialization::saveInfo(){
  ofstream  oupt;
  oupt.open("./data/inputSpec.txt",ios::app);
  if (oupt.is_open()) {
    oupt<<this->getName()<<endl;
  }
  oupt.close();

}
    // Overloading << operator
    ostream& operator<<(ostream& out, const Medical_Specialization& specialization) {
        out << "ID: " << specialization.id << ", Name: " << specialization.name<< ", Quantity: " << specialization.quantity;
        return out;
    }

    // Overloading >> operator
    istream& operator>>(istream& in, Medical_Specialization& specialization) {
        getline(in, specialization.name);
        return in;
    }

    // Overloading == operator
    bool Medical_Specialization::operator==(const Medical_Specialization& other) {
        return id == other.id;
    }

    Medical_Specialization& Medical_Specialization::operator++() {
    quantity++;
    return *this;
    }
