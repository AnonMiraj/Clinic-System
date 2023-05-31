#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "Stock.h"
#include "OrderItem.h"
#include "Admin.h"
#include <string>
#include<conio.h>
#include <ctime>

using namespace std;

enum ORDERSTATUS { PENDING, PAID, COMPLETED, CANCELED };

class Order {
private:

    string status;
    string NameOfPatient;
    string NameOfdoctor;
    string date;

    int OrderID;
    int number;
    int totalPrice;
    int c_orderItem;
    int PatientID;
    int DoctorId;

    Stock* stk;
    orderItem** items;
    Admin* ptrAdmin;
public:

    Order();
    Order(int orderId, int num, string orderStatus, int total, string PatientName);
    ~Order();

    /// Getter
    string getDate()const;
    string getStatus() const;
    string getPatentName()const;
    string getDoctorName()const;
    int getOrderId() const;
    int getNumber() const;
    int getTotalPrice() const;
    int getPatientId()const;
    int getDoctorId()const;

    /// Setter
    void setDate();
    void setOrderId(int id);
    void setNumber(int num);
    void setStatus(ORDERSTATUS orderStatus);
    void setTotalPrice(int total);
    void setNameOfPatient(string Patentname);
    void setPatientIdInOrder(int id);
    void setNameOfDoctor(string name);
    void setDoctorIdInOrder(int id);

    /// Another

    ///int calcTotalPiceOfOrder();
    int searchIdItems(int id);
    void CreateOrderInsideClinic(Stock& stock,Admin&a);
    void CreateOrderOutsideClinic(Stock& stock,Admin&a);
    void AddOrderItem(orderItem* item);
    void UpdateOrderStatus(ORDERSTATUS status);
    void EditOrder(int itemId);
    void RemoveOrderItem(int itemId);

    ///Print

    /// Overloading Opetator for cin and cout ^_^ (:

    friend istream& operator>>(istream& in, Order& r);
    friend ostream& operator<<(ostream& out, Order& r);
};

#endif
