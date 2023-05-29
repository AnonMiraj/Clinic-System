#pragma once
#include "Payment.h"
class Cash : public Payment
{
    double CashValue;
public:
    Cash();
    Cash(double);

    void Set_Cash(double);
    Cash& Get_Cash() ;

    void Pay();
    void Update();
    friend istream& operator >> (istream&, Cash&);

    virtual ~Cash();
};

