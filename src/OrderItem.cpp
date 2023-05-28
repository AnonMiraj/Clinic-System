#include "OrderItem.h"
#include <iostream>
using namespace std;

orderItem::orderItem():idOrderItem(0), sale_price(0.0), qunatityOrderItem(0)
{

}

orderItem::orderItem(Stock& stock) : stk(&stock), idOrderItem(0), sale_price(0.0), qunatityOrderItem(0)
{
    stk = &stock;
}

//void orderItem::SetStock(Stock&s)
//{
//    stk = &s;
//}


void orderItem::setTotalPrice(double t)
{
    totalPriceOrderItem = t;
}

bool orderItem::setOrderItem(int id,Stock&s)
{
    stk = &s;
    int index= stk->SearchId(id);
   // cout << "Index: " << index;
    //system("pause");
    if (index != -1)
    {
        this->idOrderItem = id;
        int q;
        cout << "Enter Quntitiy: ";
        cin >> q;
        if (q <= stk->getQuntitiy(id))
        {
            cout << "Enter a Sale Price: ";
            cin >> sale_price;
            cout << "This Item Added Successfully \n";
            stk->setQuantity((stk->getQuntitiy(id) - q), index); //10-->4//6
            this->qunatityOrderItem = q;
            return true;
        }
        else if (q > stk->getQuntitiy(id))
        {
            cout << "This Quntitiy Doesn't Exist ): \n";
            cout << "The Valid Quntitiy Is : " << stk->getQuntitiy(idOrderItem) << endl;
            cout << "Are You Want To Make This Order Again [Y/N]";
            char ch;
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                setOrderItem(id, s);
            }
            
            return false;
        }
    }
    else
    {
        cout << "This Id Doesn't Exist ): \n";
        return false;
    }
}

double orderItem::calcTotalPrice()
{
    totalPriceOrderItem = sale_price * qunatityOrderItem;
    return totalPriceOrderItem;
}

void orderItem::UpdateQuantity(int newQuantity)
{
    int index;
    index=stk->SearchId(idOrderItem);
    //cout << "The Old Quntitiy Is: " << qunatityOrderItem << endl;
    if (stk->getQuntitiy(idOrderItem)+this->qunatityOrderItem >= newQuantity) // 10 --> 5 //--> 3 --> 7
    {
        cout << "Has been Added Successfully \n";
         stk->setQuantity((stk->getQuntitiy(idOrderItem) + this->qunatityOrderItem - newQuantity), index); //--> هجمع القديم ناقص الجديد
         this->qunatityOrderItem = newQuantity;
    }
    else
    {
        cout << "Sorry , This Quntitiy Is Not Valid ):" << endl;
        cout << "The Valid Quntitiy Is: " << stk->getQuntitiy(idOrderItem)+this->qunatityOrderItem << endl;
        cout << "Are You Want To Update Again [Y/N]";
        char ch;
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            cout << "Enter New Quntitiy Again: ";
            int q;
            cin >> q;
            UpdateQuantity(q);
        }
    }
}

double orderItem::getTotalPrice()
{
    return totalPriceOrderItem;
}

int orderItem::getIdOrderItem()
{
    return idOrderItem;
}

orderItem orderItem::operator++()
{
    int index;
    index= stk->SearchId(idOrderItem);
    if (stk->getQuntitiy(idOrderItem) >= qunatityOrderItem + 1) // 10 5 --> 5 -->
    {
        cout << "Has been Added Successfully \n";
        stk->setQuantity((stk->getQuntitiy(idOrderItem) - 1), index);
        qunatityOrderItem++;
    }
    else
    {
        cout << "Sorry , This Quntitiy Is Not Valid ):" << endl;
        cout << "The Valid Quntitiy Is: " << stk->getQuntitiy(idOrderItem) << endl;
    }
    return *this;
}

orderItem orderItem::operator--()
{

    int index;
    index = stk->SearchId(idOrderItem);
    
    stk->setQuantity((stk->getQuntitiy(idOrderItem) + 1), index);
    qunatityOrderItem--;
    
    return *this;
}

orderItem orderItem::operator+=(int quantity)
{
    int index;
    index = stk->SearchId(idOrderItem);
    //cout << "The Old Quntitiy Is: " << quantity << endl;
    if (stk->getQuntitiy(idOrderItem) >= quantity)
    {
        this->qunatityOrderItem += quantity;
        cout << "Has been Added Successfully \n";
        stk->setQuantity((stk->getQuntitiy(idOrderItem) - quantity), index);
    }
    else
    {
        cout << "Sorry , This Quntitiy Is Not Valid ):" << endl;
        cout << "The Valid Quntitiy Is: " << stk->getQuntitiy(idOrderItem) << endl;
    }
    return *this;
}

