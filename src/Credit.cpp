#include "Credit.h"
Credit::Credit()
{
    numberCredit = "unknown";
    typeCredit = "unknown";

}
Credit::Credit(const char* s1, const char* s2)
{
    set_numberCredit(s1);
    set_typeCredit(s2);
}
///set
void Credit::set_numberCredit(const char* s) { (*this).numberCredit = s; }
void Credit::set_typeCredit(const char* s) { (*this).typeCredit = s; }
///get
Credit& Credit::get_numberCredit()  { return *this; }
Credit& Credit::get_typeCredit()  { return *this; }
///pay
void Credit::Pay() {
    cout << "2)Credit.\n";
    cout << "***********\n";
    Payment::Pay();
    cout << "Enter the numberCredit : ";
    cin >> numberCredit;
    cin.ignore();
    cout << "Enter the typeCredit : ";
    getline(cin, typeCredit);
}
istream& operator >> (istream& in, Credit& cr) {
    cout << "2)Credit.\n";
    cout << "***********\n";
    cr.Pay();
    cout << "Enter the numberCredit : ";
    in >> cr.numberCredit;
    cout << "Enter the typeCredit : ";
    getline(in, cr.typeCredit);
    cin.ignore();
    return in;
}
///update
void Credit::Update() {
    int c = 0;
    char ch;
    do {
        system("cls");
        Payment::Update();
        cout << "3)update numberCredit.\nr";
        cout << "4)update typeCredit\n";
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
            cin >> expireDate.day >> ch >> expireDate.month >> ch >> expireDate.year;
            break;
        case 3:
            cout << "Enter the numberCredit Updated : ";
            cin >> numberCredit;
            break;
        case 4:
            cout << "Enter the typeCredit updated : ";
            cin >> typeCredit;
        case 0:
            return;
        default:
            cout << "--------< INVALID CHOICE (-_-)>-------.\n";
            system("pause");
        }
    } while (true) ; 
}

Credit::~Credit()
{

}

