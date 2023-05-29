#include "Transaction.h"
Transaction::Transaction() {
	p = new Payment*[50];
    counter = -1;
}
void Transaction::Set_Payment(){
    int choice;
    do {
        system("cls");
        cout << "Choose any approach payment.\n";
        cout << "****************************\n";
        cout << "1)Cash.\n";
        cout << "2)Credit.\n";
        cout << "3)Check.\n";
        cout << "0)Exit.\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            p[++counter] = new Cash();
            Handle_Pyment();
            break;
        case 2:
            p[++counter] = new Credit();
            Handle_Pyment();
            break;
        case 3:
            p[++counter] = new Check();
            Handle_Pyment();
            break;
        case 0:
            return;
        default:
            cout << "------------------< INVALED CHOICE >-----------------\n";
            system("pause");
        }
    } while (true);
}
void Transaction::Handle_Pyment() {
    int choice;
    do {
        system("cls");
        cout << "Choose your choice.\n";
        cout << "*******************\n";
        cout << "1)Pay.\n";
        cout << "2)Update.\n";
        cout << "0)Exit.\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            p[counter]->Pay();
            cout << "**************************************************\n";
            cout << "===> The Payment has Copmeleted successfully (^_^)\n";
            cout << "**************************************************\n";
            system("pause");
            break;
        case 2:
            system("cls");
            p[counter]->Update();
            break;
        case 0:
            return;
        default:
            cout << "------------------< INVALED CHOICE >-----------------\n";
            system("pause");
        }
    } while (true);
}

Transaction::~Transaction() {
    for (auto i = 0;i < counter;++i) delete p[i];
    delete []p;
}