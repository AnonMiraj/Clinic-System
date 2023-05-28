#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include "patient.h"
#include "doctor.h"
#include "other.h"
#include "Medical_Insurance.h"
#include "Medical_Specialization.h"
#include <fstream>
using namespace std;

class Admin {
private:
    Patient* patients;
    Doctor* doctors;
    Doctor* archivedDoctors;
    Medical_Specialization* specializations;
    Medical_Insurance insurances;

    int patientCount;
    int specializationCount;
    int doctorCount;
    int archiveCount;

    int maxSpecialization;
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

    void archiveDoctor();
    void unarchiveDoctor();

    void loadDoctor();
    void loadPatient();
    void load();
    void save();
    friend ostream& operator<<(ostream& os, const Admin& admin);

    void setInsurances();
    void getInsurances();
};


#endif  // ADMIN_H

