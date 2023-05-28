#include <bits/stdc++.h> // stringstream
#include <cstring>       // string, to_string
#include <iostream>      // cin, cout
#include <string>
#include "admin.h"
#include "other.h"
using namespace std;

/** ASSISTANT INLINE FUNCTIONS **/
inline void wait_or_clear(unsigned int sec, bool clear_screen = false) {
  sleep(sec);
  if (clear_screen)
    system("clr");
}

inline void printline(string msg, bool end_line = true) {
  cout << msg << (end_line ? "\n" : "\t");
}

inline void print_try_again() {
  printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!", 1);
  wait_or_clear(3, 1);
}

/** MAIN PRINT MENU FUNCTION **/
int get_menu_choise(string menu, int level = 0) {
  stringstream X(menu);
  string line, padding;
  int i = 1;
  for (int p = 0; p < level + 1; ++p)
    padding += "\t";

  while (getline(X, line, ','))
    printline(padding + to_string(i++) + ". " + line, 1);

  printline(level ? padding + "0. RETURN BACK" : padding + "0. EXIT APP", 1);
  int c;
  printline("ENTER YOUR CHOICE :", false);
  cin >> c;
  return c;
}
/// Admin inilization 

Admin Hospital;


/** ADMIN MANAGEMENT AND SUB MENU **/

void sub_menu_1_admin_management() {
  int c = -1;
  while (c != 0) {
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> ADMIN MANAGEMENT ....");
    c = get_menu_choise("ADD DOCTOR,EDIT DOCTOR,ARCHIVE DOCTOR,UNARCHIVE DOCTOR,HISTORY PATIENT,HISTORY DOCTOR,DOCTOR EDIT REQUEST,PATIENT EDIT REQUEST,APPOINTMENT EDIT REQUEST,APPOINTMENT CANCEL REQUEST", 1);
    switch (c) {
    case 1:
      Hospital.addDoctor();      
      _pause();
      break;
    case 2:
      Hospital.editDoctor();
      _pause();
      break;
    case 3:
      Hospital.archiveDoctor();
      _pause();
      break;
    case 4:
      Hospital.archiveDoctor();
      _pause();
      break;
    case 5:
      _pause();
      break;
    case 6:
      _pause();
      break;
    case 7:
      _pause();
      break;
    case 8:
      _pause();
      break;
    case 9:
      _pause();
      break;
    case 10:
      _pause();
      break;
    case 11:
      _pause();
      break;
    case 0:
      return;
    default:
      print_try_again();
    }
  }
}


/** DATA ENTRY AND SUB MENU **/
void sub_menu_2_doctor_management() {
  int c = -1;
  while (c != 0) {
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> DOCTOR MANAGEMENT ....");
    c = get_menu_choise("ATTEND,EDIT", 1);
    switch (c) {
    case 1:
      _pause();
      break;
    case 2:
      _pause();
      break;
    case 0:
      return;
    default:
      print_try_again();
    }
  }
}

/** patient management AND SUB MENU **/

void sub_sub_menu_3_patient_management() {
  int c = -1;
  while (c != 0) {
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> PATIENT MANAGEMENT -> APPOINTMENT, ....");
    c = get_menu_choise("", 2);
    switch (c) {
    case 1:
      _pause();
      break;
    case 2:
      _pause();
      break;
    case 3:
      _pause();
      break;
    case 4:
      _pause();
      break;
    case 0:
      return;
    default:
      print_try_again();
    }
  }
}
void sub_menu_3_patient_management() {
  int c = -1;
  while (c != 0) {
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU -> PATIENT MANAGEMENT ....");
    c = get_menu_choise("CREATE ACCOUNT ,EDIT ACCOUNT INFORMATION ,BUY A PRESCRIPTION,APPOINTMENT,VIEW AVAILABLE DOCTORS", 1);
    switch (c) {
    case 1:
      Hospital.addPatient();
      _pause();
      break;
    case 2:
      Hospital.editPatient();
      _pause();
      break;
    case 3:
      _pause();
      break;
    case 4:
      sub_sub_menu_3_patient_management();
      _pause();
      break;
    case 5:
      _pause();
      break;
    case 6:
      _pause();
      break;
    case 0:
      return;
    default:
      print_try_again();
    }
  }
}

/** MAIN FUNCTION **/
int main() {
  Hospital.load();
  printline("START APPLICATION ....", 1);
  wait_or_clear(1, 1);
  int c = -1;
  while (c != 0) {
    wait_or_clear(0, 1);
    printline("\n\nMAIN MENU ....", 1);
    c = get_menu_choise("ADMIN MANAGEMENT,DOCTOR MANAGEMENT,PATIENT MANAGEMENT,debug",
                        0);

    switch (c) {
    case 1:
      sub_menu_1_admin_management();
      break;
    case 2:
      sub_menu_2_doctor_management();
      break;
    case 3:
      sub_menu_3_patient_management();
      break;
    case 4:
      cout<<Hospital;
      _pause();
      break;
    case 0:
      printline("\n\n\a\t\t\tGoodbye :)......\n\n\n\n\n\n", 1);
      break;
    default:
      print_try_again();
      wait_or_clear(3, true);
    }
  }
  Hospital.save();
 return 0;
}
