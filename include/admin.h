#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "doctor.h"
#include "patient.h"
#include "Stock.h"
#include "appointment.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Admin
{
  public:
  int doctorCounter;
  int MaxDoctor;
  int patientCounter;
  int MaxPatient;
  int appointmentCounter;
  int MaxAppointment;
  Admin();
  ~Admin();

  protected:

  private:
  Doctor* DoctorList;
  Patient* PatientList;
  Appointment* AppointmentList;
}; 

#endif //ADMIN_H