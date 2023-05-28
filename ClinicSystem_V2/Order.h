#ifndef ORDER_H
#define ORDER_H
#include<conio.h>
#include <iostream>
#include <string>
#include "Stock.h"
#include "OrderItem.h"
#include <ctime>
//#include "ListOfCustomers.h"

using namespace std;

enum ORDERSTATUS { PENDING, PAID, COMPLETED,CANCELED };

class Order {
private:
    string date;
    int OrderID;
    int number;
    string status;
    int totalPrice;
    Stock *stk;
    orderItem** items;
    int c_orderItem;
    string NameOfPatient;
    int PatientID;
    string NameOfdoctor;
public:

    Order();
    Order(int orderId, int num, string orderStatus, int total, string PatientName);
    ~Order();
    // Getter
    string getDate()const;
    int getOrderId() const;
    int getNumber() const;
    string getStatus() const;
    int getTotalPrice() const;
    string getNameOfCustomer() const;
    // Setter
    void setDate();
    void setOrderId(int id);
    void setNumber(int num);
    void setStatus(ORDERSTATUS orderStatus);
    void setTotalPrice(int total);
    void setNameOfPatient(string customerName);
    // Another 
    
    //int calcTotalPiceOfOrder();
    int searchIdItems(int id);
    void CreateOrder(Stock& stock);
    void AddOrderItem(orderItem* item);
    void UpdateOrderStatus(ORDERSTATUS status);
    void EditOrder(int itemId);
    void RemoveOrderItem(int itemId);
    // Overloading Opetator for cin and cout ^_^ (:
    friend istream& operator>>(istream& in, Order& r);
    friend ostream& operator<<(ostream& out, Order& r);
};

#endif  // ORDER_H
