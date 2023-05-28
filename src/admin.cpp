#include "admin.h"
#include "doctor.h"
#include "patient.h"
#include "person.h"


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
    patients[patientCount].setId(patientCount+10001);
    patientCount++;
}
void Admin::editPatient(){
  int id;
  cout<<"Enter patient Id: ";
  cin>>id;
  patients[id].editInfo();
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
  doctors[id].editInfo();
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

