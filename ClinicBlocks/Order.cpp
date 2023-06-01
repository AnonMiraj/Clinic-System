#include "Order.h"


Order::Order()
{
    OrderID = 0;
    number = 0;
    status = "PENDING";
    totalPrice = 0;
    NameOfPatient = "Unkwon";
    items = new orderItem*[100];
    c_orderItem = 0;
    PatientID = 0;
    DoctorId=0;
    NameOfdoctor="Unkwon";
    inside=false;

}

Order::Order(int orderId, int num, string orderStatus, int total, string customerName)
{
    OrderID = orderId;
    number = num;
    status = orderStatus;
    totalPrice = total;
    NameOfPatient = customerName;
    items = nullptr;
    c_orderItem = 0;
    PatientID = 0;
}

Order::~Order()
{
    // Clean up dynamically allocated memory for order items
    if (items != nullptr)
    {
        for (int i = 0; i < c_orderItem; i++)
        {
            delete items[i];
        }
        delete[] items;
    }
}

string Order::getDate() const
{
    return date;
}

int Order::getOrderId() const
{
    return OrderID;
}

int Order::getNumber() const
{
    return number;
}

string Order::getStatus() const
{
    return status;
}

int Order::getTotalPrice() const
{
    return totalPrice;
}

void Order::setDate()
{
    time_t rawtime;
    time(&rawtime);
    //date = ctime(&rawtime);                   //Error Here --> ):
}

void Order::setOrderId(int id)
{
    OrderID = id;
}

void Order::setNumber(int num)
{
    number = num;
}

void Order::setStatus(ORDERSTATUS s)
{

    if (s== PENDING)
    {
        status = "PENDING";
    }
    else if (s == PAID)
    {
        status = "PAID";
    }
    else if (s == COMPLETED)
    {
        status = "COMPLETED";
    }
    else if (s == CANCELED)
    {
        status = "CANCELED";
    }
}

void Order::setTotalPrice(int total)
{
    totalPrice = total;
}

void Order::setNameOfPatient(string name)         //-->> prepate to add patient
{
    NameOfPatient = name;
}
/*
int Order::calcTotalPiceOfOrder()
{
    totalPrice = 0;
    for (int i = 0; i < c_orderItem; i++)
    {
        totalPrice += items[i]->getTotalPrice();
    }
    return totalPrice;
}
*/
int Order::searchIdItems(int id)
{
    for (int i = 0; i < c_orderItem; i++)
    {
        if (items[i]->getIdOrderItem() == id)
        {
            return i;
        }
    }
    return -1;
}

