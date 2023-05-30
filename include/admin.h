#ifndef ADMIN_H
#define ADMIN_H
#include "person.h"
#include "patient.h"
#include "doctor.h"
#include "other.h"
#include "Medical_Insurance.h"
#include "Medical_Specialization.h"
#include "appointment.h"
#include <fstream>

using namespace std;

class Admin {
private:
    Patient* patients;
    Doctor* doctors;
    Medical_Specialization* specializations;
    Appointment* appointments;
    Medical_Insurance insurances;

    int patientCount;
    int doctorCount;
    int specializationCount;
    int appointmentCount;

    int maxPatients;
    int maxDoctors;
    int maxSpecialization;
    int maxAppointment;
public:
    Admin();
    ~Admin();

    // Other member functions for managing patients and doctors
    void addPatient();
    void editPatient();

    void addDoctor();
    void editDoctor();
    void addDoctorToSpec();
    void DetDoctorFromSpec();
    //new
    void printAllDoctors();
    void patientHistory();
    void doctorsHistory();
    void printAllSpecs();



    void archiveDoctor();
    void unarchiveDoctor();

    void addSpecialization();
    void editSpecialization();
    void addAppointment();
    void BeAttend();

    void loadDoctor();
    void loadPatient();
    void loadSpecial();

    void load();
    void save();
    friend ostream& operator<<(ostream& os, const Admin& admin);

    void setInsurances();
    void getInsurances();

    int searchPatient(int);
    int searchDoctor(int);
    string getPatient_name(int in);
    string getDoctor_name(int in);
};


#endif  // ADMIN_H

