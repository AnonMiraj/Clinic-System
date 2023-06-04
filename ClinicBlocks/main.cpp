#include <bits/stdc++.h> // stringstream
#include <cstring>       // string, to_string
#include <iostream>      // cin, cout
#include <string>
#include "admin.h"
#include "List_Of_Orders.h"
#include "Stock.h"
#include "other.h"
// #include<windows.h>
using namespace std;

/** ASSISTANT INLINE FUNCTIONS **/
inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    // Sleep(sec);
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
Admin h;
Admin *Hospital=&h;
List_Of_Orders r;
List_Of_Orders *OrderList=&r;
Stock s;
Stock*stk=&s;

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
            Hospital->addDoctor();
            _pause();
            break;
        case 2:
            Hospital->editDoctor();
            _pause();
            break;
        case 3:
            Hospital->archiveDoctor();
            _pause();
            break;
        case 4:
            Hospital->unarchiveDoctor();
            _pause();
            break;
        case 5:
            Hospital->printAllDoctors();
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
            Hospital->addSpecialization();
            break;
        case 2:
            Hospital->editSpecialization();
            _pause();
            break;
        case 3:
            Hospital->addDoctorToSpec();
            _pause();
            break;
        case 4:
            Hospital->DetDoctorFromSpec();
            _pause();
            break;
        case 5:
            Hospital->printAllSpecs();
            _pause();
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_sub_menu_ViewPatient()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> ADMIN HUB -> PATINET MANAGMENT -> VIEW ....");
        c = get_menu_choise("SHOW ALL PATINETS,SHOW SPECIFIC PATIENT", 2);
        switch (c)
        {
        case 1:
            Hospital->printAllPatient();
            _pause();
            break;

        case 2:
            Hospital->viewPatient();
            _pause();
            break;

        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_3_Patient_management()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> ADMIN HUB -> PATIENT MANAGEMENT ....");

        c = get_menu_choise("ADD PATIENT,EDIT PATIENT,VIEW", 2);
        switch (c)
        {
        case 1:
            Hospital->addPatient();
            _pause();
            break;
        case 2:
            Hospital->editPatient();
            _pause();
            break;
        case 3:
            sub_sub_sub_menu_ViewPatient();
            _pause();
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_4_stk_management()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> ADMIN HUB -> STOCK MANAGEMENT ....");

        c = get_menu_choise("ADD MEDECINE,EDIT MEDECINE,PRINT ALL", 3);
        switch (c)
        {
        case 1:
            stk->addMedcinInStock();
            _pause();
            break;
        case 2:
            stk->editMedcin();
            _pause();
            break;
        case 3:
            cout<<*stk;
            _pause();
            break;
        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_5_View()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> ADMIN HUB -> PHARMACY MANAGEMENT -> VIEW ....");
        c = get_menu_choise("SHOW ALL ORDERS,SHOW SPECIFIC ORDERS", 2);
        switch (c)
        {
        case 1:
            OrderList->printAllOrders();
            _pause();
            break;

        case 2:
            {
                string id;
                do
                {
                    cout<<"Enter Order ID To Show : ";
                    cin>>id;
                }while (!IsValid(id,'1'));
                int index = OrderList->searchOrder(stoi(id));

                if (index != -1)
                    OrderList->printSpecificOrder(index);
                else
                    cout<<"There is ID isn't exist :(\n";
            _pause();
            }
            break;

        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_5_pharmacy_management()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> ADMIN HUB -> PHARMACY MANAGEMENT ....");
        c = get_menu_choise("ORDER MEDECINE,EDIT ORDER,CANCEL ORDER,VIEW", 1);
        switch (c)
        {
        case 1:
            OrderList->addOrder(Hospital, stk);
            _pause();
            break;

        case 2:
            {
                string id;
                do
                {
                    cout<<"Enter Order ID To edit : ";
                    cin>>id;
                }while (!IsValid(id,'1'));
                int index = OrderList->searchOrder(stoi(id));
                if (index != -1)
                    OrderList->editOrder(index);
                else
                    cout<<"There is no order ID :(\n";
            }
            _pause();
            break;

        case 3:
            {
                string id;
                do
                {
                    cout<<"Enter Order ID To remove : ";
                    cin>>id;
                }while (!IsValid(id,'1'));
                OrderList->removeOrder(stoi(id));
                _pause();
                }
            break;

        case 4:
            sub_sub_menu_5_View();
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
        c = get_menu_choise("DOCTOR MANAGEMENT,SPECIALTY MANAGEMENT,PATIENT MANAGEMENT,HISTORY PATIENT,HISTORY DOCTOR,STOCK MANAGEMENT,PHARMACY MANAGEMENT", 1);
        switch (c)
        {
        case 1:
            sub_sub_menu_1_doctor_management();
            break;
        case 2:
            sub_sub_menu_2_spec_management();
            break;
        case 3:
            sub_sub_menu_3_Patient_management();
            break;

        case 4:
            Hospital->patientHistory();
            _pause();
            break;
        case 5:
            Hospital->doctorsHistory();
            _pause();
        case 6:
            sub_sub_menu_4_stk_management();
            break;
        case 7:
            sub_sub_menu_5_pharmacy_management();
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
        c = get_menu_choise("ATTEND,EDIT,VEIW", 1);
        switch (c)
        {
        case 1:
            Hospital->BeAttend();
            _pause();
            break;
        case 2:
            Hospital->editDoctor();
            _pause();
            break;
        case 3:
            Hospital->viewDoctor();
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

void sub_sub_menu_3_Appointement()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> PATIENT HUB -> APPOINTMENT ....");
        c = get_menu_choise("BOOK,VIEW,CANCEL", 2);
        switch (c)
        {
        case 1:
            Hospital->addAppointment();
            _pause();
            break;

        case 2:
            Hospital->viewAPP();
            _pause();
            break;

        case 3:
            Hospital->cancelAPP();
            _pause();
            break;

        /*case 3:
            //edit --> doctor id , period , day and date , patient id , prescription values
            _pause();
            break;*/

        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_4_View()
{
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> PATIENT HUB -> VIEW ....");
        c = get_menu_choise("ALL DOCTORS,SPECIFIC SPECIALIZATION,SEARCH BY NAME", 2);
        switch (c)
        {
        case 1:
            Hospital->viewAvailableDoctors();
            _pause();
            break;

        case 2:
            Hospital->printSpecDoctors();
            _pause();
            break;
        case 3:
            Hospital->Doctors_SearchByName();
            _pause();
            break;

        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

void sub_sub_menu_patientHub_pharmacy()
{
        int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> PATIENT HUB -> PHARMACY HUB  ....");
        c = get_menu_choise("ORDER MEDECINE,EDIT ORDER,CANCEL ORDER,SHOW SPECIFIC ORDER", 1);
        switch (c)
        {
        case 1:
            OrderList->addOrder(Hospital, stk);
            _pause();
            break;

        case 2:
            {
                string id;
                do
                {
                    cout<<"Enter Order ID To edit : ";
                    cin>>id;
                }while (!IsValid(id,'1'));
                int index = OrderList->searchOrder(stoi(id));
                if (index != -1)
                    OrderList->editOrder(index);
                else
                    cout<<"There is no order ID :(\n";
            }
            _pause();
            break;

        case 3:
            {
                string id;
                do
                {
                    cout<<"Enter Order ID To remove : ";
                    cin>>id;
                }while (!IsValid(id,'1'));
                OrderList->removeOrder(stoi(id));
                _pause();
                }
            break;

        case 4:
            {
                string id;
                do
                {
                    cout<<"Enter Order ID To Show : ";
                    cin>>id;
                }while (!IsValid(id,'1'));
                int index = OrderList->searchOrder(stoi(id));

                if (index != -1)
                    OrderList->printSpecificOrder(index);
                else
                    cout<<"There is ID isn't exist :(\n";
            _pause();
            }
            break;
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
        c = get_menu_choise("CREATE ACCOUNT,EDIT ACCOUNT INFORMATION,APPOINTMENT,VIEW,PHARMACY MANAGEMENT", 1);
        switch (c)
        {
        case 1:
            Hospital->addPatient();
            _pause();
            break;
        case 2:
            Hospital->editPatient();
            _pause();
            break;

        case 3:
            sub_sub_menu_3_Appointement();
            break;

        case 4:
            sub_sub_menu_4_View();
            break;

        case 5:
            sub_sub_menu_patientHub_pharmacy();
            _pause();
            break;

        case 0:
            return;

        default:
            print_try_again();
        }
    }
}

void sub_menu_4_pharmacy_hub()
{

    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU -> PHARMACY HUB ....");
        c = get_menu_choise("ADMIN HUB,PATIENT HUB", 1);
        switch (c)
        {
        case 1:
            sub_sub_menu_5_pharmacy_management();
            _pause();
            break;


        case 2:
            sub_sub_menu_patientHub_pharmacy();
            _pause();
            break;

        case 0:
            return;
        default:
            print_try_again();
        }
    }
}

/***
 *
 *
 *    FFFFFFFFFFFFFFFFFFFFFF                      iiii               CCCCCCCCCCCCClllllll   iiii                      iiii                              SSSSSSSSSSSSSSS                                                    tttt
 *    F::::::::::::::::::::F                     i::::i           CCC::::::::::::Cl:::::l  i::::i                    i::::i                           SS:::::::::::::::S                                                ttt:::t
 *    F::::::::::::::::::::F                      iiii          CC:::::::::::::::Cl:::::l   iiii                      iiii                           S:::::SSSSSS::::::S                                                t:::::t
 *    FF::::::FFFFFFFFF::::F                                   C:::::CCCCCCCC::::Cl:::::l                                                            S:::::S     SSSSSSS                                                t:::::t
 *      F:::::F       FFFFFF    cccccccccccccccciiiiiii       C:::::C       CCCCCC l::::l iiiiiii nnnn  nnnnnnnn    iiiiiii     cccccccccccccccc     S:::::S            yyyyyyy           yyyyyyy    ssssssssss   ttttttt:::::ttttttt        eeeeeeeeeeee       mmmmmmm    mmmmmmm
 *      F:::::F               cc:::::::::::::::ci:::::i      C:::::C               l::::l i:::::i n:::nn::::::::nn  i:::::i   cc:::::::::::::::c     S:::::S             y:::::y         y:::::y   ss::::::::::s  t:::::::::::::::::t      ee::::::::::::ee   mm:::::::m  m:::::::mm
 *      F::::::FFFFFFFFFF    c:::::::::::::::::c i::::i      C:::::C               l::::l  i::::i n::::::::::::::nn  i::::i  c:::::::::::::::::c      S::::SSSS           y:::::y       y:::::y  ss:::::::::::::s t:::::::::::::::::t     e::::::eeeee:::::eem::::::::::mm::::::::::m
 *      F:::::::::::::::F   c:::::::cccccc:::::c i::::i      C:::::C               l::::l  i::::i nn:::::::::::::::n i::::i c:::::::cccccc:::::c       SS::::::SSSSS       y:::::y     y:::::y   s::::::ssss:::::stttttt:::::::tttttt    e::::::e     e:::::em::::::::::::::::::::::m
 *      F:::::::::::::::F   c::::::c     ccccccc i::::i      C:::::C               l::::l  i::::i   n:::::nnnn:::::n i::::i c::::::c     ccccccc         SSS::::::::SS      y:::::y   y:::::y     s:::::s  ssssss       t:::::t          e:::::::eeeee::::::em:::::mmm::::::mmm:::::m
 *      F::::::FFFFFFFFFF   c:::::c              i::::i      C:::::C               l::::l  i::::i   n::::n    n::::n i::::i c:::::c                         SSSSSS::::S      y:::::y y:::::y        s::::::s            t:::::t          e:::::::::::::::::e m::::m   m::::m   m::::m
 *      F:::::F             c:::::c              i::::i      C:::::C               l::::l  i::::i   n::::n    n::::n i::::i c:::::c                              S:::::S      y:::::y:::::y            s::::::s         t:::::t          e::::::eeeeeeeeeee  m::::m   m::::m   m::::m
 *      F:::::F             c::::::c     ccccccc i::::i       C:::::C       CCCCCC l::::l  i::::i   n::::n    n::::n i::::i c::::::c     ccccccc                 S:::::S       y:::::::::y       ssssss   s:::::s       t:::::t    tttttte:::::::e           m::::m   m::::m   m::::m
 *    FF:::::::FF           c:::::::cccccc:::::ci::::::i       C:::::CCCCCCCC::::Cl::::::li::::::i  n::::n    n::::ni::::::ic:::::::cccccc:::::c     SSSSSSS     S:::::S        y:::::::y        s:::::ssss::::::s      t::::::tttt:::::te::::::::e          m::::m   m::::m   m::::m
 *    F::::::::FF            c:::::::::::::::::ci::::::i        CC:::::::::::::::Cl::::::li::::::i  n::::n    n::::ni::::::i c:::::::::::::::::c     S::::::SSSSSS:::::S         y:::::y         s::::::::::::::s       tt::::::::::::::t e::::::::eeeeeeee  m::::m   m::::m   m::::m
 *    F::::::::FF             cc:::::::::::::::ci::::::i          CCC::::::::::::Cl::::::li::::::i  n::::n    n::::ni::::::i  cc:::::::::::::::c     S:::::::::::::::SS         y:::::y           s:::::::::::ss          tt:::::::::::tt  ee:::::::::::::e  m::::m   m::::m   m::::m
 *    FFFFFFFFFFF               cccccccccccccccciiiiiiii             CCCCCCCCCCCCClllllllliiiiiiii  nnnnnn    nnnnnniiiiiiii    cccccccccccccccc      SSSSSSSSSSSSSSS          y:::::y             sssssssssss              ttttttttttt      eeeeeeeeeeeeee  mmmmmm   mmmmmm   mmmmmm
 *                                                                                                                                                                            y:::::y

 */
/** MAIN FUNCTION **/

int main()
{
    system("Color 06");
      cout    << "\n\n\n\n\t\t\t           \x02\x03 [Fci Clinic System] \x02\x03 \n";
      cout    << "\t\t\t           -------------------------\n\n"
              << "\t\t\t                 _ _.-'`-._ _\n"
              << "\t\t\t                ;.'________'.;\n"
              << "\t\t\t     _________n.[____________].n_________\n"
              << "\t\t\t    |\"\"_\"\"_\"\"_\"\"||==||==||==||\"\"_\"\"_\"\"_\"\"|\n"
              << "\t\t\t    |\"\"\"\"\"\"\"\"\"\"\"\"||..||..||..||\"\"\"\"\"\"\"\"\"\"|\n"
              << "\t\t\t    |LI LI LI LI||LI||LI||LI||LI LI LI LI|\n"
              << "\t\t\t    |.. .. .. ..||..||..||..||.. .. .. ..|\n"
              << "\t\t\t    |LI LI LI LI||LI||LI||LI||LI LI LI LI|\n"
              << "\t\t\t ,,;;,;;;,;;;,;;;,;;;,;;;,;;;,;;,;;;,;;;,;;,\n"
              << "\t\t\t;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n";
      cout<<"\n\n\t     1- Mohamed        2- Abdelrahman        3- Ezz        4- Mohy        5- Chat Gpt"<<endl;

      _pause();
        Sleep(3000);
    system("Color 03");
    Hospital->load();
    stk->addMedcinInStockByFiles();
    printline("START APPLICATION ....", 1);
    wait_or_clear(1, 1);
    int c = -1;
    while (c != 0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMAIN MENU ....", 1);
        c = get_menu_choise("ADMIN HUB,DOCTOR MANAGEMENT,PATIENT MANAGEMENT,PHARMACY MANAGEMNET",
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
            sub_menu_4_pharmacy_hub();
            break;

        /*case 5:
            cout<<*Hospital;
            _pause();
            break;*/
        case 0:
            printline("\n\n\a\t\t\tGoodbye \x03\x02......\n\n\n\n\n\n", 1);
            break;
        //
        default:
            print_try_again();
            wait_or_clear(3, true);
        }
    }
    Hospital->save();
    stk->saveInfo();
    return 0;
}
