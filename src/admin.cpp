#include "admin.h"
#include "doctor.h"
#include "other.h"
#include "patient.h"
#include "person.h"
#include <fstream>
#include <string>


Admin::Admin() {
    patients = new Patient[10];  // Initial capacity for 10 patients
    doctors = new Doctor[10];  // Initial capacity for 10 doctors
    archivedDoctors = new Doctor[10]; // Initial capacity for 10 doctors
    patientCount = 0;
    doctorCount = 0;
    archiveCount = 0;
    maxPatients = 10;
    maxDoctors = 10;
    maxArchive = 10;
}

Admin::~Admin() {
    delete[] patients;
    delete[] doctors;
    delete[] archivedDoctors;
}

void Admin::addPatient() {
    if (patientCount == maxPatients) {
        // Resize the array if it's full
        Patient* newPatients = new Patient[maxPatients * 2];
        for (int i = 0; i < patientCount; i++) {
            newPatients[i] = patients[i];
        }
        delete[] patients;
        patients = newPatients;
        maxPatients *= 2;
    }

    patients[patientCount] =  Patient();
    cin>>patients[patientCount]; 
    patients[patientCount].setId(patientCount+1);
    patientCount++;
}
void Admin::editPatient(){
  int id;
  cout<<"Enter patient Id: ";
  cin>>id;
  patients[id-1].editInfo();
}

void Admin::addDoctor() {
    if (doctorCount == maxDoctors) {
        // Resize the array if it's full
        Doctor* newDoctors = new Doctor[maxDoctors * 2];
        for (int i = 0; i < doctorCount; i++) {
            newDoctors[i] = doctors[i];
        }
        delete[] doctors;
        doctors = newDoctors;
        maxDoctors *= 2;
    }
    
    doctors[doctorCount] = Doctor();
    cin>>doctors[doctorCount];
    doctors[doctorCount].setId(doctorCount+1);
    doctorCount++;
}
void Admin::editDoctor(){
  int id;
  cout<<"Enter doctors Id: ";
  cin>>id;
  doctors[id-1].editInfo();
}
void Admin::loadDoctor(){
  int id,age,expYears,salary,fee;
  string name,gender,blood,phone,address,profession,avalDay,avalHour,date;
  ifstream inp;
  inp.open("inputDoctors.txt");
  if(inp.is_open())
  while (inp>>id) {
  inp.ignore();
  getline(inp,name);
  inp>>age;
  inp.ignore();
  getline(inp,gender);
  getline(inp,blood);
  getline(inp,phone);
  getline(inp,address);
  inp>>salary;
  inp.ignore();
  getline(inp,profession);
  inp>>expYears;
  inp.ignore();
  getline(inp,avalDay);
  getline(inp,avalHour);
  getline(inp,date);
  inp>>fee;
  doctors[doctorCount]=Doctor(id,name,age,gender,blood,phone,address,salary,profession,expYears,0,0,date,fee);
  setIndexesToTrue(doctors[doctorCount].getAvailableDays(),8,avalDay);
  setIndexesToTrue(doctors[doctorCount].getAvailablePeroids(),49,avalHour);
  doctorCount++;
  }
  else
   cout<<"FUCK";
  inp.close();
}
void Admin::loadPatient(){
  int id,age;
  string name,gender,blood,phone,address,notes,emergency;
  ifstream inp;

  inp.open("inputPatient.txt");
  if(inp.is_open())
  while (inp>>id) {
  inp.ignore();
  getline(inp,name);
  inp>>age;
  inp.ignore();
  getline(inp,gender);
  getline(inp,blood);
  getline(inp,phone);
  getline(inp,address);
  getline(inp,notes);
  getline(inp,emergency);

  patients[patientCount++]=Patient(id,name,age,gender,blood,phone,address,notes,"","",emergency);
  }
  else
   cout<<"FUCK";
  inp.close();
}

void Admin::load(){
  this->loadDoctor();
  this->loadPatient();

}
void Admin::save(){
  ofstream ofs ("inputPatient.txt", std::ios::out | std::ios::trunc); // clear contents
  ofs.close();

     for (int i = 0; i < patientCount; i++) {
         patients[i].saveInfo();
     }
  ofs.open("inputDoctors.txt", std::ios::out | std::ios::trunc);
  ofs.close();
     for (int i = 0; i < doctorCount; i++) {
         doctors[i].saveInfo();
     }

}
//temprory
ostream& operator<<(ostream& os, const Admin& admin) {
    os << "Patients:" << endl;
    for (int i = 0; i < admin.patientCount; i++) {
        os << admin.patients[i] << endl;
    }

    os << "Doctors:" << endl;
    for (int i = 0; i < admin.doctorCount; i++) {
        os << admin.doctors[i] << endl;
    }

    return os;
}

