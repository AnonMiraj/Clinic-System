#include "Stock.h"
#include "other.h"

using namespace std;

Stock::Stock(): c_MedcinList(0)
{
    MedcinListSize=100;
    MedcinList = new Medcin[MedcinListSize];
    //output.open("outputMedcin.txt");

    Quntitiy = new int[MedcinListSize];

}

Stock::~Stock()
{
    delete[] MedcinList;
}


void Stock::setQuantity(int q,int index)
{
    Quntitiy[index] = q;
}
double Stock::getSalePriceOfMedcin(int index)
{
    return MedcinList[index].getPrice();
}
// Function to add a medicine to stock
void Stock::addMedcinInStock()
{

    cout << "Enter the details of the medicine to add to stock:" << endl;

    p:
        system("Color 03");
    int medcinid;
    cout<<"Enter  Medcin Id You Want To Add: ";
    cin >> medcinid;
    cin.ignore();

    // Check if the medicine already exists in stock
    for (int i = 0; i < c_MedcinList; ++i)
    {
        if (MedcinList[i].getId() == medcinid)
        {
            cout << "Medicine already exists in stock. " << endl;
            cout << "do You Want To Update Quntitiy of This Id or Try Again: "<<endl;
            v:
            system("Color 03");
            cout<<" 1- Update His Quntitiy \n 2- Try Again";

            string ch;
            cin >> ch;
            if (ch=="1")
            {
                cout << "Enter quantity: ";
                cin>>Quntitiy[i];
                cout<<"Has Updated In Stock Successfully"<<endl;



            }
            else if(ch=="2")
                goto p;
            else {
                system("Color 04");
                system("cls");
                cout<<"Enter A Valid Choise!!!!"<<endl;
                Sleep(2500);
                goto v;
            }

            return;
        }
    }

    // Medicine does not exist in stock, add it

    MedcinList[c_MedcinList].setId(medcinid);
    cin >> MedcinList[c_MedcinList];
    cout << "Enter quantity: ";
    cin>>Quntitiy[c_MedcinList++];
    // add and increase counter

    cout << "^_^ Medicine Successfully Added To Stock. ^_^" << endl;
}
int Stock::getMedcinListCount(){
  return c_MedcinList;
}

void Stock::addMedcinInStockByFiles()
{
    ifstream input("./data/inputMedcin.txt");
    if (!input)
    {
        cout << "File Can Not Be Open ):" << endl;
        _pause();
    }


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
      input.close();

}
void Stock::saveInfo(){
    ofstream oput("../data/inputMedcin.txt");
    if (!oput)
    {
        cout << "File Can Not Be Open ):" << endl;
        _pause();
    }


    for (int i=0; i<c_MedcinList ; i++) {

    oput<<MedcinList[i].getId()<<endl;
    oput<<MedcinList[i].getName()<<endl;
    oput<<MedcinList[i].getBrand()<<endl;
    oput<<MedcinList[i].getPrice()<<endl;
    oput<<Quntitiy[i]<<endl;

    }
      oput.close();


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
            system("Color 02");

            cout << "Medicine details Updated." << endl;
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
            /// if user sure then i will delete medcin and -- of counter
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
        //cout<<"Ahmed Mohsen";
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
int Stock::SearchIdByName(string med){
  for (int i=0 ; i<c_MedcinList ; i++) {
    if (MedcinList[i].getName()==med) {
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
