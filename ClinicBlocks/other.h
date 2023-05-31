#ifndef OTHER_H
#define OTHER_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <ctime>


using namespace std;
int IsValid(int n);
string IsValid(string word);
bool IsValid(string num, char n);

char IsValid(string msg, int small, int big);
int IsValid(int small, int big, string num);

string printDate(time_t);
string printTime(time_t);

void setIndexesToTrue(bool *arr, int size);
void setIndexesToTrue(bool *arr, int size, string);
void printDayNames(const bool *arr, int size, ostream& os);
void printPeriodTimes( const bool *arr, int size, ostream& os);
void _pause();
#endif // !OTHER_H
