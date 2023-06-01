#include "Payment.h"
Payment::Payment() {
	amount     = 0.0;
	date.day   = 0;
	date.month = 0;
	date.year  = 0;
}
void Payment::Pay() {
	char ch;
	do
	{
	    cout << "Enter the amount : ";
        cin >> amount;
	} while(IsValid(amount) == -1);
	
	cout << "Enter the date : ";
	cin >> date.day >> ch >> date.month >> ch >> date.year;
}
istream& operator >> (istream& in, Payment& pa) {
	char ch;
	cout << "Enter the amount : ";
	in >> pa.amount;
	cout << "Enter the date : ";
	in >> pa.date.day >> ch >> pa.date.month >> ch >> pa.date.year;
	return in;
}
void Payment::Update() {
	cout << "----------< Menu update >----------\n";
	cout << "1)update amount.\n";
	cout << "2)update date.\n";
}
Payment::~Payment() {
	
}
