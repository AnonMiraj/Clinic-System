#include "Cash.h"
Cash::Cash()
{
    CashValue = 0.0;
}
Cash::Cash(double c)
{
    Set_Cash(c);
}
void Cash::Set_Cash(double c) { (*this).CashValue = c; }
Cash& Cash::Get_Cash() { return *this; }
///Pay
void Cash::Pay() {
    cout << "1)Cash.\n";
    cout << "*********\n";
    Payment::Pay();
    cout << "Enter the CashValue : ";
    cin >> CashValue;
}
istream& operator >> (istream& in, Cash& c) {
    cout << "1)Cash.\n";
    cout << "*********\n";
    c.Pay();
    cout << "Enter the CashValue : ";
    in >> c.CashValue;
    return in;
}
///Update
void Cash::Update() {
    int c = 0;
    char ch;
    do{
        system("cls");
        Payment::Update();
        cout << "3)update CashValue.\n";
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
            cout << "Enter the CashValue Updated : ";
            cin >> CashValue;
            break;
        case 0:
            return;
        default:
            cout << "--------< INVALID CHOICE(-_-) >--------\n";
            system("pause");
        }
    } while (true);
}
Cash::~Cash()
{

}
