#ifndef OTHER_H
#define OTHER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;
int isValid(int n); 
string IsValid(string msg);



void setIndexesToTrue(bool *arr, int size);
void printDayNames(const bool *arr, int size, ostream& os);
void printPeriodTimes( const bool *arr, int size, ostream& os);
#endif // !OTHER_H
