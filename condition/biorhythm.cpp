#include <cmath>
#include <iostream>

using namespace std;

struct date {
    int day;
    int month;
    int year;
};

bool is_leap(int year) {
    if (year % 4 != 0)
        return false;
    if (year % 100 == 0 && year % 400 != 0)
        return false;
    return true;
}

int prefix[13] = {0, 31, 61, 92, 122, 153, 184, 214, 245, 275, 306, 334, 365};

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    date birth, query;
    cin >> birth.day >> birth.month >> birth.year >> query.day >> query.month >>
        query.year;
    birth.year -= 543;
    query.year -= 543;

    // red
    int total =
        prefix[12 - birth.month] +
        (prefix[13 - birth.month] - prefix[12 - birth.month] - birth.day + 1);
    if (birth.month < 3 && is_leap(birth.year))
        total++;

    // black
    total += 365 * (query.year - birth.year - 1);

    // blue
    total += 365 - prefix[13 - query.month] + query.day - 1;
    if (query.month > 2 && is_leap(query.year))
        total++;

    cout << total << ' ';

    double numer = 6.283185306 * (double)total;
    for (int i = 23; i <= 33; i += 5)
        cout << (round(sin(numer / i) * 100.0) / 100.0) << ' ';
    return 0;
}
