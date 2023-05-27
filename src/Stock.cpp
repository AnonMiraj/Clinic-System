#include "Stock.h"

using namespace std;

Stock::Stock(): c_MedcinList(0) 
{
    MedcinList = new Medcin [100];
}

Stock::~Stock()
{
    delete[] MedcinList;
}

// Function to add a medicine to stock
void Stock::addMedcinInStock()
{
    cout << "Enter the details of the medicine to add to stock:" << endl;

    int medcinid;

    cin >> medcinid;
    cin.ignore();

    // Check if the medicine already exists in stock
    for (int i = 0; i < c_MedcinList; ++i)
    {
        if (MedcinList[i].getId() == medcinid)
        {
            cout << "Medicine already exists in stock. " << endl;
            cout << "do You Want To Update: ";
            char ch;
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                int quantity;
                cout << "Enter the additional quantity: ";
                cin >> quantity;
                cin.ignore();

                MedcinList[i].setQuntitiy(/*MedcinList[i].getQuntitiy()*/ quantity);
            } 

            return;
        }
    }

    // Medicine does not exist in stock, add it

    MedcinList[c_MedcinList].setId(medcinid);
    cin >> MedcinList[c_MedcinList++];

    // add and increase counter

    cout << "Medicine added to stock." << endl;
}

// Function to edit a medicine in stock
void Stock::editMedcin()
{
    cout << "Enter  ID of the medicine to edit:" << endl;

    int medcinid;
    cin >> medcinid;

    int index = SearchId(medcinid);

        if (index!=-1)
        {
            cout << MedcinList[index];
            MedcinList[index].Edit();
            cout << "Medicine details updated." << endl;
            return;
        }

    cout << "Medicine not found in stock." << endl;
}

// Function to delete a medicine from stock
void Stock::deleteMecinFromStock()
{
    int id;
    cout << "Enter id of the medicine to delete:" << endl;
    cin >> id;
    int index = SearchId(id);
    if (index != -1)
    {
        cout << MedcinList[index];
        cout << "Are You Sure To Delete This ?![y/n]";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            // if user sure then i will delete medcin and -- of counter
            cout << "^_^ Was Deleted Successfully ^_^" << endl;

            swap(MedcinList[index], MedcinList[c_MedcinList]);
            //MedcinList[index] = MedcinList[c_MedcinList];
            c_MedcinList--;
            return;
        }
    }
    cout << "This Id Not Exist ): " << endl;
}

int Stock::getQuntitiy(int id)
{
    int index;
    index=SearchId(id);
    if (index != -1)
    {
        return MedcinList[index].getQuntitiy();
    }
    cout << "This Quntitiy isn't Exist" << endl;

    return -1;
 
}

int Stock::SearchId(int id)
{
    for (int i = 0; i < c_MedcinList; i++)
    {
        if (id == MedcinList[i].getId())
        {
            return i;
        }
    }
    return -1;
}
  
ostream& operator<<(ostream& out, const Stock& stock)
{
    // TODO: insert return statement here
    for (int i = 0; i < stock.c_MedcinList; i++)
    {
        out << "+--------------------------------+";
        out << stock.MedcinList[i];
        out << "+--------------------------------+";

    }
    return out;
}
