#ifndef LIST_OF_ORDERS_H
#define LIST_OF_ORDERS_H
#include "Admin.h"
#include "Stock.h"
#include "Order.h"

class List_Of_Orders {
private:
    Order* orders;
    int size;
    int capacity;
    int c_orders;
    Admin*ptrAdmin;
    Stock*ptrStock;

public:
    List_Of_Orders();
    List_Of_Orders(Admin*ptr);
    ~List_Of_Orders();

    void addOrder(Stock*s,Admin*ptr);
    void removeOrder(int orderId);
    void printAllOrders();

    // Other functions you may need for manipulating the list of orders
};

#endif
