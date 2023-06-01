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
    c_OrderList=0;
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

string Admin::printAvailableDay(const Doctor& d)
{
    using namespace std::chrono;
    string ye = "", mo = "", da = "", DATE = ""; char ch;

    bool IsNotValid;
    do
    {
        IsNotValid = false;
        try
        {
            cout << "\nEnter date (yyyy/mm/dd): ";
            cin >> ye >> ch >> mo >> ch >> da;

            if (!IsValid(ye, '1') || !IsValid(mo, '2') || !IsValid(da, '3'))
                throw "\n";

            if ((ye.size() != 4) || (stoi(mo) > 12) || (stoi(da) > 31))
                throw "This date is invalid. :(\n";



            break;
        }
        catch (const char* str)
        {
            IsNotValid = true;
            cout << str;
        }

    } while (IsNotValid);

    mo = (mo.size() == 1 ? "0"+mo : mo);
    da = (da.size() == 1 ? "0"+da : da);
    DATE = ye + "/" + mo + "/" + da;

    // Get current local time
    system_clock::time_point now = system_clock::now();
    time_t ti = system_clock::to_time_t(now);
    tm* t = localtime(&ti);
    t->tm_year = std::stoi(ye) - 1900; // Adjusting the year
    t->tm_mon = std::stoi(mo) - 1;    // Adjusting the month
    t->tm_mday = std::stoi(da);       // Setting the day

    mktime(t); // Normalize the time structure

    int wday = t->tm_wday;
    if (wday == 0) {
        wday = 6;
    } else {
        wday -= 2;
    }

    int counter = 0;
    if (d.availableDays[wday] == true)
    {
        cout<<endl <<DATE <<endl;
        for (int j = 1; j < 48; j++)
        {
            if (!d.availablePeroids[j])
                continue;

            bool check = true;
            for (int k=0; k <appointmentCount; k++)
            {
                if (appointments[k].getStatue() == "BOOKED" && appointments[k].getDate() == DATE && appointments[k].getPeriod_int() == j && *appointments[k].getDoctor() == d)
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                if (counter % 5 == 0)
                    cout << endl;
                counter++;
                cout << "| " << j << "- " << getPeriod(j) << "  ";
            }
        }

        if (counter == 0)
            {
                cout << "There is no available period on this day :(\n";
                DATE = "00";
            }
    }
    else
        {
            cout << "This day is not available for the doctor :(\n";
            DATE = "00";
        }

    return DATE;
}

void Admin::addAppointment()
{
    resizeappoint();
    appointments[appointmentCount] = Appointment(appointmentCount+1);

    //choose doctor
    int dID;
    do
    {
        dID = returnValidInt("Enter Doctor id : ");
        if (searchDoctor(dID)== -1)
            cout<<"This Id is not exist :(\n\n";
        else
            break;
    } while (true);

    appointments[appointmentCount].setDoctor(doctors[dID-1]);

    cout<<"Doctor's name : " <<doctors[dID-1].getName()
        <<"\nSpecialization : " <<doctors[dID-1].getSpecialization()->getName()
        <<"\nAppointment fee : " <<doctors[dID-1].getAppointmentFee();

    //choose appointment
    int period;
    //printDayNames(doctors[dID-1].getAvailableDays(), 8);
    //printPeriodTimes(doctors[dID-1].availablePeroids, 49);
    string ava;
    do
    {
        ava = printAvailableDay(doctors[dID-1]);
    } while (ava == "00");
    appointments[appointmentCount].setDate(ava);

    // is valid function to check if the period number if availbale this day
    // you need to return an array from function to what you must choose from
    string w;
    do
    {
        cout<<"\nEnter period number : "; cin>>w;
    } while (IsValid(1,48,w) == -1);
    period = stoi(w);
    appointments[appointmentCount].setPeriod(period);

        /*
            for (int i=0; i<appointmentCount-1; i++)
            if (appointments[i] == appointments[appointmentCount] && appointments[i].getStatue() != "CANCELLED")
            {
                check = true;
                cout<<"\nThis date is already booked :(\nPlease, enter a new date\n";
                break;
            }
        */

    //choose patient
    int pID;
    do
    {
        pID = returnValidInt("Enter Patient ID : ");
        if (searchPatient(pID) == -1)
            cout<<"This Id is not exist :(\n\n";
        else
            break;
    } while (true);

    appointments[appointmentCount].setPatient(patients[pID-1]);

    //pay to book the appointment

    appointments[appointmentCount].setStatue(1);
    appointmentCount++;
}

