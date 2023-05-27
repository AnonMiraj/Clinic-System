#include "other.h"

#include <iostream>
#include <string>
using namespace std;

bool IsValid(string msg)
{
  bool IsNotValid = false;
  string num;
  do
  {
    IsNotValid = false;

    try
    {
      cout << msg;
      cin >> num;

      for (int i = 0; i < num.size(); i++)
        if (!isdigit(num[i]))
        {
          IsNotValid = true;
          break;
        }

      if (IsNotValid)
        throw "Error";

      return true;
    }

    catch (const char *str)
    {
      cerr << "Please, don't write letter. type only from these choices :)\n";
    }
  } while (IsNotValid);

  return true;
}





