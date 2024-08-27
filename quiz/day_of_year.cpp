#include <iostream>

using namespace std;

int month2offset[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int day, month, year, order = 0;
    cin >> day >> month >> year;
    year -= 543;     
    bool is_leep = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    order += month2offset[month - 1];
    if (month > 2 && is_leep)
        order++;
    order += day;
    cout << order;
    return 0;
}