bool Order::CreateOrderOutsideClinic(Stock* s,Admin*a,int idPatient,int index)
{
    /**

p:
    system("Color 03");
    stk = s;
    ptrAdmin=a;
    char ch;
    cout << "Enter Id Of Patent You Want To Add Oreder To Him: ";
    int p_id;
    cin >> p_id;
    int indexofPatient =ptrAdmin->searchPatient(p_id) ;
    if(indexofPatient=-1)
    {
        system("Color 04");
        cout<<"Srry, This Id Patient Not Exist ):"<<endl;
        cout<<"Do You Need To try Again? [Y/N]: ";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            system("cls");
            goto p;
        }
        else
            return false;
    }**/
    char ch;
    setDate();
    int id;
    cout << "Enter Id OF Order: ";
    cin >> id;

    do
    {
        cout << "Enter item Id: ";
        int id;
        cin >> id;
        if (items[c_orderItem]->setOrderItem(id, s))
        {
            setPatientIdInOrder(idPatient);

            NameOfPatient=ptrAdmin->getPatient_name(index);
            c_orderItem++;
            totalPrice += items[c_orderItem]->calcTotalPrice();
            return true;
        }
        cout << "Do You Want To Add Another Medcine [y/n] ";
        ch = _getch();
    }
    while (ch == 'y' || ch == 'Y');

    if (c_orderItem > 0)
    {
        setOrderId(id);
    }
    // }
    // else
    //  cout << "This Custmer Id Does't Exist):" << endl;

}
bool Order::CreateOrder(Stock*s,Admin*a,Appointment*appoint)
{
    p:
    char ch;
    cout << "Enter Patient Id: ";
    int idPatient;
    cin >> idPatient;

    int indexofPatient =ptrAdmin->searchPatient(idPatient);/// To Search In Array Patient And Make Sure Is This Ptient Is Exist

    if(indexofPatient=-1)
    {
        system("Color 04");
        cout<<"Srry, This Id Patient Not Exist ):"<<endl;
        cout<<"Do You Need To try Again? [Y/N]: ";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            system("cls");
            goto p;
        }
        else
            return false;
    }

    ///if(appoint->)
    ///{
        if(CreateOrderInsideClinic(s,a,idPatient,indexofPatient))
        {
            return true;
            inside=true;
        }
        else
            return false;
    ///}
    ///else
    ///{

        if(CreateOrderOutsideClinic(s,a,idPatient,indexofPatient))
        {
            return true;
            inside=false;
        }
        else
            return false;
    ///}


}
bool Order::CreateOrderInsideClinic(Stock*s,Admin*a,int p_id,int index)/// Add Discount to the patient inside the clinic
{


    system("Color 03");
    stk = s;
    ptrAdmin=a;
    char ch;

    /// To Return Enter The Value (Return Again)



v:
    int d_id;
    cout << "Enter Id Of Doctor: ";
    cin>>d_id;
    int indexofDoctor =ptrAdmin->searchDoctor(d_id) ;
    if(index=-1)
    {
        system("Color 04");
        cout<<"Srry, This Id Doctor Not Exist ):"<<endl;
        cout<<"Do You Need To try Again? [Y/N]: ";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            system("cls");
            goto v;
        }
        else
            return false;
    }

    setPatientIdInOrder(p_id);    /// To Add ID Patient In Order
    setDoctorIdInOrder(d_id);    /// To Add ID Doctor In Order

    setDate();
    int id;
    cout << "Enter Id OF Order: ";
    cin >> id;

    do
    {
        cout << "Enter item Id: ";
        int id;
        cin >> id;
        if (items[c_orderItem]->setOrderItem(id, s))
        {
            NameOfPatient=ptrAdmin->getPatient_name(index);/// index here To Patient and i recive it parametar
            NameOfdoctor=ptrAdmin->getDoctor_name(indexofDoctor);
            c_orderItem++;
            totalPrice += items[c_orderItem]->calcTotalPrice();
            return true;
        }
        cout << "Do You Want To Add Another Medcine [y/n] ";
        ch = _getch();
    }
    while (ch == 'y' || ch == 'Y');

    if (c_orderItem > 0)
    {
        setOrderId(id);
    }
}

void Order::AddOrderItem(orderItem* item)
{
    // Add the given order item to the order
    // and update the total price
    char ch;

    if (items == nullptr)
    {
        // Create a new array to store order items
        items = new orderItem * [1];
        items[0] = item;
        c_orderItem = 1;
    }
    else
    {
        // Create a new array with increased size
        orderItem** newItems = new orderItem * [c_orderItem + 1];

        // Copy existing items to the new array
        for (int i = 0; i < c_orderItem; i++)
        {
            newItems[i] = items[i];
        }

        // Add the new item to the end of the new array
        newItems[c_orderItem] = item;

        // Delete the old array
        delete[] items;

        // Update the items pointer to point to the new array
        items = newItems;
        totalPrice += items[c_orderItem]->calcTotalPrice();
        // Increment the count of order items
        c_orderItem++;

    }

    // Update the total price
}

void Order::UpdateOrderStatus(ORDERSTATUS orderStatus)
{
    // Update the order status based on the provided enum value
    switch (orderStatus)
    {
    case PENDING:
        status = "PENDING";
        break;
    case PAID:
        status = "PAID";
        break;
    case COMPLETED:
        status = "COMPLETED";
        break;
    default:
        cout << "Invalid order status!" << endl;
    }
}

