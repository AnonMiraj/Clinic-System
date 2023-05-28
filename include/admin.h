
#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include "patient.h"
#include "doctor.h"

using namespace std;

class Admin {
private:
    Patient* patients;
    Doctor* doctors; 
    Doctor* archivedDoctors;
    int patientCount;
    int doctorCount;
    int archiveCount;   
    int maxPatients;
    int maxDoctors;
    int maxArchive;
public:
    Admin();
    ~Admin();

    // Other member functions for managing patients and doctors
    void addPatient();
    void addDoctor();

    void editPatient();
    void editDoctor();
    friend ostream& operator<<(ostream& os, const Admin& admin);
};


#endif  // ADMIN_H

