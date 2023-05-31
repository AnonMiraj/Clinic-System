#include "Stock.h"

using namespace std;

Stock::Stock(): c_MedcinList(0) 
{
    MedcinList = new Medcin[100];
    input.open("inputMedcin.txt");
    if (!input)
    {
        cout << "File Can Not Be Open ):" << endl;
        system("pause");
    }
    //output.open("outputMedcin.txt");
    Quntitiy = new int[100];

}

Stock::~Stock()
{
    delete[] MedcinList;
    input.close();
}


void Stock::setQuantity(int Q,int index)
{
    Quntitiy[index] = Q;
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
                cout << "Enter the additional quantity: ";
                cin>>Quntitiy[c_MedcinList];
            } 

            return;
        }
    }

    // Medicine does not exist in stock, add it

    MedcinList[c_MedcinList].setId(medcinid);
    cin >> MedcinList[c_MedcinList++];

    // add and increase counter

    cout << "^_^ Medicine Successfully Added To Stock. ^_^" << endl;
}

void Stock::addMedcinInStockByFiles()
{

    int id, price;
    string name, brand;

    while (c_MedcinList <100 && input >> id)
    {

        input.ignore();
        getline(input, name);
        getline(input, brand);
        input >> price;
        input >> Quntitiy[c_MedcinList];
        MedcinList[c_MedcinList] = Medcin(id, name, brand, price);

        c_MedcinList++;
    }
}

// Function to edit a medicine in stock
void Stock::editMedcin()
{
    cout << "Enter  ID of the medicine You Want To Edit:" << endl;
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
        return Quntitiy[index];
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
        out << "+------------------------------------+"<<endl;
        out << stock.MedcinList[i];
        out << "| Quntitiy: " << setw(24) << setfill(' ') << stock.Quntitiy[i] << " |" << endl;
        out << "+------------------------------------+" << endl;

    }
    return out;
}
