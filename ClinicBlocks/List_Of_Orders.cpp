#include "List_Of_Orders.h"
#include <iostream>
using namespace std;
List_Of_Orders::List_Of_Orders() {
    capacity = 10; // Initial capacity
    size = 0;
    orders = new Order[capacity];

}
/**
List_Of_Orders::List_Of_Orders(Admin*a,Stock&s) {
    capacity = 10; // Initial capacity
    size = 0;
    orders = new Order[capacity];

}**/

List_Of_Orders::~List_Of_Orders() {
    delete[] orders;
}

void List_Of_Orders::addOrder(Stock*s,Admin*a)
{

ptrAdmin=&a;
ptrStock=&s;

if(ptrAppointment->!=-1)
{
   if(orders[c_orders].CreateOrderInsideClinic(ptrStock,ptrAdmin))
   {
       c_orders++;

   }
}
else


}

void List_Of_Orders::removeOrder(int orderId) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (orders[i].getOrderId() == orderId) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            orders[i] = orders[i + 1];
        }
        size--;
    }
}

void List_Of_Orders::printAllOrders() {
    for (int i = 0; i < size; i++) {
        cout << orders[i] << endl;
    }
}

// Other function implementations you may need for manipulating the list of orders
