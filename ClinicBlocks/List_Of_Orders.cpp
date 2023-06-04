#include "List_Of_Orders.h"
#include <iostream>

List_Of_Orders::List_Of_Orders()
{
    orders = nullptr;
    size = 0;
    capacity = 0;
    c_orders = 0;
    ptrAdmin = nullptr;
    ptrStock = nullptr;
    ptrAppointment = nullptr;
}



List_Of_Orders::~List_Of_Orders()
{
    delete[] orders;
}

void List_Of_Orders::addOrder(Admin*Hospital,Stock*s)
{

    if (capacity == 0)
    {
        capacity = 10;
        orders = new Order[capacity];
    }
    else if (size == capacity)
    {
        capacity *= 2;
        Order* new_orders = new Order[capacity];
        for (int i = 0; i < size; i++)
        {
            new_orders[i] = orders[i];
        }
        delete[] orders;
        orders = new_orders;
    }


    if(orders[c_orders].CreateOrder(s,Hospital))/// If Create Order Successfully We increase counter of list
    {
        c_orders++;
    }

}

void List_Of_Orders::removeOrder(int id)
{
//    for (int i = 0; i < c_orders; i++)
//    {
//        if (orders[i].getOrderId() == orderId)
//        {
//            // Shift the remaining orders to fill the gap
//            for (int j = i; j < c_orders - 1; j++)
//            {
//                orders[j] = orders[j + 1];
//            }
//            size--;
//            c_orders--;
//            break;
//        }
//    }

    int index=orders->searchIdItems(id);
    int itemid;
    cout<<"Enter id of item: ";
    cin>>itemid;
    orders[index].RemoveOrderItem(itemid);
}
void List_Of_Orders::cancleOrder(int id)
{

}
void List_Of_Orders::printSpecificOrder(int i)
{
    orders[i].printOrder();
}

void List_Of_Orders::printAllOrders()
{
    for(int i=0; i<c_orders; i++)
    {
        orders[i].printOrder();
    }
}

int List_Of_Orders::searchOrder(int id)
{
    for (int i=0; i<c_orders; i++)
        if (orders[i].getOrderId() == id)
            return i;
    return -1;
}

void List_Of_Orders::editOrder(int i)
{
    string id;
    do
    {
        cout<<"Enter Order item ID To edit : ";
        cin>>id;
    }
    while (!IsValid(id,'1'));
    orders[i].EditOrder(stoi(id));
}
