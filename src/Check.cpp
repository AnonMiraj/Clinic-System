#include "Check.h"

Check::Check()
{
    nameCheck   = "unknown";
    BankId = "unknown";
}
Check::Check(const char* s1, const char* s2)
{
    set_BankIdForCheck(s1);
    set_NameCheck(s2);
}
///set
void Check::set_BankIdForCheck(const char* b) { (*this).BankId = b; }
void Check::set_NameCheck(const char* n) { (*this).nameCheck = n; }
///get
Check& Check::get_BankIdForCheck()  { return *this; }
Check& Check::get_NameCheck()  { return *this; }
///pay
void Check::Pay() {
    cout << "3)Check.\n";
    cout << "*********\n";
    Payment::Pay();
    cin.ignore();
    cout << "Enter the name : ";
    getline(cin, nameCheck);
    cout << "Enter the BankId : ";
    cin >> BankId;
}
istream& operator >> (istream& in, Check& ch) {
    cout << "3)Check.\n";
    cout << "*********\n";
    ch.Pay();
    cin.ignore();
    cout << "Enter the name : ";
    getline(in, ch.nameCheck);
    cout << "Enter the BankId : ";
    in >> ch.BankId;
    return in;
}
///update
void Check::Update() {
    int c = 0;
    char ch;
    do{
        system("cls");
        Payment::Update();
        cout << "3)update name.\n";
        cout << "4)update BankId\n";
        cout << "0)Exit.\n";
        cout << "Enter the choice : ";
        cin >> c;
        switch (c) {
        case 1:
            cout << "Enter the amount Updated : ";
            cin >> amount;
            break;
        case 2:
            cout << "Enter the date Updated : ";
            cin >> date.day >> ch >> date.month >> ch >> date.year;
            break;
        case 3:
            cout << "Enter the name Updated : ";
            cin >> nameCheck;
            break;
        case 4:
            cout << "Enter the BankId updated : ";
            cin >> BankId;
        case 0:
            return;
        default:
            cout << "------INVALID CHOICE-------(-_-).\n";system("pause");
        }
    } while (true);
}
Check::~Check()
{

}

