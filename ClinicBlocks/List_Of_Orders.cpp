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


    if(orders[c_orders].CreateOrder(s,Hospital))/// If Create Order Successfully We increse counter of list
    {
        c_orders++;

    }

}

void List_Of_Orders::removeOrder(int orderId)
{
    for (int i = 0; i < size; i++)
    {
        if (orders[i].getOrderId() == orderId)
        {
            // Shift the remaining orders to fill the gap
            for (int j = i; j < size - 1; j++)
            {
                orders[j] = orders[j + 1];
            }
            size--;
            c_orders--;
            break;
        }
    }
}

void List_Of_Orders::printAllOrders()
{
    for(int i=0; i<c_orders; i++)
    {
        orders[i].printOrder();
    }
}
