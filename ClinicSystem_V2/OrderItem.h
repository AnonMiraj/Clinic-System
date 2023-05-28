#pragma once
#include "Medcin.h"
#include "Stock.h"
class orderItem
{
private:
	double sale_price;
	int qunatityOrderItem;
	Stock* stk;
	int idOrderItem;

public:
	orderItem();
	orderItem(Stock&);

	void setOrderItem(int id, Stock& s);
	void UpdateQuantity(int newQuantity);
	int getIdOrderItem();
	void setSalePrice(double);
	double getSalePrice();
	void setQuantityOfOrderItem(int);
	double getQuantityOfOrderItem();
	void EditOrderItem();
	orderItem operator++();
	orderItem operator--();
	orderItem operator+=(int quantity);
	orderItem operator-=(int quantity);
	friend ostream& operator<<(ostream&, orderItem&);

};
