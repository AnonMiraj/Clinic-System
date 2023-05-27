#ifndef OTHER_H
#define OTHER_H

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;
inline int isValid(int n); 
inline string IsValid(string msg);



inline void setIndexesToTrue(bool *arr, int size);
inline void printDayNames(const bool *arr, int size, ostream& os);
inline void printPeriodTimes( const bool *arr, int size, ostream& os);
#endif // !OTHER_H
