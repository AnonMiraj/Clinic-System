#ifndef LIST_OF_ORDERS_H
#define LIST_OF_ORDERS_H
#include "admin.h"
#include "Stock.h"
#include "Order.h"
#include "other.h"
#include <string>
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
    ~List_Of_Orders();

    void addOrder(Admin*ptr,Stock*s);
    void removeOrder(int orderId);
    void printSpecificOrder(int);
    void printAllOrders();
    int searchOrder(int id);
    void editOrder(int);

};

#endif

