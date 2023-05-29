#pragma once
#include "Cash.h"
#include "Credit.h"
#include "Check.h"
#include "Payment.h"
class Transaction
{
private:
    Payment**p;
    int counter;
public:
    Transaction();
    ///Payment
    void Set_Payment();
    void Handle_Pyment();
    virtual ~Transaction();
};

