#include <iostream>
#include <string>
using namespace std;

string IsValid(string msg)
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

      return num;
    }

    catch (const char *str)
    {
      cerr << "Please, don't write letter. type only numbers :)\n";
    }
  } while (IsNotValid);

  return num;
}

int IsValid(int n)
{
  bool IsNotValid = false;
  string num;

  IsNotValid = false;

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

    return n;
  }

  catch (const char *str)
  {
    cerr << "Please, don't write letter. type only numbers :)\n";
  }
}
