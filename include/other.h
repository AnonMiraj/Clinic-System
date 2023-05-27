#include <iostream>
#include <string>
using namespace std;

bool IsValid(string num)
{
  bool IsNotValid = false;

  try
  {
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
    cerr << "Please, don't write letter. type only numbers :)\n";
  }
}

bool IsValid(int n)
{
  bool IsNotValid = false;
  string num;

  try
  {
    num = to_string(n);

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
    cerr << "Please, don't write letter. type only numbers :)\n";
  }
}