void Admin::viewAPP()
{
    int ID;
    do
    {
        ID = returnValidInt("Enter your Appointment id : ");

        if (searchAppointment(ID) == -1) cout<<"This Id is not exist :(\n";
        else break;
    } while (true);

    cout<<appointments[ID-1];
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

void Admin::cancelAPP()
{
    int id; string w;
    do
    {
        id = returnValidInt("Enter your Appointment id : ");

        if (searchAppointment(id)== -1) cout<<"This Id is not exist :(\n";
        else break;
    } while (true);

    if(appointments[id-1].getStatue() == "BOOKED")
    {
        appointments[id-1].setStatue(0);
    }

    else
        cout<<"You can't cancel the appointment. it's " <<appointments[id-1].getStatue() <<"\n";
}

int Admin::searchAppointment(int id)
{
    for (int i=0; i<appointmentCount; i++)
        if (appointments[i].getID() == id)
            return i;
    return -1;
}

int Admin::returnValidInt(string msg)
{
    string w;
    do
    {
        cout<<msg;
        cin>>w;
    } while (!IsValid(w,'1'));

    return stoi(w);
}

void Admin::editPatient()
{
    int id;
    do
    {
        id = returnValidInt("Enter your Patient id : ");

        if (searchPatient(id)== -1) cout<<"This Id is not exist :(\n";
        else break;
    } while (true);

    patients[id-1].editInfo();
}

void Admin::editSpecialization()
{
    int id; string w;
    do
    {
        id = returnValidInt("Enter your Appointment id : ");

        if (searchPatient(id)== -1) cout<<"This Id is not exist :(\n";
        else break;
    } while (true);

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

void Admin::viewDoctor()
{
    int ID = returnValidInt("Enter Doctor ID : ");
    cout<<doctors[ID-1];

}

void Admin::editDoctor()
{
    int id = returnValidInt("Enter Doctor ID : ");
    doctors[id-1].editInfo();
}

void Admin::archiveDoctor()
{
    int doctorIndex = returnValidInt("Enter Doctor ID : ");
    doctors[doctorIndex-1].setAracived(true);

}

void Admin::unarchiveDoctor()
{
    int archiveIndex = returnValidInt("Enter the archived Doctor id : ");;
    cout<<"Enter the archived Doctor id : ";
    cin>>archiveIndex;
    doctors[archiveIndex-1].setAracived(false);
}

void Admin::viewAvailableDoctors()
{
    for (int i=0; i<doctorCount; i++)
    {
        cout<<"\n*******************************************\n";
        cout<<"ID : " <<doctors[i].getId() <<"\nName : " <<doctors[i].getName()
            <<"\nSpecialization : " <<doctors[i].getSpecialization()->getName() <<"\nFee : " <<doctors[i].getAppointmentFee() <<endl;
        printDayNames(doctors[i].getAvailableDays(),8);
        printPeriodTimes(doctors[i].getAvailablePeroids(),49);
        cout<<"\n*******************************************\n";
    }
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

void Admin::printSpecDoctors()
{
    int id = returnValidInt("Enter specialization Id: ");
    cout<<"\n +++ " <<specializations[id-1].getName() <<" +++\n";

    for(int i=0;i<doctorCount;i++)
    {
        if(*doctors[i].getSpecialization() == specializations[id-1])
        {
            cout<<"\n****************************************\n";
            cout<<"ID : " <<doctors[i].getId() <<endl;
            cout<<"NAME: "<<doctors[i].getName()<<endl;
            cout<<"Fee: "<<doctors[i].getAppointmentFee()<<endl;
            cout<<"Available Days: "; printDayNames(doctors[i].availableDays,8);
            cout<<"\nAvailable Periods: "; printPeriodTimes(doctors[i].availablePeroids,49);
            cout<<"\nRate: "<<doctors[i].getRatingSum();
            cout<<"\n****************************************\n";

        }
    }
}

void Admin::patientHistory()
{
    int id = returnValidInt("Enter Patient ID : ");


    for(int i=0; i<appointmentCount; i++)
    {
        if(id == appointments[i].getPatient()->getId())
        {

        cout<<"==============================="<<endl;
        cout<<appointments[i];
        cout<<"==============================="<<endl;
        }

    }
}

void Admin::doctorsHistory()
{
    int id = returnValidInt("Enter Doctor ID : ");


    for(int i=0; i<appointmentCount; i++)
    {
        if(id == appointments[i].getDoctor()->getId())
        {

        cout<<"==============================="<<endl;
        cout<<appointments[i];
        cout<<"==============================="<<endl;
        }

    }
}

void Admin::resizeDoctor()
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
}

void Admin::resizePatient()
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


}

void Admin::resizespecial()
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

}

void Admin::resizeappoint()
{
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

void Admin::loadAppointment()
{
  string date;
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

void Admin::loadPrescription()
{
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


void Admin::Doctors_SearchByName()
{
    int c = 0;
    string s; cout<<"\nEnter a name or part to search : "; cin>>s;

    int len = s.size();

    for (int i=0; i<doctorCount; i++)
    {
        string name = doctors[i].getName();

        for (int j=0; j<=name.size()-len; j++)
        {

            string sub= name.substr(j,len);
            /*for (int k=j; k<j+len; k++) //substr
                sub += name[k];*/

            if (s == sub)
                {
                    cout<<"\n##########################\n";
                    cout<<doctors[i];
                    cout<<"\n##########################\n";
                    c++;
                    break;
                }
        }
    }

    if (c == 0)
        cout<<"\nThere is no Doctors at this name :(\n";
}

//search
int Admin::searchPatient(int id)
{
    for (int i=0; i<patientCount; i++)
        if (patients[i].getId() == id)
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
    for (int i=0; i<doctorCount; i++)
        if (doctors[i].getId() == id)
        {
            return i;
        }

    return -1;
}

int Admin::searchAppoint_patient(int id)
{
    for (int i=0; i<appointmentCount; i++)
        if (*appointments[i].getPatient() == patients[i] && appointments[i].getStatue() != "CANCELLED")
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