void Order::EditOrder(int id)
{
    // Find the order item with the given item ID
    int index = stk->SearchId(id);
    if (index != -1)
    {
        // Prompt the user to edit the order item details
        cout << "Enter new quantity: ";
        int newQuantity;
        cin >> newQuantity;

        // Supstract the old valu
        totalPrice -= items[index]->calcTotalPrice();

        // Update the quantity of the order item
        items[index]->UpdateQuantity(newQuantity);

        // Calculate the new total price
        totalPrice+= items[index]->calcTotalPrice();

        //totalPrice += items[index]->getTotalPrice();

        cout << "Order item updated successfully." << endl;
        return;
    }

    cout << "Order item not found." << endl;
}

void Order::RemoveOrderItem(int itemId)
{
    /// Find the order item with the given item ID

    for (int i = 0; i < c_orderItem; i++)
    {
        if (items[i]->getIdOrderItem() == itemId)
        {
            /// Calculate the total price before removing the item
            int itemTotalPrice = items[i]->getTotalPrice();

            /// Delete the order item from the array
            delete items[i];

            // Shift the remaining items to fill the gap
            //for (int j = i; j < c_orderItem - 1; j++) {
            //    items[j] = items[j + 1];
            //}

            swap(items[i], items[c_orderItem-1]);
            // Decrement the count of order items
            c_orderItem--;

            // Calculate the new total price
            totalPrice -= itemTotalPrice;

            cout << "Order item removed successfully." << endl;
            return;
        }
    }

    cout << "Order item not found." << endl;
}


istream& operator>>(istream& in, Order& r)
{
    // i won't use this overloding i will use function create order
    char ch;
    int id;
    cout << "Enter Order Id: ";
    cin >> r.OrderID;
    do
    {
        cout << "Enter Item Id: ";
        in >> id;
        //if (r.items[r.c_orderItem]->setOrderItem(id))
        {
            r.c_orderItem++;
        }

        cout << "Do You Want To Add Another Item [y/n] ";
        ch = _getch();
    }
    while (ch == 'y' || ch == 'Y');

    return in;
}

ostream& operator<<(ostream& out, Order& r)
{

    out << "Order ID: " << r.OrderID << endl;
    out << "Date: " << r.date << endl;
    out << "Status: " << r.status << endl;
    out << "Total Price: " << r.totalPrice << endl;
    //out << "Name of Customer: " << r.NameOfCustomer << endl;
    cout << "Do You Need To Display Items? [Y/N]";
    char ch;
    ch = _getch();
    if(ch=='Y'||ch=='y')
    {
        out << "\"Order Items\"" << endl;
        for (int i = 0; i < r.c_orderItem; i++)
        {
            out << "Order Item " << i + 1 << ":" << endl;
            out << r.items[i] << endl;
        }
    }
    return out;
}

void Order::setPatientIdInOrder(int id)
{
    PatientID = id;
}

void Order::setNameOfDoctor(string name)
{
    this->NameOfdoctor = name;
}
void Order::setDoctorIdInOrder(int id)
{
    this->DoctorId = id;
}
string Order::getPatentName() const
{
    return NameOfPatient;
}

string Order::getDoctorName() const
{
    return NameOfdoctor;
}

int Order::getPatientId() const
{
    return PatientID;
}

int Order::getDoctorId() const
{
    return DoctorId;
}
void Order::printOrderofPatientInsideClinic()
{
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"| Name Of Patient: "<<NameOfPatient<<"\tPatient Id: "<<PatientID<<" |"<<endl;
    cout<<"| Name Of Doctor: "<<NameOfPatient<<"\tDoctor Id: "<<DoctorId<<" |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<*this;   /// To Print Object Who Call The Function
}
void Order::printOrderofPatientOutsideClinic()
{
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"| Name Of Patient: "<<NameOfPatient<<"\tPatient Id: "<<PatientID<<" |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<*this;   /// To Print Object Who Call The Function

}
void Order::printOrder()
{
    if(inside)
    {
        printOrderofPatientInsideClinic();
    }
    else
        printOrderofPatientOutsideClinic();
}
