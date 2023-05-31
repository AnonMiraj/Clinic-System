#include "Order.h"

Order::Order() {
    OrderID = 0;
    number = 0;
    status = "PENDING";
    totalPrice = 0;
    NameOfCustomer = "Unkwon";
    items = new orderItem*[100];
    c_orderItem = 0;
    CustomerID = 0;
}

Order::Order(int orderId, int num, string orderStatus, int total, string customerName, Stock& stock) {
    OrderID = orderId;
    number = num;
    status = orderStatus;
    totalPrice = total;
    NameOfCustomer = customerName;
    stk = &stock;
    items = nullptr;
    c_orderItem = 0;
    CustomerID = 0;
}

Order::~Order() {
    // Clean up dynamically allocated memory for order items
    if (items != nullptr) {
        for (int i = 0; i < c_orderItem; i++) {
            delete items[i];
        }
        delete[] items;
    }
}

string Order::getDate() const
{
    return date;
}

int Order::getOrderId() const {
    return OrderID;
}

int Order::getNumber() const {
    return number;
}

string Order::getStatus() const {
    return status;
}

int Order::getTotalPrice() const {
    return totalPrice;
}

string Order::getNameOfCustomer() const {
    return NameOfCustomer;
}

void Order::setDate()
{
    time_t rawtime;
    time(&rawtime);
    //date = ctime(&rawtime);
}

void Order::setOrderId(int id) {
    OrderID = id;
}

void Order::setNumber(int num) {
    number = num;
}

void Order::setStatus(ORDERSTATUS s) {

    if (s== PENDING)
    {
        status = "PENDING";
    }
    else if (s == PAID)
    {
        status = "PAID";
    }
    else if (s == COMPLETED)
    {
        status = "COMPLETED";
    }
    else if (s == CANCELED)
    {
        status = "CANCELED";
    }
}

void Order::setTotalPrice(int total) {
    totalPrice = total;
}

void Order::setNameOfCustomer(string customerName) {//-->>
    NameOfCustomer = customerName;
}

void Order::CreateOrder(Stock& s) {
    
    stk = &s;
    char ch;
    cout << "Enter Id Of Custmer You Want To Add Oreder To Him: ";
    int cusid;
    cin >> cusid;
    //int indexofcustmer = l.SearchCustmerByID(cusid);

    //if (indexofcustmer != -1)
   //{
       // setCoustmerId(cusid);
        int id;
        cout << "Enter Id OF Order: ";
        cin >> OrderID;

        //setOrderId(OrderId);

        do {
            cout << "Enter item Id: ";
            int id;
            cin >> id;
            if (items[c_orderItem]->setOrderItem(id, s))
            {
                c_orderItem++;
            }
            cout << "Do You Want To Add Another Item [y/n] ";
            cin>>ch;
        } while (ch == 'y' || ch == 'Y');
   // }
   // else
      //  cout << "This Custmer Id Does't Exist):" << endl;

}

void Order::AddOrderItem(orderItem* item) {
    // Add the given order item to the order
    // and update the total price
    if (items == nullptr) {
        // Create a new array to store order items
        items = new orderItem * [1];
        items[0] = item;
        c_orderItem = 1;
    }
    else {
        // Create a new array with increased size
        orderItem** newItems = new orderItem * [c_orderItem + 1];

        // Copy existing items to the new array
        for (int i = 0; i < c_orderItem; i++) {
            newItems[i] = items[i];
        }

        // Add the new item to the end of the new array
        newItems[c_orderItem] = item;

        // Delete the old array
        delete[] items;

        // Update the items pointer to point to the new array
        items = newItems;

        // Increment the count of order items
        c_orderItem++;
    }

    // Update the total price
    totalPrice += item[c_orderItem].calcTotalPrice();
}

void Order::UpdateOrderStatus(ORDERSTATUS orderStatus) {
    // Update the order status based on the provided enum value
    switch (orderStatus) {
    case PENDING:
        status = "PENDING";
        break;
    case PAID:
        status = "PAID";
        break;
    case COMPLETED:
        status = "COMPLETED";
        break;
    default:
        cout << "Invalid order status!" << endl;
    }
}

void Order::EditOrder(int itemId) {
    // Find the order item with the given item ID
    int index = stk->SearchId(itemId);
    if (index != -1)
    {
        // Prompt the user to edit the order item details
        cout << "Enter new quantity: ";
        int newQuantity;
        cin >> newQuantity;

        // Supstract the old valu 
        totalPrice -= items[index]->calcTotalPrice();

        // Update the quantity of the order item
        items[index]->UpdateQuantity(newQuantity);

        // Calculate the new total price 
        totalPrice += items[index]->getTotalPrice();

        cout << "Order item updated successfully." << endl;
        return;
    }
    

    cout << "Order item not found." << endl;
}

void Order::RemoveOrderItem(int itemId) {
    // Find the order item with the given item ID
    for (int i = 0; i < c_orderItem; i++) {
        if (items[i]->getIdOrderItem() == itemId) {
            // Calculate the total price before removing the item
            int itemTotalPrice = items[i]->getTotalPrice();

            // Delete the order item from the array
            delete items[i];

            // Shift the remaining items to fill the gap
            for (int j = i; j < c_orderItem - 1; j++) {
                items[j] = items[j + 1];
            }

            // Decrement the count of order items
            c_orderItem--;

            // Calculate the new total price
            totalPrice -= itemTotalPrice;

            cout << "Order item removed successfully." << endl;
            return;
        }
    }

    cout << "Order item not found." << endl;
}


istream& operator>>(istream& in, Order& r) {
    // i won't use this overloding i will use function create order
    char ch;
    int id;
    cout << "Enter Order Id: ";
    cin >> r.OrderID;
    do
    {
        cout << "Enter Item Id: ";
        in >> id;
         //if (r.items[r.c_orderItem]->setOrderItem(id))
        {
            r.c_orderItem++;
        }

        cout << "Do You Want To Add Another Item [y/n] ";
        cin>>ch;
    } while (ch == 'y' || ch == 'Y');

    return in;
}

ostream& operator<<(ostream& out, Order& r) {

    out << "Order ID: " << r.OrderID << endl;
    out << "Number: " << r.number << endl;
    out << "Date: " << r.date << endl;
    out << "Status: " << r.status << endl;
    out << "Total Price: " << r.totalPrice << endl;
    //out << "Name of Customer: " << r.NameOfCustomer << endl;

    out << "Order Items:" << endl;
    for (int i = 0; i < r.c_orderItem; i++) {
        out << "Order Item " << i + 1 << ":" << endl;
        out << r.items[i] << endl;
    }

    return out;
}