orderItem orderItem::operator-=(int quantity)
{
    int index;
    index = stk->SearchId(idOrderItem);
   // cout << "The Old Quntitiy Is: " << quantity << endl;
    
        this->qunatityOrderItem -= quantity;
        stk->setQuantity((stk->getQuntitiy(idOrderItem) + quantity), index);
        
        return *this;
}

void orderItem::setSalePrice(double price)
{
    sale_price = price;
}

double orderItem::getSalePrice()
{
    return sale_price;
}

void orderItem::setQuantityOfOrderItem(int qty)
{
    qunatityOrderItem = qty;
}

double orderItem::getQuantityOfOrderItem()
{
    return qunatityOrderItem;
}

void orderItem::EditOrderItem()
{
    int option;
    cout << "1- Edit Sale Price " << endl;
    cout << "2- Edit Quntitiy" << endl;
    cout << "Enter Your Option: ";
    cin >> option;
    if (option == 1)
    {
        cout << "The Old Sale Price Is " << sale_price << endl;
        cout << "Enter The New Sale Price: ";
        cin >> sale_price;
    }
    else if (option == 2)
    {
        int q;
        cout << "Enter New Quntitiy: ";
        cin >> q;
        UpdateQuantity(q);
    }
}

/*
void orderItem::UpdateQuantity(int newQuantity) {
    int d;

    if (>=newQuantity) {
        // زودت الكميه القديمه علشان ارجعه زي ما كام وبعد كدا طرحت الكميه القديمه 
        // وده علشان اتجنب اني اطرح الكميتين واطرح الي اتحدثت فقط
        ptrProduct->setQuntity(ptrProduct->getQuntityFromProduct()+(this->quantity)-newQuantity);
        //Update Order item quantity
        this->quantity = newQuantity;
    }
    else 
        cout << "Quantity You Enter Large Than What We have :( "<<endl;
}

// Overload ++ operator to increase the quantity of the order item by 1

orderItem orderItem::operator++() {
    if (ptrProduct->getQuntityFromProduct()>=quantity+1)
    {
        quantity++;
        ptrProduct->setQuntity(getQuantitiy() - 1);//to decrese quantity by 1 because i'am icrese order فبالتالي المخزن هيقل بمقدار 1
    }
    else //if (ptr_product->get_quantity() < m_quantity+1)
        cout << "Quantity You Enter Large Than What We have :( " << endl;

    return *this;
}

// Overload -- operator to decrease the quantity of the order item by 1

orderItem orderItem::operator--() {
    quantity--;
    ptrProduct->setQuntity(getQuantitiy() + 1);//to increse quantity by 1 because i'am decrese order فبالتالي المخزن هيزيد بمقدار 1
    return *this;
}

// Constractor to 

orderItem::orderItem(Stock&s)
{
    stk = &s;
}

void orderItem::setOrderItem(int id)
{
    int q;
    int sale;
    if (stk->checkID(id))
    {
        cout << "Enter Sale Price: ";
        cin >> sale;
        cout << "Enter Quntitiy: ";
        cin >> q;
        if (q <= stk->getQuantity(id))
        {
            idOrderItem = id;
            cout << "^_^ Quntitiy Added Successfuly ^_^ \n";
            quantity = q;
            sale_price = sale;
        }
        else
            cout << "Quntity Is Not Valid ): ";
    }
    else
        cout << "This Id Product Is Not Exist ): \n";
}

void orderItem::UpdateQuantity(int newQuantity)
{

}

// Overload += operator to increase the quantity of the order item by the given amount

orderItem orderItem::operator+=(int quantity) {

    if (stk->getQuantity(idOrderItem) >= quantity + this->quantity)
    {
        this->quantity += quantity;
        stk->setQuantity(getQuantitiy() - quantity);             //--> 
    }
    else
        cout << "Quantity You Enter Large Than What We have :( " << endl;

    return *this;
}

// Overload -= operator to decrease the quantity of the order item by the given amount

orderItem orderItem::operator-=(int quantity) {
    this->quantity -= quantity;
    ptrProduct->setQuntity(getQuantitiy() + quantity);
    return *this;
}


void orderItem::setSalePrice(double s)
{
    sale_price = s;
}
double orderItem::getSalePrice()
{
    return this->sale_price;
}

void orderItem::setQuantity(double q)
{
    this->quantity = q;
}
double orderItem::getQuantitiy()
{
    return this->quantity;
}
*/

ostream& operator<<(ostream&out, orderItem&r)
{
    out << "Id Of Item Is : " << r.idOrderItem << endl;
    out << "Sale Price Is: " << r.sale_price << endl;
    out << "Quntitiy Is: " << r.getQuantityOfOrderItem() << endl;
    return out;
}
