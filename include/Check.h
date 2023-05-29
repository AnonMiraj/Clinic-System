#pragma once
#include "Payment.h"
#include<string>
class Check : public Payment
{
    string nameCheck;
    string BankId;
public:
    Check();
    Check(const char*, const char*);
    void set_NameCheck(const char*);
    void set_BankIdForCheck(const char*);

    Check& get_NameCheck();
    Check& get_BankIdForCheck();

    void Pay();
    void Update();
    friend istream& operator >> (istream&, Check&);
    virtual ~Check();
};

