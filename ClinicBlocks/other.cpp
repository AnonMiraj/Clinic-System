#include "other.h"

string IsValid(string word)
{
  bool IsNotValid = false;
    try
    {

      for (int i = 0; i < word.size(); i++)
        if (!isalpha(word[i]))
        {
          IsNotValid = true;
          break;
        }

      if (IsNotValid)
        throw "Error";

      return word;
    }

    catch (const char *str)
    {
      cerr << "Please, type only letter :)\n";
    }

  return word;
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
  return n;
}

char IsValid(string msg, int small, int big)
{
    bool IsNotValid = false; string num;
    do
    {
        IsNotValid = false;

        try
        {
            cout << msg; cin >> num;

            for (int i = 0; i < num.size(); i++)
                if (!isdigit(num[i]))
                {
                    IsNotValid = true; break;
                }

            if (IsNotValid)
                throw "Error";

            if (stoi(num)  < small || stoi(num) > big)
                throw (big);

            //return num[0];
        }

        catch (const char* str)
        {
            cerr << "Please, don't write letter. type only from these choices :)\n";
        }

        catch (int i)
        {
            cerr << "please, Enter a number from the list :)\n";
            IsNotValid = true;
        }
    } while (IsNotValid);

    return num[0];
}

int IsValid(int small, int big, string num)
{
    bool IsNotValid = false;
        try
        {

            for (int i = 0; i < num.size(); i++)
                if (!isdigit(num[i]) && (num[i]!='-' || num.size()==1) )
                {
                    IsNotValid = true; break;
                }

            if (IsNotValid)
                throw "Error";

            if (stoi(num)  < small || stoi(num) > big)
                throw (big);

        }

        catch (const char* str)
        {
            cerr << "Please, don't write letter. type only from these choices :)\n";
            return -1;
        }

        catch (int i)
        {
            cerr << "please, Enter a number from the list :)\n";
            IsNotValid = true;
            return -1;
        }
    return stoi(num);
}

string printDate(time_t timeValue)
{
    tm* timeInfo = localtime(&timeValue);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeInfo);
    return buffer;
}

string printTime(time_t timeValue)
{
    tm* timeInfo = localtime(&timeValue);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%H:%M", timeInfo);
    return buffer;
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

void printDayNames(const bool arr[], int size ) {
    const string daysOfWeek[] = {
         "","1-Saturday, ", "2-Sunday, ", "3-Monday, ", "4-Tuesday, ", "5-Wednesday, ", "6-Thursday, ", "7-Friday"
    };

    cout<<"Days : ";
    for (int i = 1; i < size; ++i) {
        if (arr[i]) {
            cout << daysOfWeek[i] << " ";
        }
    }
    cout << endl;
}

void printPeriodTimes( const bool arr[], int size) {

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
        }
        else {
            if (isInPeriod) {
                int endPeriod = i - 1;
                int startMinutes = ((startPeriod - 1) * minutesPerPeriod) % 60;
                int endMinutes = (endPeriod * minutesPerPeriod) % 60;

                int startHour = ((startPeriod - 1) * minutesPerPeriod) / 60;
                int endHour = (endPeriod * minutesPerPeriod) / 60;
                if (endHour ==24)
                  endHour=0;

                cout << setfill('0') << setw(2) << startHour << ":"
                          << setw(2) << startMinutes << " - "
                          << setw(2) << endHour << ":"
                          << setw(2) << endMinutes;
                if (i != size-1)
                    cout<<" , ";

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

        cout << setfill('0') << setw(2) << startHour << ":"
                  << setw(2) << startMinutes << " - "
                  << setw(2) << endHour << ":"
                  << setw(2) << endMinutes;
    }

    cout << endl;

}

void _pause() {
  cin.ignore();
  do {
    cout << '\n' << "Press the Enter key to continue.";
  } while (cin.get() != '\n');
}
