#ifndef OTHER_H
#define OTHER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;
bool isValid(int); 
bool IsValid(string);



void setIndexesToTrue(bool *arr, int size);
void setIndexesToTrue(bool *arr, int size, string);
void printDayNames(const bool *arr, int size, ostream& os);
void printPeriodTimes( const bool *arr, int size, ostream& os);
#endif // !OTHER_H