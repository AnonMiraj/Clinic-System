#include "admin.h"
#include "Medical_Specialization.h"
#include "doctor.h"
#include "other.h"
#include "patient.h"
#include "person.h"
#include <fstream>
#include <string>
#include <unistd.h>


Admin::Admin()
{
    patientCount = 0;
    doctorCount = 0;
    specializationCount=0;

    maxPatients = 10;
    maxDoctors = 10;
    maxSpecialization=50;

    patients = new Patient[maxPatients];  // Initial capacity for 10 patients
    doctors = new Doctor[maxDoctors];  // Initial capacity for 10 doctors
    specializations = new Medical_Specialization[maxSpecialization];  // Initial capacity for 10 doctors

}

Admin::~Admin()
{
    delete[] patients;
    delete[] doctors;
    delete[] specializations;
}

void Admin::addPatient()
{
    if (patientCount == maxPatients)
    {
        // Resize the array if it's full
        Patient* newPatients = new Patient[maxPatients * 2];
        for (int i = 0; i < patientCount; i++)
        {
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

void Admin::addSpecialization()
{
    if (specializationCount == maxSpecialization)
    {
        // Resize the array if it's full
        Medical_Specialization* newSpecializations = new Medical_Specialization[maxSpecialization * 2];
        for (int i = 0; i < specializationCount; i++)
        {
            newSpecializations[i] = specializations[i];
        }
        delete[] specializations;
        specializations = newSpecializations;
        maxSpecialization *= 2;
    }
    string name;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin,name);
    specializations[specializationCount] =  Medical_Specialization(specializationCount+1,name);
    specializationCount++;
}


void Admin::editPatient()
{
    int id;
    cout<<"Enter patient Id: ";
    cin>>id;
    patients[id-1].editInfo();
}

void Admin::editSpecialization()
{
    int id;
    cout<<"Enter patient Id: ";
    cin>>id;
    specializations[id-1].editInfo();
}

void Admin::addDoctorToSpec(){
    int Spec_Indx=-1;
    cout<<"Enter Specialization Id (Enter 0 to exit Add To Spec Menu ): ";
    cin>>Spec_Indx;
    Spec_Indx--;

    int doc_Indx=-1;
    cout<<"Enter Doctor Id (Enter 0 to exit Add To Spec Menu ): ";
    cin>>doc_Indx;
    doc_Indx--;

    if(Spec_Indx == -1 || doc_Indx==-1 )
    {
        cout << "Exiting the Add To Specialization Menu " << endl;
        return;
    }
    system("cls");

    doctors[doc_Indx].setSpecialization(&specializations[Spec_Indx]);

    cout << "Doctor Added successfully." ;
}
void Admin::DetDoctorFromSpec(){
    int doc_Indx=-1;
    cout<<"Enter Doctor Id (Enter 0 to exit Add To Spec Menu ): ";
    cin>>doc_Indx;
    doc_Indx--;

    if(doc_Indx == -1)
    {
        cout << "Exiting the Remove From Specialization Menu " << endl;
        return;
    }
    system("cls");
    Medical_Specialization *newSpec;
    doctors[doc_Indx].setSpecialization(newSpec);

    cout << "Doctor Removed successfully." ;
    
}

void Admin::addDoctor()
{
    if (doctorCount == maxDoctors)
    {
        // Resize the array if it's full
        Doctor* newDoctors = new Doctor[maxDoctors * 2];
        for (int i = 0; i < doctorCount; i++)
        {
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
void Admin::editDoctor()
{
    int id;
    cout<<"Enter doctors Id: ";
    cin>>id;
    doctors[id-1].editInfo();
}
void Admin::archiveDoctor()
{
    int doctorIndex;
    cout<<"Enter the doctor id: ";
    cin>>doctorIndex;

}
void Admin::unarchiveDoctor()
{
    int archiveIndex;
    cout<<"Enter the archived Doctor id: ";
    cin>>archiveIndex;

}

void Admin::loadDoctor()
{
    int id,age,expYears,specializationID,salary,fee;
    string name,gender,blood,phone,address,avalDay,avalHour,date;
    ifstream inp;
    inp.open("inputDoctors.txt");
    if(inp.is_open())
        while (inp>>id)
        {
            inp.ignore();
            getline(inp,name);
            inp>>age;
            inp.ignore();
            getline(inp,gender);
            getline(inp,blood);
            getline(inp,phone);
            getline(inp,address);
            inp>>salary;
            inp>>specializationID;
            inp>>expYears;
            inp.ignore();
            getline(inp,avalDay);
            getline(inp,avalHour);
            getline(inp,date);
            inp>>fee;
            doctors[doctorCount]=Doctor(id,name,age,gender,blood,phone,address,salary,expYears,0,0,date,fee);
            setIndexesToTrue(doctors[doctorCount].getAvailableDays(),8,avalDay);
            setIndexesToTrue(doctors[doctorCount].getAvailablePeroids(),49,avalHour);
            if(specializationID!=-1)
              doctors[doctorCount].setSpecialization(&specializations[specializationID-1]);
            doctorCount++;
        }
    else
    inp.close();
}
void Admin::loadPatient()
{
    int id,age;
    string name,gender,blood,phone,address,notes,emergency;
    ifstream inp;

    inp.open("inputPatient.txt");
    if(inp.is_open())
        while (inp>>id)
        {
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

            patients[patientCount++]=Patient(id,name,age,gender,blood,phone,address,"",0,emergency);
        }
    else
        cout<<"FUCK";
    inp.close();
}
void Admin::loadSpecial(){
  string name;
  ifstream inp("inputSpec.txt");

    if(inp.is_open())
        while (getline(inp,name))
        {
            specializations[specializationCount]=Medical_Specialization(specializationCount+1,name);

        cout<<"FUCK";
        cout<<"FUCK";
        specializationCount++;
        }   
    else
        cout<<"FUCK";
    inp.close();

}

void Admin::load()
{
    this->loadDoctor();
    this->loadPatient();
    this->loadSpecial();
}
void Admin::save()
{
    ofstream ofs ("inputPatient.txt", std::ios::out | std::ios::trunc); // clear contents
    ofs.close();

    for (int i = 0; i < patientCount; i++)
    {
        patients[i].saveInfo();
    }
    ofs.open("inputDoctors.txt", std::ios::out | std::ios::trunc);
    ofs.close();
    for (int i = 0; i < doctorCount; i++)
    {
        doctors[i].saveInfo();
    }

}
    void Admin::setInsurances(){
    cin>>insurances;
    }

    void Admin::getInsurances(){
    cout<<insurances;
    }

//temprory
ostream& operator<<(ostream& os, const Admin& admin)
{
    os << "Patients:" << endl;
    for (int i = 0; i < admin.patientCount; i++)
    {
        os << admin.patients[i] << endl;
    }

    os << "Doctors:" << endl;
    for (int i = 0; i < admin.doctorCount; i++)
    {
        os << admin.doctors[i] << endl;
    }
    os << "Specials :" << endl;
    for (int i = 0; i < admin.specializationCount; i++)
    {
        os << admin.specializations[i] << endl;
    }


    return os;
}

