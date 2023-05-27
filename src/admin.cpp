#include "admin.h"

Admin::Admin()
{
  doctorCounter = 0; MaxDoctor = 1000;
  DoctorList = new Doctor();

  patientCounter = 0; MaxPatient = 10000;
  PatientList = new Patient();

  appointmentCounter = 0; MaxAppointment = 100000;
  AppointmentList = new Appointment(0);
}

Admin::~Admin()
{

}