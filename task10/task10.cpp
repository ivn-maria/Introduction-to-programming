#include <iostream>
#include <iomanip>

using namespace std;

const int YEAR = 365;
const int monthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    unsigned int system;
    cin >> system;

    if (system < 0) {
        cout << "-1";
        return 0;
    }

    unsigned int time_clock = system % 86400;

    unsigned int seconds = time_clock % 60;
    unsigned int minutes = (time_clock % 3600) / 60;
    unsigned int hours = time_clock / 3600;

    unsigned int day_clock = system / 86400;

    int years = 1970;

    while (day_clock >= YEAR) {
        day_clock -= YEAR;
        years++;
    }

    for(int i = 1970; i < years; i += 4)
        day_clock -= 1;

    int months = 0;

    while (day_clock >= monthArray[months]) {
        if(years % 4 == 0 && months == 2) day_clock -= monthArray[months] + 1;
        else day_clock -= monthArray[months];

        months++;
    }

    months += 1;

    unsigned int days = 1;

    days += day_clock;

    (days < 10) ? cout << setw(2) << setfill('0') << days : cout << days;
    cout << '.';
    (months < 10) ? cout << setw(2) << setfill('0') << months : cout << months;
    cout << '.';
    cout << years << " ";
    (hours < 10) ? cout << setw(2) << setfill('0') << hours : cout << hours;
    cout << ':';
    (minutes < 10) ? cout << setw(2) << setfill('0') << minutes : cout << minutes;
    cout << ':';
    (seconds < 10) ? cout << setw(2) << setfill('0') << seconds : cout << seconds;

    return 0;
}