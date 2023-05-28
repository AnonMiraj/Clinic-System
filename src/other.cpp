#include "other.h"

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

bool IsValid(string num, char n)
{
  bool IsNotValid = false;
    IsNotValid = false;
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
    }

    catch (const char *str)
    {
      cerr << "Please, don't write letter. type only numbers :)\n";
      return false;
    }

  return true;
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
void setIndexesToTrue(bool arr[], int size) {
    string input;
    getline(cin, input);

    istringstream iss(input);
    string token;
    while (iss >> token) {
        if (token.find('-') != string::npos) {
            // Range input detected, e.g., "1-3"
            istringstream rangeIss(token);
            string start, end;
            getline(rangeIss, start, '-');
            getline(rangeIss, end, '-');

            int startIndex = stoi(start);
            int endIndex = stoi(end);

            for (int i = startIndex; i <= endIndex; ++i) {
                if (i >= 0 && i < size) {
                    arr[i] = true;
                }
            }
        } else {
            // Single index input detected, e.g., "1"
            int index = stoi(token);
            if (index >= 0 && index < size) {
                arr[index] = true;
            }
        }
    }
}
void setIndexesToTrue(bool arr[], int size,string input) {

    istringstream iss(input);
    string token;
    while (iss >> token) {
        if (token.find('-') != string::npos) {
            // Range input detected, e.g., "1-3"
            istringstream rangeIss(token);
            string start, end;
            getline(rangeIss, start, '-');
            getline(rangeIss, end, '-');

            int startIndex = stoi(start);
            int endIndex = stoi(end);

            for (int i = startIndex; i <= endIndex; ++i) {
                if (i >= 0 && i < size) {
                    arr[i] = true;
                }
            }
        } else {
            // Single index input detected, e.g., "1"
            int index = stoi(token);
            if (index >= 0 && index < size) {
                arr[index] = true;
            }
        }
    }
}

void printDayNames(const bool arr[], int size, ostream& os ) {
    const string daysOfWeek[] = {
         "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"
    };

    for (int i = 1; i < size; ++i) {
        if (arr[i]) {
            cout << daysOfWeek[i-1] << " ";
        }
    }
    os << endl;
}
void printPeriodTimes( const bool arr[], int size, ostream& os) {
 
    const int minutesPerPeriod = 30;

    cout << "Periods: ";
    int startPeriod = -1;
    bool isInPeriod = false;
    for (int i = 0; i < size; ++i) {
        if (arr[i]) {
            if (!isInPeriod) {
                startPeriod = i;
                isInPeriod = true;
            }
        } else {
            if (isInPeriod) {
                int endPeriod = i - 1;
                int startMinutes = ((startPeriod - 1) * minutesPerPeriod) % 60;
                int endMinutes = (endPeriod * minutesPerPeriod) % 60;

                int startHour = ((startPeriod - 1) * minutesPerPeriod) / 60;
                int endHour = (endPeriod * minutesPerPeriod) / 60;
                if (endHour ==24)
                  endHour=0;

                os << setfill('0') << setw(2) << startHour << ":"
                          << setw(2) << startMinutes << " - "
                          << setw(2) << endHour << ":"
                          << setw(2) << endMinutes << " ";

                isInPeriod = false;
            }
        }
    }

    if (isInPeriod) {
        int endPeriod = size - 1;
        int startMinutes = ((startPeriod - 1) * minutesPerPeriod) % 60;
        int endMinutes = (endPeriod * minutesPerPeriod) % 60;

        int startHour = ((startPeriod - 1) * minutesPerPeriod) / 60;
        int endHour = (endPeriod * minutesPerPeriod) / 60;
        if (endHour ==24)
          endHour=0;

        os << setfill('0') << setw(2) << startHour << ":"
                  << setw(2) << startMinutes << " - "
                  << setw(2) << endHour << ":"
                  << setw(2) << endMinutes << " ";
    }

    os << endl;

}
void _pause() {
  cin.ignore();
  do {
    cout << '\n' << "Press the Enter key to continue.";
  } while (cin.get() != '\n');
}
