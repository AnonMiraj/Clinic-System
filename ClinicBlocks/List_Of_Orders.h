#ifndef LIST_OF_ORDERS_H
#define LIST_OF_ORDERS_H

#include "Order.h"

class List_Of_Orders {
private:
    Order* orders;
    int size;
    int capacity;

public:
    List_Of_Orders();
    ~List_Of_Orders();

    void addOrder(const Order& order);
    void removeOrder(int orderId);
    void printAllOrders();

    // Other functions you may need for manipulating the list of orders
};

#endif
