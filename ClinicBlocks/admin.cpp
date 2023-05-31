#include "admin.h"
#include "Medical_Specialization.h"
#include "appointment.h"
#include "doctor.h"
#include "other.h"
#include "patient.h"
#include "person.h"
#include <cstdio>
#include <fstream>
#include <string>
#include <unistd.h>


Admin::Admin()
{
    patientCount = 0;
    doctorCount = 0;
    specializationCount = 0;
    appointmentCount = 0;

    maxPatients = 10;
    maxDoctors = 10;
    maxSpecialization=10;
    maxAppointment = 10;

    patients = new Patient[maxPatients];  // Initial capacity for 10 patients
    doctors = new Doctor[maxDoctors];  // Initial capacity for 10 doctors
    specializations = new Medical_Specialization[maxSpecialization];  // Initial capacity for 10 doctors
    appointments = new Appointment[maxAppointment];

}

Admin::~Admin()
{
    delete[] patients;
    delete[] doctors;
    delete[] specializations;
}

void Admin::addPatient()
{
    resizePatient();
    patients[patientCount] =  Patient();
    cin>>patients[patientCount];
    patients[patientCount].setId(patientCount+1);
    patientCount++;
}

void Admin::addSpecialization()
{
    resizespecial();
    string name;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin,name);
    specializations[specializationCount] =  Medical_Specialization(specializationCount+1,name);
    specializationCount++;
}

void Admin::addAppointment()
{
    resizeappoint();
    cout<<endl<<appointmentCount<<endl;
    appointments[appointmentCount] = Appointment(appointmentCount+1);

    //choose doctor
    int ID;
    cout<<"Enter doctor id : "; cin>>ID;
    cout<<doctors[ID-1];
    appointments[appointmentCount].setDoctor(doctors[ID-1]);



    //choose appointment
    int per;
    //printDayNames(doctors[ID-1].getAvailableDays(), 49);
    //printPeriodTimes(doctors[ID-1].getAvailablePeroids(), 8);
    cout<<"Enter a number of period : "; cin >> per;
    appointments[appointmentCount].setPeriod(per);
    cout<<"Enter a day number : "; cin>>per;
    appointments[appointmentCount].setDate(per);

    //choose patient
    cout<<"Enter patient id : ";
    cin>>ID;
    appointments[appointmentCount].setPatient(patients[ID-1]);

    //pay to book the appointment

    appointments[appointmentCount].setStatue(1);
    appointmentCount++;

}

void Admin::BeAttend()
{
    for (int i = 0; i<appointmentCount; i++)
    {
        if (appointments[i].getStatue() == "BOOKED")
            cout<<"\n************************\n"
                <<appointments[i]
                <<"\n************************\n";
    }
string medic, dose;
int quantity,yes;
    int AttendID;
    cout<<"Enter appointment ID to be attended : "; cin>>AttendID;
p:
    cout<<"Add Prescription: "<<endl;
    cout<<"medication: ";
    cin>>medic;
    cout<<"Dose: ";
    cin>>dose;
    cout<<"quantity";
    cin>>quantity;
    appointments[AttendID-1].addPrescription(medic,dose,quantity);
    cout<<"Add more? (y/N)";
    cin>>yes;
    if (yes=='y'||yes=='Y')
      goto p;
    appointments[AttendID-1].setStatue(2);
}

