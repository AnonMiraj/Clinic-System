#pragma once
#include "Payment.h"
#include  <string>
class Credit : public Payment
{
    string numberCredit;
    string typeCredit;
    Date expireDate;
public:
    Credit();
    Credit(const char*, const char*);

    void set_numberCredit(const char*);
    void set_typeCredit(const char*);

    Credit& get_numberCredit() ;
    Credit& get_typeCredit() ;

    void Pay();
    void Update();
    friend istream& operator >> (istream&, Credit&);
    virtual ~Credit();

};

