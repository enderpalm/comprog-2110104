#include <iostream>

using namespace std;

int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year) {
    if (year % 4 != 0)
        return false;
    if (year % 100 == 0 && year % 400 != 0)
        return false;
    return true;
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int day, month, year;
    cin >> day >> month >> year;
    days_per_month[1] = is_leap(year - 543) ? 29 : 28;
    day += 15;
    if (day > days_per_month[month - 1]) {
        day -= days_per_month[month - 1];
        month++;
    }
    if (month > 12) {
        month -= 12;
        year++;
    }
    cout << day << '/' << month << '/' << year;
    return 0;
}
