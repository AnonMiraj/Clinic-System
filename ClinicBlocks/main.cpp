#include <bits/stdc++.h> // stringstream
#include <cstring>       // string, to_string
#include <iostream>      // cin, cout
#include <string>
#include "admin.h"
#include "other.h"
#include<windows.h>
using namespace std;

/** ASSISTANT INLINE FUNCTIONS **/
inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    Sleep(sec);
    if (clear_screen)
        system("cls");
}

inline void printline(string msg, bool end_line = true)
{
    cout << msg << (end_line ? "\n" : "\t");
}

inline void print_try_again()
{
    printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!", 1);
    wait_or_clear(3, 1);
}

/** MAIN PRINT MENU FUNCTION **/
int get_menu_choise(string menu, int level = 0)
{
    stringstream X(menu);
    string line, padding;
    int i = 1;
    for (int p = 0; p < level + 1; ++p)
        padding += "\t";

    int counter = 0;
    while (getline(X, line, ','))
    {
        printline(padding + to_string(i++) + ". " + line, 1);
        counter++;
    }

    printline(level ? padding + "0. RETURN BACK" : padding + "0. EXIT APP", 1);
    string c;
    do
    {
        printline("ENTER YOUR CHOICE :", false);
        cin >> c;
    } while (IsValid(0, counter+1, c) == -1);
    return stoi(c);
}

/// Admin inilization

Admin Hospital;


/** ADMIN HUB AND SUB MENU **/

void sub_sub_menu_1_doctor_management()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> ADMIN HUB -> DOCTOR MANAGEMENT ....");

        c = get_menu_choise("ADD DOCTOR,EDIT DOCTOR,ARCHIVE DOCTOR,UNARCHIVE DOCTOR,print all", 2);
        switch (c)
        {
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
            Hospital.unarchiveDoctor();
            _pause();
            break;
        case 5:
            Hospital.printAllDoctors();
            _pause();
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}
void sub_sub_menu_2_spec_management()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> ADMIN HUB -> SPECIALTIES MANAGEMENT ....");
        c = get_menu_choise("ADD SPECIALTY,EDIT SPECIALTY,ASSIGN DOCTOR,UNASSIGN DOCTOR,Print All Specs", 2);
        switch (c)
        {
        case 1:
            Hospital.addSpecialization();
            break;
        case 2:
            Hospital.editSpecialization();
            _pause();
            break;
        case 3:
            Hospital.addDoctorToSpec();
            _pause();
            break;
        case 4:
            Hospital.DetDoctorFromSpec();
            _pause();
            break;
        case 5:
            Hospital.printAllSpecs();
            _pause();
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}


void sub_menu_1_admin_hub()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> ADMIN hub ....");
        c = get_menu_choise("DOCTOR MANAGEMENT,SPECIALTY MANAGEMENT,HISTORY PATIENT,HISTORY DOCTOR", 1);
        switch (c)
        {
        case 1:
            sub_sub_menu_1_doctor_management();
            break;
        case 2:
            sub_sub_menu_2_spec_management();
            break;
        case 3:
            Hospital.patientHistory();
            _pause();
            break;
        case 4:
            Hospital.doctorsHistory();
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
void sub_menu_2_doctor_hub()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> DOCTOR HUB ....");
        c = get_menu_choise("ATTEND,EDIT", 1);
        switch (c)
        {
        case 1:
            Hospital.BeAttend();
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

/** patient hub AND SUB MENU **/

void sub_sub_menu_3_patient_hub()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> PATIENT HUB -> APPOINTMENT, ....");
        c = get_menu_choise("", 2);
        switch (c)
        {
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
void sub_menu_3_patient_hub()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> PATIENT HUB ....");
        c = get_menu_choise("CREATE ACCOUNT ,EDIT ACCOUNT INFORMATION ,BUY A PRESCRIPTION,APPOINTMENT,VIEW AVAILABLE DOCTORS", 1);
        switch (c)
        {
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
            Hospital.addAppointment();
            sub_sub_menu_3_patient_hub();
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
int main()
{
    Hospital.load();
    printline("START APPLICATION ....", 1);
    wait_or_clear(1, 1);
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU ....", 1);
        c = get_menu_choise("ADMIN HUB,DOCTOR MANAGEMENT,PATIENT MANAGEMENT",
                            0);

        switch (c)
        {
        case 1:
            sub_menu_1_admin_hub();
            break;
        case 2:
            sub_menu_2_doctor_hub();
            break;
        case 3:
            sub_menu_3_patient_hub();
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
