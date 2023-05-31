#pragma once
#include<iostream>
#include<string.h>
using namespace std;
struct Date {
	int day;
	int month;
	int year;
};
class Payment
{
protected:
	double amount;
	Date date;
public:
	Payment();
	virtual void Pay();
	virtual void Update();
	friend istream& operator >> (istream&, Payment&);
	virtual ~Payment();
};

