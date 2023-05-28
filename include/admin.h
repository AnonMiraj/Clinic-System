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
    Medical_Specialization* specializations;
    Medical_Insurance insurances;

    int patientCount;
    int doctorCount;
    int specializationCount;

    int maxPatients;
    int maxDoctors;
    int maxSpecialization;
public:
    Admin();
    ~Admin();

    // Other member functions for managing patients and doctors
    void addPatient();
    void addDoctor();
    void addSpecialization();

    void editPatient();
    void editDoctor();
    void editSpecialization();

    void addDoctorToSpec();
    void DetDoctorFromSpec();

    void archiveDoctor();
    void unarchiveDoctor();

    void loadDoctor();
    void loadPatient();
    void loadSpecial();

    void load();
    void save();
    friend ostream& operator<<(ostream& os, const Admin& admin);

    void setInsurances();
    void getInsurances();
};


#endif  // ADMIN_H

