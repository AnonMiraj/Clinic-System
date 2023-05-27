#include "Stock.h"
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    system("Color 03");
    Stock s;
    s.addMedcinInStockByFiles();
    cout << s;
    return 0;
}

