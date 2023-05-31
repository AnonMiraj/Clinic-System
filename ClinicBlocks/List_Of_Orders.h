#ifndef LIST_OF_ORDERS_H
#define LIST_OF_ORDERS_H
#include "Admin.h"
#include "Stock.h"
#include "Order.h"
#include "appointment.h"
class List_Of_Orders {
private:
    Order* orders;
    int size;
    int capacity;
    int c_orders;
    Admin*ptrAdmin;
    Stock*ptrStock;
    Appointment*ptrAppointment;
public:
    List_Of_Orders();
    List_Of_Orders(Admin*ptr,Stock&s);
    ~List_Of_Orders();

    void addOrder(Admin*ptr,Stock*s,Appointment *p);
    void removeOrder(int orderId);
    void printAllOrders();
    void editOrder();

};

#endif