int Admin::searchAppointment(int id)
{
    for (int i=0; i<appointmentCount; i++)
        if (appointments[i].getID() == id)
            return i;
    return -1;
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

void Admin::addDoctorToSpec()
{
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

    doctors[doc_Indx].setSpecialization(specializations[Spec_Indx]);
    ++specializations[Spec_Indx];
    cout << "Doctor Added successfully." ;
}

void Admin::DetDoctorFromSpec()
{
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
    Medical_Specialization newSpec;
    doctors[doc_Indx].setSpecialization(newSpec);

    cout << "Doctor Removed successfully." ;

}

void Admin::addDoctor()
{
    resizeDoctor();
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
    doctors[doctorIndex-1].setAracived(true);

}

void Admin::unarchiveDoctor()
{
    int archiveIndex;
    cout<<"Enter the archived Doctor id: ";
    cin>>archiveIndex;
    doctors[archiveIndex-1].setAracived(false);
}

void Admin::printAllDoctors()
{
    for(int i=0; i<doctorCount; i++)
    {
        cout<<"==============================="<<endl;
        cout<<doctors[i];
        cout<<"==============================="<<endl;

    }

}
void Admin::printAllSpecs()
{
    for(int i=0; i<specializationCount; i++)
    {
        cout<<"==============================="<<endl;
        cout<<specializations[i];
        cout<<"==============================="<<endl;

    }

}

void Admin::patientHistory(){
    int id;
    cout<<"Enter patient Id: ";
    cin>>id;


        for(int i=0; i<appointmentCount; i++)
    {
        if(id-1==Appointment().getPatient()->getId())
        {

        cout<<"==============================="<<endl;
        cout<<appointments[i];
        cout<<"==============================="<<endl;
        }

    }
}

void Admin::doctorsHistory(){}
// resizer
void Admin::resizeDoctor(){
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
}

void Admin::resizePatient(){
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


}
void Admin::resizespecial(){
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

}
void Admin::resizeappoint(){
      if (appointmentCount == maxAppointment)
    {
        // Resize the array if it's full
        Appointment* newAppointment = new Appointment[maxAppointment * 2];
        for (int i = 0; i < appointmentCount; i++)
        {
            newAppointment[i] = appointments[i];
        }
        delete[] appointments;
        appointments = newAppointment;
        maxAppointment *= 2;
    }
}
// loader from files
void Admin::loadDoctor()
{
    int id,age,expYears,specializationID,salary,fee,archive;
    string name,gender,blood,phone,address,avalDay,avalHour,date;
    ifstream inp;
    inp.open("inputDoctors.txt");
    if(inp.is_open())
        while (inp>>id)
        {
            resizeDoctor();

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
            inp>>archive;
            inp.ignore();
            getline(inp,avalDay);
            getline(inp,avalHour);
            getline(inp,date);
            inp>>fee;
            doctors[doctorCount]=Doctor(id,name,age,gender,blood,phone,address,salary,expYears,0,0,false,date,fee);
            setIndexesToTrue(doctors[doctorCount].getAvailableDays(),8,avalDay);
            setIndexesToTrue(doctors[doctorCount].getAvailablePeroids(),49,avalHour);
            if(specializationID!=-1)
            {
              doctors[doctorCount].setSpecialization(specializations[specializationID-1]);
              ++specializations[specializationID-1];
            }
            doctorCount++;
        }
    else
        inp.close();
}

void Admin::loadPatient()
{
    int id,age,insurance;
    string name,gender,blood,phone,address,emergency;
    ifstream inp;

    inp.open("inputPatient.txt");
    if(inp.is_open())
        while (inp>>id)
        {
            resizePatient();

            inp.ignore();
            getline(inp,name);
            inp>>age;
            inp.ignore();
            getline(inp,gender);
            getline(inp,blood);
            getline(inp,phone);
            getline(inp,address);
            getline(inp,emergency);
            inp>>insurance;

            patients[patientCount++]=Patient(id,name,age,gender,blood,phone,address,"",insurance,emergency);
        }
    else
        cout<<"FUCK";
    inp.close();
}

void Admin::loadSpecial()
{
    string name;
    ifstream inp("inputSpec.txt");

    if(inp.is_open())
        while (getline(inp,name))
        {
            resizespecial();

            specializations[specializationCount]=Medical_Specialization(specializationCount+1,name);
            specializationCount++;
        }
    else
        cout<<"FUCK";
    inp.close();

}
void Admin::loadAppointment(){
  long long date;
  int period,patientId,doctorId,statue;
      ifstream inp("inputAppoint.txt");

    if(inp.is_open())
        while (inp>>date)
        {
            resizeappoint();

            inp>>period>>patientId>>doctorId>>statue;
            appointments[appointmentCount]=Appointment(appointmentCount+1,period,date,statue);
            appointments[appointmentCount].setPatient(patients[patientId-1]);
            appointments[appointmentCount].setDoctor(doctors[doctorId-1]);
            appointmentCount++;
        }
    else
        cout<<"FUCK";
    inp.close();

}
void Admin::loadPrescription(){
  string dose,medic;
  int appointmentId,quantity,prescCount;
      ifstream inp("inputPresc.txt");

    if(inp.is_open())
        while (inp>>appointmentId)
        {
            inp>>prescCount;
            while (prescCount--) {
            inp.ignore();
            getline(inp,medic);
            getline(inp,dose);
            inp>>quantity;
            appointments[appointmentId-1].addPrescription(medic, dose , quantity);
            }

        }
    else
        cout<<"FUCK";
    inp.close();


}

void Admin::load()
{
    this->loadSpecial();
    this->loadDoctor();
    this->loadPatient();
    this->loadAppointment();
    this->loadPrescription();
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
    ofs.open("inputSpec.txt", std::ios::out | std::ios::trunc);
    ofs.close();
    for (int i = 0; i < specializationCount; i++)
    {
      specializations[i].saveInfo();
    }

    ofs.open("inputAppoint.txt", std::ios::out | std::ios::trunc);
    ofs.close();

    ofs.open("inputPresc.txt", std::ios::out | std::ios::trunc);
    ofs.close();

    for (int i = 0; i < appointmentCount; i++)
    {
      ofstream  oupt2;
      oupt2.open("inputPresc.txt",ios::app);
      oupt2<<i+1<<endl;
      oupt2.close();
      appointments[i].saveInfo();
    }

}

void Admin::setInsurances()
{
    cin>>insurances;
}

void Admin::getInsurances()
{
    cout<<insurances;
}


//seerch
int Admin::searchPatient(int id)
{
    for (int i=0; i<patientCount; i++)
        if (patients[i] == patients[id])
            return i;

    return -1;
}

string Admin::getPatient_name(int in)
{
    return patients[in].getName();
}

string Admin::getDoctor_name(int in)
{
    return doctors[in].getName();
}

int Admin::searchDoctor(int id)
{
    for (int i=0; i<patientCount; i++)
        if (doctors[i] == doctors[id])
            return i;

    return -1;
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
    os << "Appointments :"<< endl;
    for (int i = 0; i < admin.appointmentCount; i++)
    {
        os << admin.appointments[i] << endl;
    }
    return os;
}

