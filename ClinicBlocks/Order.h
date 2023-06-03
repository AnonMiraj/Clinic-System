#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "Stock.h"
#include "OrderItem.h"
#include "admin.h"
#include <string>
#include<conio.h>
#include <ctime>
#include "appointment.h"
using namespace std;

enum ORDERSTATUS { PENDING, PAID, COMPLETED, CANCELED };

class Order {
private:

    string status;
    string NameOfPatient;
    string NameOfdoctor;
    string date;

    bool inside;/// check if patient inside or outside clinic
    int OrderID;
    int number;
    int totalPrice;
    int c_orderItem;
    int PatientID;
    int DoctorId;
    static int ord_id;

    Stock* stk;
    orderItem* items;
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
    bool CreateOrderInsideClinic(Stock* s,Admin*a,int id,int index);
    bool CreateOrderOutsideClinic(Stock* s,Admin*a,int id,int index);
    bool CreateOrder(Stock* s,Admin*a);



    void AddOrderItem(orderItem* item);
    void UpdateOrderStatus(ORDERSTATUS status);
    void EditOrder(int itemId);
    void RemoveOrderItem(int itemId);

    ///Print
    void printOrder();
    void printOrderofPatientInsideClinic();
    void printOrderofPatientOutsideClinic();

    /// Overloading Opetator for cin and cout ^_^ (:

    friend istream& operator>>(istream& in, Order& r);
    friend ostream& operator<<(ostream& out, Order& r);
};

#endif
