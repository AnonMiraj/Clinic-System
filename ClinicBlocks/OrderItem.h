#pragma once
#include "Medcin.h"
#include "Stock.h"

class orderItem
{
private:
	double sale_price;
	double totalPriceOrderItem;
	int qunatityOrderItem;
	Stock* stk;
	int idOrderItem;

public:
	orderItem();
	orderItem(Stock&);

	/// Setter
	void setTotalPrice(double total);
	bool setOrderItem( Stock* s);
	void setSalePrice(double);
	void setQuantityOfOrderItem(int);

	/// Getter
	double getTotalPrice();
	int getIdOrderItem();
	double getSalePrice();
	double getQuantityOfOrderItem();

	/// Another
	double calcTotalPrice();        /// --> To Calc Total Price and return the value in total price
	void UpdateQuantity(int newQuantity);
	void EditOrderItem();

	/// Overloding Operators
	orderItem operator++();
	orderItem operator--();
	orderItem operator+=(int quantity);
	orderItem operator-=(int quantity);
	friend ostream& operator<<(ostream&, orderItem&);

};
